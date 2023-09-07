#include "header.h"

int main() {
    const int maxObjects = 100;  
    int objectCount = 0; 
    City** cities = new City * [maxObjects];
    Shop** shops = new Shop * [maxObjects];
    Product** products = new Product * [maxObjects];
    Bank** banks = new Bank * [maxObjects];
    Buyer** buyers = new Buyer * [maxObjects];

    ofstream outputFile("data.txt");

    int choice = 0;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add a city" << endl;
        cout << "2. Add a shop" << endl;
        cout << "3. Add a product" << endl;
        cout << "4. Add a bank" << endl;
        cout << "5. Add a buyer" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an action: ";
        choice = checkInt(choice);

        switch (choice) {
        case 1: {
            if (objectCount < maxObjects) {
                string name;
                int population = 0;
                cout << "Enter the city name: ";
                cin >> name;
                cout << "Enter the population: ";
                population = checkInt(population);
                cities[objectCount] = new City(name, population);
                objectCount++;
                cout << "City successfully added." << endl;

                outputFile << cities[objectCount - 1]->getName() << "," << cities[objectCount - 1]->getPopulation() << endl;
            }
            else {
                cout << "Maximum number of objects reached." << endl;
            }
            break;
        }
        case 2: {
            if (objectCount < maxObjects) {
                string name, type;
                cout << "Enter the shop name: ";
                cin >> name;
                cout << "Enter the shop type: ";
                cin >> type;
                shops[objectCount] = new Shop(name, type);
                objectCount++;
                cout << "Shop successfully added." << endl;

                outputFile << shops[objectCount - 1]->getName() << "," << shops[objectCount - 1]->getType() << endl;
            }
            else {
                cout << "Maximum number of objects reached." << endl;
            }
            break;
        }
        case 3: {
            if (objectCount < maxObjects) {
                string name, type;
                int quantity = 0;
                double price = 0;
                cout << "Enter the product name: ";
                cin >> name;
                cout << "Enter the product type: ";
                cin >> type;
                cout << "Enter the product quantity: ";
                quantity = checkInt(quantity);
                cout << "Enter the product price: ";
                price = checkFloat(price);
                products[objectCount] = new Product(name, type, quantity, price);
                objectCount++;
                cout << "Product successfully added." << endl;

                outputFile << products[objectCount - 1]->getName() << "," << products[objectCount - 1]->getType() << ","
                    << products[objectCount - 1]->getQuantity() << "," << products[objectCount - 1]->getPrice() << endl;
            }
            else {
                cout << "Maximum number of objects reached." << endl;
            }
            break;
        }
        case 4: {
            if (objectCount < maxObjects) {
                string accountNumber;
                double balance = 0;
                cout << "Enter the account number: ";
                cin >> accountNumber;
                cout << "Enter the account balance: ";
                balance = checkFloat(balance);
                banks[objectCount] = new Bank(accountNumber, balance);
                objectCount++;
                cout << "Bank successfully added." << endl;

                outputFile << banks[objectCount - 1]->getAccountNumber() << "," << banks[objectCount - 1]->getBalance() << endl;
            }
            else {
                cout << "Maximum number of objects reached." << endl;
            }
            break;
        }
        case 5: {
            if (objectCount < maxObjects) {
                string lastName;
                double money = 0, purchaseAmount = 0;
                cout << "Enter the buyer's last name: ";
                cin >> lastName;
                cout << "Enter the buyer's money: ";
                money = checkFloat(money);
                cout << "Enter the buyer's purchase amount: ";
                purchaseAmount = checkFloat(purchaseAmount);
                buyers[objectCount] = new Buyer(lastName, money, purchaseAmount);
                objectCount++;
                cout << "Buyer successfully added." << endl;

                outputFile << buyers[objectCount - 1]->getLastName() << "," << buyers[objectCount - 1]->getMoney() << ","
                    << buyers[objectCount - 1]->getPurchaseAmount() << endl;
            }
            else {
                cout << "Maximum number of objects reached." << endl;
            }
            break;
        }
        case 6: {
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 6);

    for (int i = 0; i < objectCount; i++) {
        delete cities[i];
        delete shops[i];
        delete products[i];
        delete banks[i];
        delete buyers[i];
    }
    delete[] cities;
    delete[] shops;
    delete[] products;
    delete[] banks;
    delete[] buyers;

    return 0;
}
