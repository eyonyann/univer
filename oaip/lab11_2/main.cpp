#include "Header.h"



int main() {

	int first, last, size;
	srand(time(NULL));
	cout << "Enter the size of arrays: ";
	cin >> size;
	cout << "Enter range [a;b] (where a < b) of random numbers: ";
	cin >> first >> last;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = first + rand() % (last - first + 1);
	}

	cout << "The array was succesfully initialized!" << endl;

	char choice, srch;
	int key, result;
	do {
		cout << endl << "Choose the function you want to see: " << endl
			<< "1. Print the array;" << endl
			<< "2. Result of bubble sort;" << endl
			<< "3. Result of min sort;" << endl
			<< "4. Result of insert sort;" << endl
			<< "5. Result of Shell sort;" << endl
			<< "6. Result of Hoor sort;" << endl
			<< "7. Result of bogo sort;" << endl
			<< "8. Search;" << endl
			<< "0. Exit." << endl
			<< "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case '1': print(array, size); break;
		case '2': bubbleSort(array, size); break;
		case '3': minSort(array, size); break;
		case '4': insertSort(array, size); break;
		case '5': shellSort(array, size); break;
		case '6': hoorSort(array, 0, size); break;
		case '7': bogoSort(array, size); break;
		case '8':
			cout << "Enter the element you want to find: ";
			cin >> key;
			cout << "1. Sequential search;" << endl
				<< "2. Binary search;" << endl;
			cin >> srch;
			switch (srch)
			{
			case '1': seqSearch(array, size, key); break;
			case '2': result = binarySearch(array, 0, size - 1, key);
				if (result == -1) cout << "Not found" << endl;
				else cout << "The element was found at index " << result << endl;
				break;
			default: cout << "Check the input; "; break;
			}
			break;
		case '0': return 0; break;
		default: cout << "Check the input."; break;
		}
	} while (choice != 9);
}