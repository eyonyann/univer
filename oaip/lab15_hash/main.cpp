#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Entry {
    int key;
    int value;
    Entry* next;
};

int polynomialHash(int key, int tableSize) {
    const int prime = 31; // Простое число для хеширования
    int hash = 0;
    int power = 1;

    while (key != 0) {
        int digit = key % 10;
        key /= 10;

        hash += digit * power;
        power *= prime;
    }

    return hash % tableSize;
}

void printHashtable(Entry** hashtable, int tableSize) {
    cout << "Хеш-таблица:" << endl;
    for (int i = 0; i < tableSize; ++i) {
        cout << "Bucket " << i << ": ";
        Entry* entry = hashtable[i];
        while (entry != nullptr) {
            cout << "Ключ: " << entry->key << ", Значение: " << entry->value << " -> ";
            entry = entry->next;
        }
        cout << "nullptr" << endl;
    }
    cout << endl;
}

void removeEvenKeys(Entry** hashtable, int tableSize) {
    for (int i = 0; i < tableSize; ++i) {
        Entry* entry = hashtable[i];
        Entry* prev = nullptr;

        while (entry != nullptr) {
            if (entry->key % 2 == 0) {
                if (prev == nullptr) {
                    hashtable[i] = entry->next;
                }
                else {
                    prev->next = entry->next;
                }
                Entry* toDelete = entry;
                entry = entry->next;
                delete toDelete;
            }
            else {
                prev = entry;
                entry = entry->next;
            }
        }
    }
    cout << "Записи с четными ключами удалены." << endl << endl;
}

int checkInt(int a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ввод может содержать только числа. Попробуйте еще раз." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.gcount() > 1) {
            cout << "Ввод может содержать только числа. Попробуйте снова." << endl;
            continue;
        }
        break;
    }
    return a;
}

int main() {

    const int TABLE_SIZE = 100; // Размер хеш-таблицы
    const int NUM_ENTRIES = 100; // Количество записей

    Entry** hashtable = new Entry * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashtable[i] = nullptr;
    }

    srand(time(nullptr));
    for (int i = 0; i < NUM_ENTRIES; ++i) {
        int key = rand() % 90 + 10;
        int value = i;

        int hash = polynomialHash(key, TABLE_SIZE);
        Entry* entry = new Entry;
        entry->key = key;
        entry->value = value;
        entry->next = nullptr;

        if (hashtable[hash] == nullptr) {
            hashtable[hash] = entry;
        }
        else {
            Entry* curr = hashtable[hash];
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = entry;
        }
    }

    int choice = 0;
    do {
        cout << "Меню:" << endl;
        cout << "1. Вывести хеш-таблицу" << endl;
        cout << "2. Удалить записи с четными ключами" << endl;
        cout << "3. Выход" << endl;
        cout << "Выберите опцию: ";
        choice = checkInt(choice);
        cout << endl;
        switch (choice) {
        case 1:
            printHashtable(hashtable, TABLE_SIZE);
            break;
        case 2:
            removeEvenKeys(hashtable, TABLE_SIZE);
            break;
        case 3:
            cout << "Программа завершена." << endl;
            return 0;
        default:
            cout << "Некорректный ввод. Попробуйте снова." << endl;
            break;
        }
    } while (true);

    for (int i = 0; i < TABLE_SIZE; ++i) {
        Entry* entry = hashtable[i];
        while (entry != nullptr) {
            Entry* toDelete = entry;
            entry = entry->next;
            delete toDelete;
        }
    }
    delete[] hashtable;

    return 0;
}
