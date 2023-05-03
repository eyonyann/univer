#include "header.h"

aeroflot* top = NULL;

void push() {
    aeroflot* newAeroflot = new aeroflot;
    cout << "Enter name: ";
    cin >> newAeroflot->destination_name;
    cout << "Enter type: ";
    cin >> newAeroflot->flight_type;
    cout << "Enter number: ";
    newAeroflot->flight_num = checkInt(newAeroflot->flight_num);
    newAeroflot->next = top;
    top = newAeroflot;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    aeroflot* toDelete = top;
    top = top->next;
    cout << "Deleted element: " << toDelete->destination_name << endl;
    delete toDelete;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements: " << endl;
    aeroflot* current = top;
    while (current != NULL) {
        cout << "Name: " << current->destination_name << endl;
        cout << "Amount: " << current->flight_type << endl;
        cout << "Price: " << current->flight_num << endl;
        cout << endl;
        current = current->next;
    }
}

int checkInt(int a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Check the input! It can contain only numbers!\n";
            continue;
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        if (cin.gcount() > 1) {
            cout << "Check the input! It can contain only numbers!\n";
            continue;
        }
        if (a <= 0) {
            cout << "Th enumber must be more than 0!" << endl;
        }
        break;
    }
    return a;
}
