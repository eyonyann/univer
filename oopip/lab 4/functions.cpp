#include"header.h"

float checkFloat(float a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The input can only contain numbers. Try again." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.gcount() > 1) {
            cout << "The input can only contain numbers. Try again." << endl;
            continue;
        }

        if (a < 0) {
            cout << "The input cannot contain negative numbers. Try again." << endl;
            continue;
        }
        break;
    }
    return a;
}

int checkInt(int a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The input can only contain numbers. Try again." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.gcount() > 1) {
            cout << "The input can only contain numbers. Try again." << endl;
            continue;
        }

        if (a < 0) {
            cout << "The input cannot contain negative numbers. Try again." << endl;
            continue;
        }
        break;
    }
    return a;
}