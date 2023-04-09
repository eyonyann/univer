#include <string>
#include <iostream>
#include "Header.h"
using namespace std;

extern int number_of_flights;

int main()
{

	int choice;
	do {
		cout << endl;
		cout << "1. Enter information." << endl;
		cout << "2. Read  all information." << endl;
		cout << "3. Find flights by destinations." << endl;
		cout << "4. Sort information." << endl;
		cout << "5. Quit from programm." << endl << endl;
		cout << "Enter your choice: " << endl;

		cin >> choice;
		check_int(choice);

		switch (choice)
		{
		case 1: enter();
			break;
		case 2: print_all();
			break;
		case 3: find();
			break;
		case 4:
		{
			sort();
			break;
		}
		case 5: return 0;
		default:
		{
			cout << "There is no such option!" << endl;
			cout << "Please enter correct data" << endl;

			break;
		}
		}

	} while (true);
	return 0;
}
