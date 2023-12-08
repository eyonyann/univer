import requests
import sqlite3
from sqlite3 import Connection, Cursor
from telegram import ReplyKeyboardMarkup, ReplyKeyboardRemove
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters, ConversationHandler
from apscheduler.schedulers.background import BackgroundScheduler
from apscheduler.triggers.cron import CronTrigger
import pytz  # Add this import
from tokens import TOKEN, OWM_API_KEY

conn: Connection = sqlite3.connect('subscriptions.db', check_same_thread=False)
cursor: Cursor = conn.cursor()
cursor.execute('''
    CREATE TABLE IF NOT EXISTS subscriptions (
        user_id INTEGER PRIMARY KEY,
        is_confirmed INTEGER DEFAULT 0
    )
''')
conn.commit()
# Состояния конечного автомата
START, SUBSCRIBE, UNSUBSCRIBE, CITY_WEATHER = range(4)

# Клавиатура с кнопками
keyboard = [['Погода'], ['Подписаться', 'Отписаться' ]]
markup = ReplyKeyboardMarkup(keyboard, one_time_keyboard=True)

scheduler = BackgroundScheduler()
scheduler.start()

# Словарь для хранения подписанных пользователей
subscribed_users = set()

def start(update, context):
    user_id = update.message.from_user.id
    context.user_data['user_id'] = user_id

    # Check if the user exists in the database
    cursor.execute('SELECT * FROM subscriptions WHERE user_id = ?', (user_id,))
    existing_user = cursor.fetchone()

    if not existing_user:
        # Insert the user into the subscriptions table with is_confirmed set to False
        cursor.execute('INSERT INTO subscriptions (user_id, is_confirmed) VALUES (?, 0)', (user_id,))
        conn.commit()

    update.message.reply_text(
        f"Привет! Я бот для получения погоды. Выбери одну из команд:\n"
        "1. Погода (текущая погода в Минске)\n"
        "2. Подписаться (получать погоду в 7:00 каждый день)\n"
        "3. Отписаться (отменить подписку)",
        reply_markup=markup
    )
    return START

# Обработка команды /subscribe
def subscribe(update, context):
    user_id = context.user_data['user_id']

    # Check if the user is already subscribed
    cursor.execute('SELECT * FROM subscriptions WHERE user_id = ?', (user_id,))
    existing_user = cursor.fetchone()

    if not existing_user:
        # Insert the user into the subscriptions table with is_confirmed set to True
        cursor.execute('INSERT INTO subscriptions (user_id, is_confirmed) VALUES (?, 1)', (user_id,))
        conn.commit()
        update.message.reply_text("Ты подписан на рассылку. Будешь получать погоду в 7:00 каждый день.")
    else:
        if existing_user[1] == 1:
            update.message.reply_text("Ты уже подписан на рассылку.")
        else:
            # Update the user's subscription status to True
            cursor.execute('UPDATE subscriptions SET is_confirmed = 1 WHERE user_id = ?', (user_id,))
            conn.commit()
            update.message.reply_text("Ты подписан на рассылку. Будешь получать погоду в 7:00 каждый день.")

    return START
# Обработка команды /unsubscribe
def unsubscribe(update, context):
    user_id = context.user_data['user_id']

    # Check if the user is subscribed
    cursor.execute('SELECT * FROM subscriptions WHERE user_id = ?', (user_id,))
    existing_user = cursor.fetchone()

    if existing_user:
        if existing_user[1] == 1:
            # Update the user's subscription status to False
            cursor.execute('UPDATE subscriptions SET is_confirmed = 0 WHERE user_id = ?', (user_id,))
            conn.commit()
            update.message.reply_text("Ты отписан от рассылки. Больше не будешь получать погоду в 7:00.")
        else:
            update.message.reply_text("Ты не подписан на рассылку.")
    else:
        update.message.reply_text("Ты не подписан на рассылку.")

    return START

# Обработка команды /weather
def weather(update, context):
    user_input = update.message.text.lower()
    if 'погода' in user_input:
        city = 'Минск'
        weather_info = get_weather(city)
        update.message.reply_text(f"Текущая погода в {city}:\n{weather_info}")
    return START

def get_daily_weather(city):
    base_url = "http://api.openweathermap.org/data/2.5/forecast"
    params = {
        'q': city,
        'appid': OWM_API_KEY,
        'units': 'metric'
    }
    response = requests.get(base_url, params=params)
    data = response.json()

    if response.status_code == 200:
        # Extract relevant information for the current, daytime, and evening conditions
        current_weather = data['list'][0]
        current_temperature = current_weather['main']['temp']
        current_description = current_weather['weather'][0]['description']
        current_wind_speed = current_weather['wind']['speed']
        current_wind_direction = get_wind_direction(current_weather['wind']['deg'])
        current_precipitation = get_precipitation_description(current_weather)

        daytime_weather = data['list'][4]
        daytime_temperature = daytime_weather['main']['temp']
        daytime_description = daytime_weather['weather'][0]['description']
        daytime_wind_speed = daytime_weather['wind']['speed']
        daytime_wind_direction = get_wind_direction(daytime_weather['wind']['deg'])
        daytime_precipitation = get_precipitation_description(daytime_weather)

        evening_weather = data['list'][8]
        evening_temperature = evening_weather['main']['temp']
        evening_description = evening_weather['weather'][0]['description']
        evening_wind_speed = evening_weather['wind']['speed']
        evening_wind_direction = get_wind_direction(evening_weather['wind']['deg'])
        evening_precipitation = get_precipitation_description(evening_weather)

        return (
            f"Сейчас: {current_temperature}°C, {current_description}\n"
            f"Ветер: {current_wind_speed} м/с, {current_wind_direction}\n"
            f"Осадки: {current_precipitation}\n\n"
            f"Днем: {daytime_temperature}°C, {daytime_description}\n"
            f"Ветер: {daytime_wind_speed} м/с, {daytime_wind_direction}\n"
            f"Осадки: {daytime_precipitation}\n\n"
            f"Вечером: {evening_temperature}°C, {evening_description}\n"
            f"Ветер: {evening_wind_speed} м/с, {evening_wind_direction}\n"
            f"Осадки: {evening_precipitation}"
        )
    else:
        return "Не удалось получить информацию о погоде."
    
