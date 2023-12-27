#include "Events.h"
#include "Gifts.h"
#include "CinemaFood.h"
#include "MerchandiseUnit.h"


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<ConceptualRoom*> rooms;
    vector<Event*> events;
    vector<gift::Event*> eventsGifts;
    vector<Food*> foodItems;
    vector<MerchandiseUnit*> merchandiseUnits;

    StandUP::Register(); // id 0
    Lecture::Register(); // id 1
    Meeting::Register(); // 2
    LiveBroadcast::Register(); // 3
    TheatricalProduction::Register(); // 4

    while (true) {

        bool subMenu = false;
        char menuKey;

        cout << "Меню:" << endl
            << "1. Концептуальные залы." << endl
            << "2. Атрибутика." << endl
            << "3. Мероприятия." << endl
            << "4. Мероприятия с подарками." << endl
            << "5. еда" << endl
            << "ваш выбор: ";
        cin >> menuKey;
        cin.ignore();

        switch (menuKey)
        {
        case '0':
        {
            for (ConceptualRoom* room : rooms) {
                delete room;
            }
            for (Event* event : events) {
                delete event;
            }
            for (gift::Event* event : eventsGifts) {
                delete event;
            }
            for (Food* foodItem : foodItems) {
                delete foodItem;
            }
            for (MerchandiseUnit* unit : merchandiseUnits) {
                delete unit;
            }
            return 0;
        }
        case '1':
        {
            while (!subMenu) {
                char subMenuKey;
                cout << "Выберите тип концептуального зала, который хотите создать: " << endl
                    << "1. VR-комната" << endl
                    << "2. Детская комната" << endl
                    << "3. VIP-комната" << endl
                    << "4. Комната с кроватями" << endl
                    << "5. Комната с диванами" << endl
                    << "6. Пустая комната" << endl
                    << "7. вывести содержимое на экран" << endl
                    << "0. Выход" << endl
                    << "ваш выбор: ";

                cin >> subMenuKey;
                cin.ignore();

                ConceptualRooms roomType = null;
                switch (subMenuKey)
                {
                case '0': subMenu = true; break;
                case '1':
                    roomType = VR_ROOM;
                    break;
                case '2':
                    roomType = KIDS_ROOM;
                    break;
                case '3':
                    roomType = VIP_ROOM;
                    break;
                case '4':
                    roomType = BEDS_ROOM;
                    break;
                case '5':
                    roomType = COUCHES_ROOM;
                    break;
                case '6':
                    roomType = EMPTY_ROOM;
                case '7':
                    cout << "Список созданных концептуальных залов:" << endl;
                    for (const auto& room : rooms) {
                        room->describe();
                    }
                    break;
                default:
                    cout << "Неправильный ввод." << endl;
                    continue;
                }

                ConceptualRoom* room = createRoom(roomType);
                if (room) {
                    cout << "Комната была создана!" << endl;
                    rooms.push_back(room);
                }
            }
            break;
        }
        case '2':
        {
            while (!subMenu) {
                char subMenuKey;
                cout << "Выберите тип товара, который хотите создать:" << endl
                    << "1. Логотипная кружка." << endl
                    << "2. Плакат к фильму." << endl
                    << "3. Брендированная подушка." << endl
                    << "4. Коллекционная игрушка." << endl
                    << "5. Брендированный брелок." << endl
                    << "6. вывести созданные предметы" << endl
                    << "0. Вернуться в предыдущее меню." << endl
                    << "Ваш выбор: ";

                cin >> subMenuKey;
                cin.ignore();
                MerchandiseUnitSpec* unitSpec = nullptr;
                switch (subMenuKey) {
                case '0': subMenu = true;
                    break;
                case '1': {
                    int mugSize;
                    bool isThermal;
                    cout << "Введите размер кружки (мл): ";
                    cin >> mugSize;
                    cout << "Термокружка? (1 - Да, 0 - Нет): ";
                    cin >> isThermal;
                    unitSpec = new LogoMugSpec(mugSize, isThermal);
                    break;
                }
                case '2': {
                    string movieTitle;
                    int posterSize;
                    cout << "Введите заголовок фильма: ";
                    cin.ignore();
                    getline(cin, movieTitle);
                    cout << "Введите размер плаката (см): ";
                    cin >> posterSize;
                    unitSpec = new MoviePosterSpec(movieTitle, posterSize);
                    break;
                }
                case '3': {
                    string pillowColor;
                    bool hasLogo;
                    cout << "Введите цвет подушки: ";
                    cin.ignore();
                    getline(cin, pillowColor);
                    cout << "Присутствие логотипа? (1 - Да, 0 - Нет): ";
                    cin >> hasLogo;
                    unitSpec = new BrandedPillowSpec(pillowColor, hasLogo);
                    break;
                }
                case '4': {
                    string characterName;
                    int toyHeight;
                    cout << "Введите имя персонажа: ";
                    cin.ignore();
                    getline(cin, characterName);
                    cout << "Введите высоту игрушки (см): ";
                    cin >> toyHeight;
                    unitSpec = new CollectibleToySpec(characterName, toyHeight);
                    break;
                }
                case '5': {
                    string material;
                    bool hasLight;
                    cout << "Введите материал брелка: ";
                    cin.ignore();
                    getline(cin, material);
                    cout << "Наличие подсветки? (1 - Да, 0 - Нет): ";
                    cin >> hasLight;
                    unitSpec = new BrandedKeyringSpec(material, hasLight);
                    break;
                }
                case'6':
                    cout << "Список созданных единиц атрибутики:" << endl;
                    for (const auto& unit : merchandiseUnits) {
                        unit->describe();
                    }
                    break;
                default:
                    cout << "Неправильный ввод." << endl;
                    break;
                }

                if (unitSpec) {
                    MerchandiseUnit* unit = createMerchandiseUnitWithSpec(unitSpec);
                    if (unit) {
                        merchandiseUnits.push_back(unit);
                        cout << "Товар создан." << endl;
                    }
                    delete unitSpec;
                }
            }
            break;
        }
        case '3':
        {
            while (!subMenu) {
                int eventType;
                cout << "Выберите тип мероприятия:" << endl
                    << "1. Стендап-концерт" << endl
                    << "2. Лекция" << endl
                    << "3. Встреча со звездой" << endl
                    << "4. Прямая трансляция" << endl
                    << "5. Театральная постановка" << endl
                    << "6. вывести созданные мероприятия" << endl
                    << "0. Вернуться в предыдущее меню" << endl
                    << "Ваш выбор: ";
                cin >> eventType;
                cin.ignore();

                if (eventType >= 0 && eventType < eventRegistry.size()) {
                    Event* newEvent = Event::createEvent(eventType - 1);
                    events.push_back(newEvent);
                    cout << "Создано новое мероприятие." << endl;
                }
                else if (eventType == 0) {
                    subMenu = true;
                }
                else if (eventType == 6) {
                    cout << "Список созданных мероприятий:" << endl;
                    for (const auto& unit : events) {
                        unit->describe();
                    }
                }
                else {
                    cout << "Некорректный выбор." << endl;
                }
            }
            break;
        }
        case '4':
        {
            while (!subMenu) {
                cout << "Меню:" << endl
                    << "1. StandUP" << endl
                    << "2. Lecture" << endl
                    << "3. Meeting" << endl
                    << "4. LiveBroadcast" << endl
                    << "5. TheatricalProduction" << endl
                    << "6. вывести список сформированных подарков" << endl
                    << "0. Выход" << endl
                    << "Выберите мероприятие для создания (введите номер): ";

                int choice;
                cin >> choice;

                switch (choice) {
                case 1: {
                    gift::Event* standUp = new gift::StandUP;
                    eventsGifts.push_back(standUp);
                    cout << "Создан StandUP мероприятие." << endl;
                    gift::Gift* gift = standUp->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 2: {
                    gift::Event* lecture = new gift::Lecture;
                    eventsGifts.push_back(lecture);
                    cout << "Создано мероприятие Лекция." << endl;
                    gift::Gift* gift = lecture->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 3: {
                    gift::Event* meeting = new gift::Meeting;
                    eventsGifts.push_back(meeting);
                    cout << "Создано мероприятие Встреча." << endl;
                    gift::Gift* gift = meeting->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 4: {
                    gift::Event* liveBroadcast = new gift::LiveBroadcast;
                    eventsGifts.push_back(liveBroadcast);
                    cout << "Создано мероприятие Прямая трансляция." << endl;
                    gift::Gift* gift = liveBroadcast->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 5: {
                    gift::Event* theatricalProduction = new gift::TheatricalProduction;
                    eventsGifts.push_back(theatricalProduction);
                    cout << "Создано мероприятие Театральная постановка." << endl;
                    gift::Gift* gift = theatricalProduction->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 6:
                    cout << "Список созданных подарков за посещение мероприятий:" << endl;
                    for (const auto& unit : eventsGifts) {
                        unit->describe();
                    }
                    break;
                case 0: {
                    subMenu = true;
                }
                }
            }
            break;
        }
        case '5':
        {
            while (!subMenu) {
                cout << "Menu:" << endl
                    << "1. попкорн" << endl
                    << "2. напиток" << endl
                    << "3. хотдог" << endl
                    << "4. мороженое" << endl
                    << "0. выйти из программы" << endl
                    << "ваш выбор: ";

                int choice;
                cin >> choice;

                if (choice == 0) {
                    subMenu = true;
                    break;
                }

                Food* foodItem = nullptr;

                switch (choice) {
                case 1:
                    foodItem = new Popcorn;
                    break;
                case 2:
                    foodItem = new Soda;
                    break;
                case 3:
                    foodItem = new HotDog;
                    break;
                case 4:
                    foodItem = new IceCream;
                    break;
                default:
                    cout << "неверный выбор." << endl;
                    continue;
                }

                foodItems.push_back(foodItem);

                cout << "объект был создан." << endl;
            }

            for (const auto& foodItem : foodItems) {
                Food* copy = foodItem->clone();
                copy->sell();
                delete copy;
            }
            break;
        }
        default: cout << "проверьте правильность ввода." << endl;
            break;
        }
    }
}