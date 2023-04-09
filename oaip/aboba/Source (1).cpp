#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>

#define FILE_NAME "data.txt"

using namespace std;

void file_checker();
void enter();
void data_checker();
void out_struct();

int number_of_flights = 6;


struct aeroflot
{
	string destination_name;
	string flight_type;
	int flight_num;
};

aeroflot  flights[7], tmp;



int main()
{
	srand(time(NULL));

	file_checker();

	/*cout << "Size is \n";
	cin >> number_of_flights;*/

	enter();
	data_checker();
	out_struct();

	return 0;
}

void file_checker()
{

	ofstream fout;

	fout.open(FILE_NAME);

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
			fout << rand() % 26 << "\n";
		}
	}
	fout.close();
}

void data_checker()
{

	fstream fin;

	fin.open(FILE_NAME, std::ios::in);


	if (!fin.is_open())
	{
		cout << "\nCan't open file!\n";
	}
	else
	{

		int i = 0;
		string str;

		while (!fin.eof())
		{
			getline(fin, flights[i].destination_name, ' ');
			str = "";
			getline(fin, flights[i].flight_type, ' ');
			str = "";
			fin >> str;
			flights[i].flight_num = stoi(str);
			str = "";
			i++;
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
