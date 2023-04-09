#include <string>
#include <iostream>
#include "Header.h"

using namespace std;

struct aeroflot
{
	char destination_name[20];
	char flight_type[20];
	int flight_num;
};

static aeroflot flights[100], tmp;

int number_of_flights;


extern void enter()
{

	cout << "How many flights do you want to enter?" << endl;
	int new_flights;
	cin >> new_flights;
	new_flights = check_int(new_flights);

	int current_number_of_flights = number_of_flights;

	for (int i = 0; i < new_flights; i++)
	{
		cout << "Enter " << current_number_of_flights + i + 1 << " destination name " << endl;
		cin >> flights[current_number_of_flights + i].destination_name;
		containsOnlyLetters(flights[current_number_of_flights + i].destination_name);
		cout << "Enter " << current_number_of_flights + i + 1 << " flight type " << endl;
		cin >> flights[current_number_of_flights + i].flight_type;
		containsOnlyLetters(flights[current_number_of_flights + i].flight_type);
		cout << "Enter " << current_number_of_flights + i + 1 << " flight num " << endl;
		cin >> flights[current_number_of_flights + i].flight_num;
		check_int(flights[current_number_of_flights + i].flight_num);
	}

	number_of_flights += new_flights;
}

extern void print_all()
{
	cout << "\tName\t\t\tType\t\t\tNumber\n\n";
	//cout << setw(10) << "Type";
	//cout << setw(10) << "Number\n\n";
	for (int i = 0; i < number_of_flights; i++)
	{
		cout << "\t" << flights[i].destination_name;
		cout << "\t\t\t" << flights[i].flight_type;
		cout << "\t\t\t" << flights[i].flight_num;
		cout << endl;
	}
}

extern int find()
{
	if (!flights[0].flight_num)
	{
		cout << "You must enter information.\n\n";
		return 0;
	}

	char enter_name[20];
	cout << "Enter destination name" << endl;
	cin >> enter_name;
	containsOnlyLetters(enter_name);

	int counter = 0;
	for (int i = 0; i < number_of_flights; i++)
	{
		if (strcmp(enter_name, flights[i].destination_name) == 0)
		{
			cout << "\tName\t\t\tType\t\t\tNumber\n\n";
			
			cout << "\t" << flights[i].destination_name;
			cout << "\t\t\t" << flights[i].flight_type;
			cout << "\t\t\t" << flights[i].flight_num;
			cout << endl;
		}
		counter++;

	}

	if (counter == number_of_flights)
	{
		cout << "\nThere is no such destination name" << endl;
	}

}


extern int sort()
{
	if (!flights[0].flight_num)
	{
		cout << "You must enter information.\n\n";
		return 0;
	}

	int choice;
	do {
		cout << " 1. Sort by flight number.\n";
		cout << " 2. Sort by destination name.\n";
		cout << " 3. Sort by flight type.\n";
		cin >> choice;
		check_int(choice);

		switch (choice)
		{
		case 1: sort_num();
			break;
		case 2: sort_name();
			break;
		case 3: sort_type();
			break;
		default:
		{
			cout << "There is no such option!" << endl;
			cout << "Please enter correct data" << endl;

			break;
		}
		}
	} while (choice > 4);

	cout << "***Complited***\n";

	return 0;
}

extern void sort_num()
{
	for (int i = 0; i < number_of_flights; i++)
	{
		for (int j = 0; j < number_of_flights - 1; j++)
		{
			if (flights[j].flight_num > flights[j + 1].flight_num)
			{
				tmp = flights[j];
				flights[j] = flights[j + 1];
				flights[j + 1] = tmp;
			}
		}
	}
}

extern void sort_name() 
{
	for (int i = 0; i < number_of_flights; i++)
	{
		for (int j = 0; j < number_of_flights - 1; j++)
		{
			if (strcmp(flights[j].destination_name, flights[j + 1].destination_name) > 0)
			{
				tmp = flights[j];
				flights[j] = flights[j + 1];
				flights[j + 1] = tmp;
			}
		}
	}
}

extern void sort_type()
{
	for (int i = 0; i < number_of_flights; i++)
	{
		for (int j = 0; j < number_of_flights - 1; j++)
		{
			if (strcmp(flights[j].flight_type, flights[j + 1].flight_type) > 0)
			{
				tmp = flights[j];
				flights[j] = flights[j + 1];
				flights[j + 1] = tmp;
			}
		}
	}
}

string char_to_sring(char input[20])
{
	char* tmp = input;
	string output(tmp);
	return output;
}


char containsOnlyLetters(char input[20]) {

	char* tmp = input;
	string str(tmp);

	while (true) {
		getline(cin, str, '\n');
		if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos) {
			break;
		}
		else {
			cout << "The input can include only letters. Try again." << endl;
			continue;
		}
	}
	return input[20];
}
int check_int(int input) {
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "The input can include only numbers. Try again." << endl;
			return -1;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1) {
			cout << "The input can include only numbers. Try again." << endl;
			return -1;
		}
		if (input <= 0) {
			cout << "The number must be more than 0. Try again." << endl;
			return -1;
		}
		break;
	}
	return input;
}