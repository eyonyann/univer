#include "header.h"

int main() {
    Node* root = nullptr;

    ifstream inputFile("data.txt", ios::in);
    if (!inputFile) {
        ofstream outputFile("data.txt");
        outputFile.close();
        ifstream inputFile("data.txt");
    }

    int key;
    string data;
    while (inputFile >> key && getline(inputFile, data)) {
        root = insert(root, key, data);
    }
    inputFile.close();
    

    int choice = 0;
    do {
        cout << "\nВыберите:\n";
        cout << "1. Добавить запись\n";
        cout << "2. Поиск по ключу\n";
        cout << "3. Удалить запись по ключу\n";
        cout << "4. Вывести содержимое дерева\n";
        cout << "5. Удалить ветку дерева по ключу\n";
        cout << "6. Глубина дерева\n";
        cout << "7. Выход\n";
        cout << "Введите номер операции: ";
        choice = checkInt(choice);
        switch (choice) {
        case 1: {
            cout << "Введите ключ: ";
            int key = 0;
            key = checkInt(key);

            cout << "Введите данные: ";
            string data;
            cin >> data;

            root = insert(root, key, data);
            cout << "Запись добавлена.\n";
            break;
        }
        case 2: {
            cout << "Введите ключ для поиска: ";
            int key = 0;
            key = checkInt(key);

            Node* result = search(root, key);
            if (result != nullptr) {
                cout << "Найдена запись: Key: " << result->key << ", Data: " << result->data << endl;
            }
            else {
                cout << "Запись с указанным ключом не найдена.\n";
            }
            break;
        }
        case 3: {
            cout << "Введите ключ для удаления: ";
            int key = 0;
            key = checkInt(key);

            root = remove(root, key);
            cout << "Запись удалена.\n";
            break;
        }
        case 4: {
            cout << "Содержимое дерева:\n";
            printTree(root, 0);

            break;
        }
        case 5: {
            cout << "Введите ключ: ";
            int key = 0;
            key = checkInt(key);

            root = removeBranch(root, key);
            break;
        }
        
        case 6:
        {
            int size = findDepth(root);
            cout << "Глубина дерева: " << size << endl;
            break;
        }

        case 7:
        {
            cout << "Выход из программы.\n";
            break;
        }
        default:
        {
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
            break;
        }
        }
    } while (choice != 7);

    ofstream outputFile("data.txt");
    saveDataToFile(root, outputFile);
    outputFile.close();

    freeMemory(root);

    return 0;
}
