#pragma once

#include <iostream>
#include <fstream>

using namespace std;

float checkFloat(float a);
int checkInt(int a);

class City {
    string name;
    int population;

public:
    City(const string& name, int population) : name(name), population(population) {}

    string getName() const {
        return name;
    }

    int getPopulation() const {
        return population;
    }
};

class Shop {
    string name;
    string type;

public:
    Shop(const string& name, const string& type) : name(name), type(type) {}

    string getName() const {
        return name;
    }

    string getType() const {
        return type;
    }
};

class Product {
    string name;
    string type;
    int quantity;
    double price;

public:
    Product(const string& name, const string& type, int quantity, double price)
        : name(name), type(type), quantity(quantity), price(price) {}

    string getName() const {
        return name;
    }

    string getType() const {
        return type;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }
};

class Bank {
    string accountNumber;
    double balance;

public:
    Bank(const string& accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }
};

class Buyer {
    string lastName;
    double money;
    double purchaseAmount;

public:
    Buyer(const string& lastName, double money, double purchaseAmount)
        : lastName(lastName), money(money), purchaseAmount(purchaseAmount) {}

    string getLastName() const {
        return lastName;
    }

    double getMoney() const {
        return money;
    }

    double getPurchaseAmount() const {
        return purchaseAmount;
    }

    void makePurchase(const Product& product) {
        if (product.getQuantity() > 0 && money >= product.getPrice()) {
            purchaseAmount += product.getPrice();
            money -= product.getPrice();
            cout << "Purchase of product " << product.getName() << " was successful." << endl;
        }
        else {
            cout << "Failed to make a purchase of product " << product.getName() << "." << endl;
        }
    }

    void payThroughBank(Bank& bank) {
        if (purchaseAmount <= money) {
            money -= purchaseAmount;
            bank.setBalance(bank.getBalance() + purchaseAmount);
            purchaseAmount = 0;
            cout << "Payment through the bank was successful." << endl;
        }
        else {
            cout << "Failed to make a payment through the bank." << endl;
        }
    }

};