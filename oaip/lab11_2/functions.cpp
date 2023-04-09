#include "Header.h"


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