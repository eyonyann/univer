def get_positive_integer_input(prompt):
    while True:
        try:
            value = int(input(prompt))
            if value > 0:
                return value
            else:
                print("Пожалуйста, введите положительное целое число.")
        except ValueError:
            print("Неправильный ввод. Пожалуйста, введите целое число.")


def get_bouquet_choice():
    while True:
        bouquet = input("Выберите букет для покупки (или 'n' для выхода): ")
        if bouquet.lower() == 'n':
            return None
        elif bouquet in flower_shop:
            return bouquet
        else:
            print("Извините, такого букета нет в магазине.")


flower_shop = {
    "Розы": {"описание": "Красные розы", "цена": 100, "количество": 50},
    "Гвоздики": {"описание": "Белые гвоздики", "цена": 50, "количество": 30},
    "Лилии": {"описание": "Оранжевые лилии", "цена": 80, "количество": 40},
}


def display_description():
    for bouquet, info in flower_shop.items():
        print(f"{bouquet}: {info['описание']}")


def display_prices():
    for bouquet, info in flower_shop.items():
        print(f"{bouquet}: {info['цена']} руб.")


def display_quantities():
    for bouquet, info in flower_shop.items():
        print(f"{bouquet}: {info['количество']} шт.")


def display_all_info():
    for bouquet, info in flower_shop.items():
        print(f"{bouquet}:")
        print(f"  Описание: {info['описание']}")
        print(f"  Цена: {info['цена']} руб.")
        print(f"  Количество: {info['количество']} шт.")


def purchase():
    total_cost = 0
    while True:
        bouquet = get_bouquet_choice()
        if bouquet is None:
            break
        quantity = get_positive_integer_input(f"Сколько штук '{bouquet}' вы хотите купить? ")
        if quantity <= flower_shop[bouquet]["количество"]:
            cost = flower_shop[bouquet]["цена"] * quantity
            total_cost += cost
            flower_shop[bouquet]["количество"] -= quantity
            print(f"Вы добавили {quantity} штук '{bouquet}' в корзину.")
            print(f"Общая стоимость: {total_cost} руб.")
        else:
            print(f"Извините, в магазине нет такого количества '{bouquet}'.")



print("Добро пожаловать в Цветочный магазин!")

while True:
    print("\nМеню:")
    print("1. Просмотр описания")
    print("2. Просмотр цен")
    print("3. Просмотр количества")
    print("4. Вся информация")
    print("5. Покупка")
    print("6. До свидания")

    choice = input("Выберите пункт меню: ")

    if choice == "1":
        display_description()
    elif choice == "2":
        display_prices()
    elif choice == "3":
        display_quantities()
    elif choice == "4":
        display_all_info()
    elif choice == "5":
        purchase()
    elif choice == "6":
        print("Спасибо за покупки! До свидания.")
        break
    else:
        print("Неправильный выбор. Пожалуйста, выберите пункт из меню.")