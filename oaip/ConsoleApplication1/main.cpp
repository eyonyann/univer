#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#define FILE_NAME "data.txt"

using namespace std;

void file_checker();
int data_checker();

void enter();
void enter_struct();
void out_struct();

void sort_by_name();
void sort_by_type();
void sort_by_num();

void enter_sort_data();
void remove_overflow(int remove_inf);
void delet_inf();

//string char_to_sring(char input[20]);
//void string_to_char(string input, aeroflot* flights);



struct aeroflot
{
	char destination_name[20];
	char flight_type[20];
	int flight_num;
};

aeroflot  flights[100], tmp;
int number_of_flights;
 

int main()
{

	srand(time(NULL));
	file_checker();

	cout << endl << "How many flights do u want to enter?\n" << endl;
	cin >> number_of_flights;

	while (true)
	{
		int choice;
		cout << endl << "How u want to sort flights?\n" << endl;
		cout << "1. Randomize" << endl;
		cout << "2. Sort by type" << endl;
		cout << "3. Sort by number" << endl;
		cout << "4. Sort by name" << endl;
		cout << "5. Delete all information" << endl;
		cout << "6. Show the structure" << endl;
		cout << "7. Exit\n" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{

			enter();
			//data_checker();
			enter_struct();
			out_struct();
			break;
		}
		case 2:
		{
			sort_by_type();
			enter_sort_data();
			out_struct();
			break;
		}
		case 3:
		{
			sort_by_num();
			enter_sort_data();
			out_struct();
			break;
		}
		case 4:
		{
			sort_by_name();
			enter_sort_data();
			out_struct();
			break;
		}
		case 5:
		{
			delet_inf();
			//enter_struct();
			break;
		}
		case 6:
		{
			out_struct();
			break;
		}
		case 7:
		{
			exit(1);
			break;
		}
		default:
		{
			cout << "There is no such option!" << endl;
			cout << "Please enter correct data" << endl;

			break;
		}

		}
	}
	delete[] flights;

	return 0;
}


void file_checker()
{

	ofstream fout;

	fout.open(FILE_NAME, std::ios::app);

	if (!fout.is_open())
	{
		cout << "Can't open file!\n";
		
	}
	else
	{
		cout << "There is file\n\n";
	}
	fout.close();
}

int data_checker()
{
	int counter = 0;
		fstream fin;

		fin.open(FILE_NAME, std::ios::in);

		if (!fin.is_open())
		{
			cout << "\nCan't open file!\n";
		}
		else
		{
			int counter = 0;
			string str;
			while (!fin.eof())
			{
				str = "";
				getline(fin, str);
				counter++;
			}
			cout << "\nThere are " << counter - 1 << " flihts" << endl;

			if (counter == 1)
			{
				cout << "\nThere are no information yet \n\n";

			}
			else cout << "All is ok\n\n";
		}
		fin.close();
		return counter;
}


void enter()
{

	ofstream fout(FILE_NAME);

	if (!fout.is_open())
	{
		cout << "\nCan't open file!\n";
	}
	else
	{
		for (int i = 0; i < number_of_flights; i++)
		{
			fout << char(rand() % 26 + 0x61) << " ";
			fout << char(rand() % 26 + 0x61) << " ";
			fout << rand() % 26 << endl;
		}
	}
	fout.close();
}

void enter_struct()
{
	fstream fin(FILE_NAME);

	if (!fin.is_open())
	{
		cout << "\nCan't open file!\n";
	}
	else
	{
		for (int i = 0; i < number_of_flights; i++)
		{
			fin >> flights[i].destination_name;
			fin >> flights[i].flight_type;
			fin >> flights[i].flight_num;
		}
	}
	fin.close();
}

void out_struct()
{
	for (int i = 0; i < number_of_flights; i++)
	{
		cout << flights[i].destination_name << " ";
		cout << flights[i].flight_type << " ";
		cout << flights[i].flight_num << endl;
	}
}


void sort_by_name()
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

void sort_by_type()
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

void sort_by_num()
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

void enter_sort_data()
{
	fstream fout(FILE_NAME);

	if (!fout.is_open())
	{
		cout << "\nCan't open file!\n";
	}
	else
	{
		for (int i = 0; i < number_of_flights; i++)
		{
			fout << flights[i].destination_name << " ";
			fout << flights[i].flight_type << " ";
			fout << flights[i].flight_num << endl;
		}
	}
	fout.close();
}


void remove_overflow(int remove_inf)
{
	fstream fin(FILE_NAME, ios::app);

	if (!fin.is_open())
	{
		cout << "\nCan't open file!\n";
	}
	else
	{
		for (int i = 0; i < number_of_flights - remove_inf; i++)
		{
			fin >> flights[i].destination_name;
			fin >> flights[i].flight_type;
			fin >> flights[i].flight_num;
		}
	}
	fin.close();
}

void delet_inf()
{
	remove(FILE_NAME);
	ofstream fout;
	fout.open(FILE_NAME, ios::out);

	if (!fout.is_open())
	{
		cout << "\nCan't open file!\n";
	}
	else
	{
		cout << "\nInformation was deleted\n";
	}
	fout.close();
}


//string char_to_sring(char input[20])
//{
//	char* tmp = input;
//	string output(tmp);
//	return output;
//}
//
//void string_to_char(string input, aeroflot* flights)
//{
//	for (int i = 0; i < input.length(); i++)
//		*flights[i].destination_name = input[i];
//}