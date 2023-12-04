import requests
import sqlite3
from sqlite3 import Connection, Cursor
from datetime import time
from telegram import ReplyKeyboardMarkup, ReplyKeyboardRemove
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters, ConversationHandler, CallbackQueryHandler
from apscheduler.schedulers.background import BackgroundScheduler
from apscheduler.triggers.cron import CronTrigger
import pytz  # Add this import

# Установите свой токен бота
TOKEN = '5754400625:AAFKuYz4WRvfPmVjz8FLIbAxUymiC_WG3FE'
# Установите свой токен для OpenWeatherMap API
OWM_API_KEY = '79e3e3916ce4df3cb56a0edfb7d89c8e'

conn: Connection = sqlite3.connect('subscriptions.db', check_same_thread=False)
cursor: Cursor = conn.cursor()
cursor.execute('''
    CREATE TABLE IF NOT EXISTS subscriptions (
        user_id INTEGER PRIMARY KEY,
        hour INTEGER,
        minute INTEGER
    )
''')

# Состояния конечного автомата
START, SUBSCRIBE, UNSUBSCRIBE, CITY_WEATHER = range(4)

# Клавиатура с кнопками
keyboard = [['Погода', 'Подписаться'], ['Отписаться']]
markup = ReplyKeyboardMarkup(keyboard, one_time_keyboard=True)

scheduler = BackgroundScheduler()
scheduler.start()

# Словарь для хранения подписанных пользователей
subscribed_users = set()

# Обработка команды /start
def start(update, context):
    user_id = update.message.from_user.id
    context.user_data['user_id'] = user_id
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
        # Ask the user to enter the time for daily updates
        update.message.reply_text("Ты подписан на рассылку. В какое время ты хочешь получать погоду (в формате HH:MM)?")
        return SUBSCRIBE
    else:
        update.message.reply_text("Ты уже подписан на рассылку. Если хочешь изменить время, используй /unsubscribe и затем /subscribe.")
        return START

def subscribe_time(update, context):
    user_id = context.user_data['user_id']
    time_input = update.message.text.strip()

    try:
        # Parse the user input to get hours and minutes
        hour, minute = map(int, time_input.split(':'))

        # Insert the user into the subscriptions table with the specified time
        cursor.execute('INSERT INTO subscriptions (user_id, hour, minute) VALUES (?, ?, ?)', (user_id, hour, minute))
        conn.commit()

        update.message.reply_text(f"Ты подписан на рассылку. Будешь получать погоду в {hour:02d}:{minute:02d} каждый день.")

        # Remove the job if it exists
        job_id = f'send_daily_weather_{user_id}'
        if job_id in [job.id for job in scheduler.get_jobs()]:
            scheduler.remove_job(job_id)

        # Add a new job for this user with the specified time
        scheduler.add_job(send_daily_weather, CronTrigger(hour=hour, minute=minute, day_of_week='0-6', timezone=timezone),
                          args=[updater, user_id])

    except ValueError:
        update.message.reply_text("Некорректный формат времени. Введи время в формате HH:MM.")

    return START

def send_daily_weather(updater, user_id):
    updater.bot.send_message(user_id, "Доброе утро! Вот твоя ежедневная погода в Минске:\n" + get_weather("Minsk"))

# Обработка команды /unsubscribe
def unsubscribe(update, context):
    user_id = context.user_data['user_id']

    # Check if the user is subscribed
    cursor.execute('SELECT * FROM subscriptions WHERE user_id = ?', (user_id,))
    existing_user = cursor.fetchone()

    if existing_user:
        # Remove the user from the subscriptions table
        cursor.execute('DELETE FROM subscriptions WHERE user_id = ?', (user_id,))
        conn.commit()
        update.message.reply_text("Ты отписан от рассылки. Больше не будешь получать погоду в 7:00.")
    else:
        update.message.reply_text("Ты не подписан на рассылку.")

    return START
# Обработка команды /weather
def weather(update, context):
    user_input = update.message.text.lower()
    if 'погода' in user_input:
        city = 'Minsk'
        weather_info = get_weather(city)
        update.message.reply_text(f"Текущая погода в {city}:\n{weather_info}")
    return START

# Получение погоды через OpenWeatherMap API
# Получение погоды через OpenWeatherMap API
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
        precipitation = data.get('rain', {}).get('1h', 0) + data.get('snow', {}).get('1h', 0)

        # Get wind direction
        wind_direction = get_wind_direction(data['wind']['deg'])

        return f"Температура: {temperature}°C\nСостояние: {description}\nСкорость ветра: {wind_speed} м/с\nОсадки: {precipitation} мм\nНаправление ветра: {wind_direction}"
    else:
        return "Не удалось получить информацию о погоде."

# Function to get wind direction based on degrees
def get_wind_direction(degrees):
    if 337.5 <= degrees <= 360 or 0 <= degrees < 22.5:
        return "Северный"
    elif 22.5 <= degrees < 67.5:
        return "Северо-восточный"
    elif 67.5 <= degrees < 112.5:
        return "Восточный"
    elif 112.5 <= degrees < 157.5:
        return "Юго-восточный"
    elif 157.5 <= degrees < 202.5:
        return "Южный"
    elif 202.5 <= degrees < 247.5:
        return "Юго-западный"
    elif 247.5 <= degrees < 292.5:
        return "Западный"
    elif 292.5 <= degrees < 337.5:
        return "Северо-западный"
    else:
        return "Неопределенное направление"
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
    cursor.execute('SELECT user_id FROM subscriptions')
    subscribed_users = {row[0] for row in cursor.fetchall()}

    for user_id in subscribed_users:
        updater.bot.send_message(user_id, "Доброе утро! Вот твоя ежедневная погода в Минске:\n" + get_weather("Minsk"))

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
            SUBSCRIBE: [MessageHandler(Filters.text, subscribe_time)],
        },
        fallbacks=[CommandHandler('start', start)],
    )


    dp.add_handler(conv_handler)
    dp.add_handler(MessageHandler(Filters.command, unknown))

    updater.start_polling()
    updater.idle()

if __name__ == '__main__':
    updater = Updater(token=TOKEN, use_context=True)
    main(updater)
    updater.start_polling()
    updater.idle()
    conn.close()