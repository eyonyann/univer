#include "header.h"

int main() {
	aeroflot* head = nullptr;
	int choice = 0, num = 0;
	string name = "";
	string type = "";

	do {
		cout << "Choose variant:\n"
			<< "1. Add new element.\n"
			<< "2. Delete certain element.\n"
			<< "3. Print all list.\n"
			<< "4. Exit.\n"
			<< "Your choice: ";
		choice = checkInt(choice);

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Enter destination name: ";
			name = containsonlyletters(name);
			cout << "Enter flight type: ";
			type = containsonlyletters(type);
			cout << "Enter flight num: ";
			num = checkInt(num);
			addFlight(head, name, type, num);
			system("cls");
			cout << "The element was added!\n";
			break;
		case 2:
			system("cls");
			cout << "Enter the destination name of the flight you want to delete: ";
			name = containsonlyletters(name);
			system("cls");
			deleteFlight(head, name);
			break;
		case 3:
			system("cls");
			print_list(head);
			break;
		case 4: break;
		default: system("cls"); cout << "Check the input!";
			break;
		}
	} while (choice != 4);
	return 0;
}