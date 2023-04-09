#include "Header.h"

struct aeroflot
{
	char destination_name[20];
	char flight_type[20];
	int flight_num;
};

static aeroflot flights[100], tmp;

int number_of_flights;



extern void print(int* array, int size) {
	int a;
	cout << "How many elements do you want to see? [equal or less than " << size << "]: ";
	while (true) {
		cin >> a;
		if (a > size || a < 0) cout << "Error. Try again." << endl;
		else break;
	}
	for (int i = 0; i < a; i++) {
		cout << array[i] << " ";
	}
}

void result(int* temporary, int size) {
	char choice;
	int a;
	cout << "The array was successfully sorted!" << endl;
	cout << "Do you want to see the array? [y/n]" << endl;
	cin >> choice;
	switch (choice)
	{
	case 'y':
	case 'Y':
		cout << "How many elements do you want to see? [equal or less than " << size << "]: ";
		while (true) {
			cin >> a;
			if (a > size) cout << "Error. Try again." << endl;
			else break;
		}
		for (int i = 0; i < a; i++) {
			cout << temporary[i] << " ";
		}
		break;
	case 'n':
	case 'N':
		break;
	default: cout << "Check the input." << endl;
		break;
	}
}

extern void bubbleSort(int* array, int size) {
	int* temporary = new int[size];
	for (int i = 0; i < size; i++) {
		temporary[i] = array[i];
	}
	double start = clock();
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--) {
			if (temporary[j - 1] > temporary[j]) {
				swap(temporary[j - 1], temporary[j]);
			}
		}
	}
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	result(temporary, size);
}

extern void minSort(int* array, int size) {
	int* temporary = new int[size];
	int i, j;
	for (i = 0; i < size; i++) {
		temporary[i] = array[i];
	}
	double start = clock();
	for (i = 0; i < size; i++) {
		int smallest = temporary[i];
		int smallestIdx = i;
		for (j = i + 1; j < size; j++) {
			if (temporary[j] < smallest) {
				smallest = temporary[j];
				smallestIdx = j;
				swap(temporary[i], temporary[smallestIdx]);
			}
		}
	}
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	result(temporary, size);
}

extern void insertSort(int* array, int size) {
	int* temporary = new int[size];
	for (int i = 0; i < size; i++) {
		temporary[i] = array[i];
	}
	double start = clock();
	for (int i = 0; i < size; i++) {
		int j = i;
		while (j > 0 && temporary[j] < temporary[j - 1]) {
			swap(temporary[j], temporary[j - 1]);
			j--;
		}
	}
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	result(temporary, size);
}

extern void shellSort(int* array, int size) {
	int* temporary = new int[size];
	for (int i = 0; i < size; i++) {
		temporary[i] = array[i];
	}
	double start = clock();
	int gap, sorted, i, j;
	for (gap = size / 2; gap > 0; gap /= 2) {
		do {
			sorted = 0;
			for (i = 0, j = gap; j < size; i++, j++) {
				if (temporary[i] > temporary[j]) {
					swap(temporary[i], temporary[j]);
					sorted = 1;
				}
			}
		} while (sorted);
	}
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	result(temporary, size);
}

void qs(int* temporary, int first, int last) {
	int i = first;
	int j = last;
	int pivot = temporary[(i + j) / 2];

	while (i <= j) {
		while (temporary[i] < pivot) i++;
		while (temporary[j] > pivot) j--;
		if (i <= j) {
			swap(temporary[i], temporary[j]);
			i++;
			j--;
		}
	}
	if (j > first) qs(temporary, first, j);
	if (i < last) qs(temporary, i, last);
}

extern void hoorSort(int* array, int first, int size) {
	int* temporary = new int[size];
	for (int i = 0; i < size; i++) {
		temporary[i] = array[i];
	}
	double start = clock();
	qs(temporary, first, size - 1);
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	result(temporary, size);
}

bool is_sorted(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

extern void bogoSort(int* array, int size) {
	int* temporary = new int[size];
	for (int i = 0; i < size; i++) {
		temporary[i] = array[i];
	}
	double start = clock();
	for (int i = 0; i < size; i++) {
		srand(time(NULL));
		while (!is_sorted(array, size)) {
			for (int i = 0; i < size; i++) {
				int j = rand() % size;
				swap(array[i], array[j]);
			}
		}
	}
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	result(temporary, size);
}

extern void seqSearch(int* array, int size, int key) {
	int* temporary = new int[size];
	int count = 0;
	for (int i = 0; i < size; i++) {
		temporary[i] = array[i];
	}
	qs(temporary, 0, size - 1);
	double start = clock();
	for (int i = 0; i < size; i++) {
		if (temporary[i] == key) {
			cout << "The element " << temporary[i] << " has " << i << " position." << endl;
			count++;
		}
	}
	if (count == 0) cout << "there is no such element in the array." << endl;
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
}

extern int binarySearch(int* arr, int low, int high, int key) {
	int* temporary = new int[high + 1];
	int count = 0;
	for (int i = 0; i < high + 1; i++) {
		temporary[i] = arr[i];
	}
	qs(temporary, 0, high);
	double start = clock();
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (temporary[mid] == key) {
			double end = clock();
			cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
			return mid;
		}
		else if (temporary[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	double end = clock();
	cout << "It has taken " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
	return -1;
}




int main10()
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

extern void sort_name() //insert вставками
{
	for (int i = 1; i < number_of_flights; i++) {
		aeroflot temp = flights[i];
		int j = i - 1;
		while (j >= 0 && strcmp(flights[j].destination_name, temp.destination_name) > 0) {
			flights[j + 1] = flights[j];
			j--;
		}
		flights[j + 1] = temp;
	}

}

extern void sort_type() // min выбором
{
	int i, j, min_idx;
	for (i = 0; i < number_of_flights - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < number_of_flights; j++) {
			if (strcmp(flights[j].flight_type, flights[min_idx].flight_type) < 0) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			aeroflot temp = flights[i];
			flights[i] = flights[min_idx];
			flights[min_idx] = temp;
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
