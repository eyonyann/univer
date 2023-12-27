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

        cout << "����:" << endl
            << "1. �������������� ����." << endl
            << "2. ����������." << endl
            << "3. �����������." << endl
            << "4. ����������� � ���������." << endl
            << "5. ���" << endl
            << "��� �����: ";
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
                cout << "�������� ��� ��������������� ����, ������� ������ �������: " << endl
                    << "1. VR-�������" << endl
                    << "2. ������� �������" << endl
                    << "3. VIP-�������" << endl
                    << "4. ������� � ���������" << endl
                    << "5. ������� � ��������" << endl
                    << "6. ������ �������" << endl
                    << "7. ������� ���������� �� �����" << endl
                    << "0. �����" << endl
                    << "��� �����: ";

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
                    cout << "������ ��������� �������������� �����:" << endl;
                    for (const auto& room : rooms) {
                        room->describe();
                    }
                    break;
                default:
                    cout << "������������ ����." << endl;
                    continue;
                }

                ConceptualRoom* room = createRoom(roomType);
                if (room) {
                    cout << "������� ���� �������!" << endl;
                    rooms.push_back(room);
                }
            }
            break;
        }
        case '2':
        {
            while (!subMenu) {
                char subMenuKey;
                cout << "�������� ��� ������, ������� ������ �������:" << endl
                    << "1. ���������� ������." << endl
                    << "2. ������ � ������." << endl
                    << "3. �������������� �������." << endl
                    << "4. ������������� �������." << endl
                    << "5. �������������� ������." << endl
                    << "6. ������� ��������� ��������" << endl
                    << "0. ��������� � ���������� ����." << endl
                    << "��� �����: ";

                cin >> subMenuKey;
                cin.ignore();
                MerchandiseUnitSpec* unitSpec = nullptr;
                switch (subMenuKey) {
                case '0': subMenu = true;
                    break;
                case '1': {
                    int mugSize;
                    bool isThermal;
                    cout << "������� ������ ������ (��): ";
                    cin >> mugSize;
                    cout << "�����������? (1 - ��, 0 - ���): ";
                    cin >> isThermal;
                    unitSpec = new LogoMugSpec(mugSize, isThermal);
                    break;
                }
                case '2': {
                    string movieTitle;
                    int posterSize;
                    cout << "������� ��������� ������: ";
                    cin.ignore();
                    getline(cin, movieTitle);
                    cout << "������� ������ ������� (��): ";
                    cin >> posterSize;
                    unitSpec = new MoviePosterSpec(movieTitle, posterSize);
                    break;
                }
                case '3': {
                    string pillowColor;
                    bool hasLogo;
                    cout << "������� ���� �������: ";
                    cin.ignore();
                    getline(cin, pillowColor);
                    cout << "����������� ��������? (1 - ��, 0 - ���): ";
                    cin >> hasLogo;
                    unitSpec = new BrandedPillowSpec(pillowColor, hasLogo);
                    break;
                }
                case '4': {
                    string characterName;
                    int toyHeight;
                    cout << "������� ��� ���������: ";
                    cin.ignore();
                    getline(cin, characterName);
                    cout << "������� ������ ������� (��): ";
                    cin >> toyHeight;
                    unitSpec = new CollectibleToySpec(characterName, toyHeight);
                    break;
                }
                case '5': {
                    string material;
                    bool hasLight;
                    cout << "������� �������� ������: ";
                    cin.ignore();
                    getline(cin, material);
                    cout << "������� ���������? (1 - ��, 0 - ���): ";
                    cin >> hasLight;
                    unitSpec = new BrandedKeyringSpec(material, hasLight);
                    break;
                }
                case'6':
                    cout << "������ ��������� ������ ����������:" << endl;
                    for (const auto& unit : merchandiseUnits) {
                        unit->describe();
                    }
                    break;
                default:
                    cout << "������������ ����." << endl;
                    break;
                }

                if (unitSpec) {
                    MerchandiseUnit* unit = createMerchandiseUnitWithSpec(unitSpec);
                    if (unit) {
                        merchandiseUnits.push_back(unit);
                        cout << "����� ������." << endl;
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
                cout << "�������� ��� �����������:" << endl
                    << "1. �������-�������" << endl
                    << "2. ������" << endl
                    << "3. ������� �� �������" << endl
                    << "4. ������ ����������" << endl
                    << "5. ����������� ����������" << endl
                    << "6. ������� ��������� �����������" << endl
                    << "0. ��������� � ���������� ����" << endl
                    << "��� �����: ";
                cin >> eventType;
                cin.ignore();

                if (eventType >= 0 && eventType < eventRegistry.size()) {
                    Event* newEvent = Event::createEvent(eventType - 1);
                    events.push_back(newEvent);
                    cout << "������� ����� �����������." << endl;
                }
                else if (eventType == 0) {
                    subMenu = true;
                }
                else if (eventType == 6) {
                    cout << "������ ��������� �����������:" << endl;
                    for (const auto& unit : events) {
                        unit->describe();
                    }
                }
                else {
                    cout << "������������ �����." << endl;
                }
            }
            break;
        }
        case '4':
        {
            while (!subMenu) {
                cout << "����:" << endl
                    << "1. StandUP" << endl
                    << "2. Lecture" << endl
                    << "3. Meeting" << endl
                    << "4. LiveBroadcast" << endl
                    << "5. TheatricalProduction" << endl
                    << "6. ������� ������ �������������� ��������" << endl
                    << "0. �����" << endl
                    << "�������� ����������� ��� �������� (������� �����): ";

                int choice;
                cin >> choice;

                switch (choice) {
                case 1: {
                    gift::Event* standUp = new gift::StandUP;
                    eventsGifts.push_back(standUp);
                    cout << "������ StandUP �����������." << endl;
                    gift::Gift* gift = standUp->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 2: {
                    gift::Event* lecture = new gift::Lecture;
                    eventsGifts.push_back(lecture);
                    cout << "������� ����������� ������." << endl;
                    gift::Gift* gift = lecture->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 3: {
                    gift::Event* meeting = new gift::Meeting;
                    eventsGifts.push_back(meeting);
                    cout << "������� ����������� �������." << endl;
                    gift::Gift* gift = meeting->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 4: {
                    gift::Event* liveBroadcast = new gift::LiveBroadcast;
                    eventsGifts.push_back(liveBroadcast);
                    cout << "������� ����������� ������ ����������." << endl;
                    gift::Gift* gift = liveBroadcast->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 5: {
                    gift::Event* theatricalProduction = new gift::TheatricalProduction;
                    eventsGifts.push_back(theatricalProduction);
                    cout << "������� ����������� ����������� ����������." << endl;
                    gift::Gift* gift = theatricalProduction->distributeGift();
                    gift->celebrate();
                    break;
                }
                case 6:
                    cout << "������ ��������� �������� �� ��������� �����������:" << endl;
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
                    << "1. �������" << endl
                    << "2. �������" << endl
                    << "3. ������" << endl
                    << "4. ���������" << endl
                    << "0. ����� �� ���������" << endl
                    << "��� �����: ";

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
                    cout << "�������� �����." << endl;
                    continue;
                }

                foodItems.push_back(foodItem);

                cout << "������ ��� ������." << endl;
            }

            for (const auto& foodItem : foodItems) {
                Food* copy = foodItem->clone();
                copy->sell();
                delete copy;
            }
            break;
        }
        default: cout << "��������� ������������ �����." << endl;
            break;
        }
    }
}