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
        cout << "\n��������:\n";
        cout << "1. �������� ������\n";
        cout << "2. ����� �� �����\n";
        cout << "3. ������� ������ �� �����\n";
        cout << "4. ������� ���������� ������\n";
        cout << "5. ������� ����� ������ �� �����\n";
        cout << "6. ������� ������\n";
        cout << "7. �����\n";
        cout << "������� ����� ��������: ";
        choice = checkInt(choice);
        switch (choice) {
        case 1: {
            cout << "������� ����: ";
            int key = 0;
            key = checkInt(key);

            cout << "������� ������: ";
            string data;
            cin >> data;

            root = insert(root, key, data);
            cout << "������ ���������.\n";
            break;
        }
        case 2: {
            cout << "������� ���� ��� ������: ";
            int key = 0;
            key = checkInt(key);

            Node* result = search(root, key);
            if (result != nullptr) {
                cout << "������� ������: Key: " << result->key << ", Data: " << result->data << endl;
            }
            else {
                cout << "������ � ��������� ������ �� �������.\n";
            }
            break;
        }
        case 3: {
            cout << "������� ���� ��� ��������: ";
            int key = 0;
            key = checkInt(key);

            root = remove(root, key);
            cout << "������ �������.\n";
            break;
        }
        case 4: {
            cout << "���������� ������:\n";
            printTree(root, 0);

            break;
        }
        case 5: {
            cout << "������� ����: ";
            int key = 0;
            key = checkInt(key);

            root = removeBranch(root, key);
            break;
        }
        
        case 6:
        {
            int size = findDepth(root);
            cout << "������� ������: " << size << endl;
            break;
        }

        case 7:
        {
            cout << "����� �� ���������.\n";
            break;
        }
        default:
        {
            cout << "������������ �����. ���������� ��� ���.\n";
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