def get_precipitation_description(weather_data):
    # Get precipitation information
    precipitation = weather_data.get('rain', {}).get('3h', 0) + weather_data.get('snow', {}).get('3h', 0)
    
    # Determine precipitation description
    if precipitation > 5:
        return "сильные осадки"
    elif precipitation > 0:
        return "легкие осадки"
    else:
        return "без осадков"
    
def get_weather(city):
    base_url = "http://api.openweathermap.org/data/2.5/weather"
    params = {
        'q': city,
        'appid': OWM_API_KEY,
        'units': 'metric'
    }
    response = requests.get(base_url, params=params)
    data = response.json()
    if response.status_code == 200:
        temperature = data['main']['temp']
        description = data['weather'][0]['description']
        wind_speed = data['wind']['speed']

        # Check if 'rain' or 'snow' key is present in the API response
        precipitation_description  = get_precipitation_description(data)
        precipitation = data.get('rain', {}).get('1h', 0) + data.get('snow', {}).get('1h', 0)
        # Get wind direction
        wind_direction = get_wind_direction(data['wind']['deg'])

        return f"Температура: {temperature}°C\nСостояние: {description}\nВетер: {wind_speed} м/с, {wind_direction}\nОсадки: {precipitation_description}({precipitation} мм)"
    else:
        return "Не удалось получить информацию о погоде."

# Function to get wind direction based on degrees
def get_wind_direction(degrees):
    if 337.5 <= degrees <= 360 or 0 <= degrees < 22.5:
        return "северный"
    elif 22.5 <= degrees < 67.5:
        return "северо-восточный"
    elif 67.5 <= degrees < 112.5:
        return "восточный"
    elif 112.5 <= degrees < 157.5:
        return "юго-восточный"
    elif 157.5 <= degrees < 202.5:
        return "южный"
    elif 202.5 <= degrees < 247.5:
        return "юго-западный"
    elif 247.5 <= degrees < 292.5:
        return "западный"
    elif 292.5 <= degrees < 337.5:
        return "северо-западный"
    else:
        return "неопределенное направление"
# Обработка неизвестных команд
def unknown(update, context):
    update.message.reply_text("Извини, не понимаю эту команду. Пожалуйста, выбери из предложенных вариантов.")

# Обработка входящих сообщений
def handle_messages(update, context):
    user_input = update.message.text.lower()
    if 'погода' in user_input and 'подписаться' not in user_input and 'отписаться' not in user_input:
        city = user_input.split()[-1]
        weather_info = get_weather(city)
        update.message.reply_text(f"Текущая погода в {city}:\n{weather_info}")
    return START

# Функция для отправки погоды подписанным пользователям
def send_daily_weather(updater):
    cursor.execute('SELECT user_id FROM subscriptions WHERE is_confirmed = 1')
    subscribed_users = {row[0] for row in cursor.fetchall()}

    for user_id in subscribed_users:
        city = 'Минск'
        weather_info = get_daily_weather(city)  # Fetch the daily weather forecast for the specified city
        updater.bot.send_message(user_id, f"Доброе утро, пупсик! \nВот твоя ежедневная погода в {city}:\n\n" + weather_info)


timezone = pytz.timezone('Europe/Moscow')


def main(updater):
    updater = Updater(token=TOKEN, use_context=True)
    dp = updater.dispatcher

    conv_handler = ConversationHandler(
        entry_points=[CommandHandler('start', start)],
        states={
            START: [
                MessageHandler(Filters.regex('^(Погода)$'), weather),
                MessageHandler(Filters.regex('^(Подписаться)$'), subscribe),
                MessageHandler(Filters.regex('^(Отписаться)$'), unsubscribe),
                MessageHandler(Filters.regex('^(.+)'), handle_messages),
            ],
        },
        fallbacks=[CommandHandler('start', start)],
    )

    

    dp.add_handler(conv_handler)
    dp.add_handler(MessageHandler(Filters.command, unknown))

    # Отправка ежедневной погоды в 7:00
    scheduler.add_job(send_daily_weather, CronTrigger(hour=7, minute=0, day_of_week='0-6', timezone=timezone),
                      args=[updater])

    updater.start_polling()
    updater.idle()
    conn.close()

if __name__ == '__main__':
    updater = Updater(token=TOKEN, use_context=True)
    main(updater)

