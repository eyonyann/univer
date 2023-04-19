#include "header.h"

int main() {
	int choice = 0, num = 0;
	string name = "";
	string type = "";
	do {
		cout << "1. Add a flight to the queue\n";
		cout << "2. Remove a flight from the queue\n";
		cout << "3. Display the flights in the queue\n";
		cout << "4. Quit\n";
		cout << "Enter your choice: ";
		choice = checkInt(choice);
		switch (choice) {
		case 1:
			system("cls");
			cout << "Enter destination name: ";
			name = containsonlyletters(name);
			cout << "Enter flight type: ";
			type = containsonlyletters(type);
			cout << "Enter flight num: ";
			num = checkInt(num);
			enqueue(name, type, num);
			system("cls");
			cout << "The purchase was added to the queue!\n";
			break;
		case 2:
			system("cls");
			dequeue();
			break;
		case 3:
			system("cls");
			display();
			break;
		case 4:
			break;
		default:
			cout << "Invalid choice. Try again.\n";
			break;
		}
	} while (choice != 4);
	return 0;
}