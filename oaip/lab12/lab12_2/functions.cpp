#include "header.h"

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
        break;
    }
    return a;
}

string containsonlyletters(string str) {
    while (true) {
        cin >> str;
        if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTSTUVWXYZ") ==
            string::npos) {
            break;
        }
        else {
            cout << "the input can include only letters. try again." << endl;
            continue;
        }
    }
    return str;
}

bool isEmpty(aeroflot* head) {
    return head == nullptr;
}

void addFlight(aeroflot*& head, string name, string type, int num) {
    aeroflot* new_flights = new aeroflot;
    new_flights->destination_name = name;
    new_flights->flight_type = type;
    new_flights->flight_num = num;
    new_flights->next = nullptr;

    if (head == nullptr || head->destination_name > name) {
        new_flights->next = head;
        head = new_flights;
    }
    else {
        aeroflot* current_flights = head;
        while (current_flights->next != nullptr && current_flights->next->destination_name <= name) {
            current_flights = current_flights->next;
        }
        new_flights->next = current_flights->next;
        current_flights->next = new_flights;
    }
}

void deleteFlight(aeroflot*& head, string name) {
    if (isEmpty(head)) {
        cout << "The list is empty!\n";
        return;
    }

    if (head->destination_name == name) {
        aeroflot* temp_flight = head;
        head = head->next;
        delete temp_flight;
        cout << "The purchase " << name << " was deleted." << endl;
        return;
    }

    aeroflot* current_flights = head;
    while (current_flights->next != nullptr && current_flights->next->destination_name != name) {
        current_flights = current_flights->next;
    }
    if (current_flights->next == nullptr) {
        cout << "The purchase " << name << " wasn't found." << endl;
    }
    else {
        aeroflot* temp_flight = current_flights->next;
        current_flights->next = current_flights->next->next;
        delete temp_flight;
        cout << "The purchase " << name << " was deleted." << endl;
    }
}

void print_list(aeroflot* head) {
    if (isEmpty(head)) {
        cout << "The list is empty!\n";
        return;
    }

    aeroflot* current_flights = head;
    while (current_flights != nullptr) {
        cout << current_flights->destination_name << " "
            << current_flights->flight_type << " "
            << current_flights->flight_num << endl;
        current_flights = current_flights->next;
    }
}