#include "header.h"

int main() {
    int choice;
    while (true) {
        cout << "1. Push element into the stack" << endl;
        cout << "2. Pop element from the stack" << endl;
        cout << "3. Display stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}