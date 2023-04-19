#include <iostream>
using namespace std;

struct ListNode {
	int book;
	ListNode* next;
};

typedef ListNode* ListNodePtr;

void insert(ListNodePtr&, int);
char del(ListNodePtr&, int);
bool isEmpty(ListNodePtr);
void printList(ListNodePtr);
void instructions();

int countList(ListNodePtr& s);
int findMax(ListNodePtr& s);
int findMin(ListNodePtr& s);
void deleteRepeats(ListNodePtr& s);
int deleteRepeatsOfElement(ListNodePtr& s, int value);

int checkInt(int a);

int main() {
	ListNodePtr start = nullptr;
	int choice = 0;
	int elem = 0;
	instructions();
	cout << "? ";
	choice = checkInt(choice);
	while (choice != 8) {
		switch (choice) {
		case 1:
			cout << "Enter a character: ";
			elem = checkInt(elem);
			insert(start, elem);
			printList(start);
			break;
		case 2:
			if (!isEmpty(start)) {
				cout << "Enter character to be deleted: ";
				elem = checkInt(elem);
				if (del(start, elem))
					cout << elem << " deleted.\n";
				else
					cout << elem << " not found.\n";
				printList(start);
			}
			else
				cout << "List is empty.\n";
			break;

		case 3:
			cout << "\nIn list there is/are " << countList(start) << " element(s)\n";
			printList(start);
			break;


		case 4:
			if (!isEmpty(start)) {
				cout << "\nIn list max value is " << findMax(start);
				printList(start);
			}
			else
				cout << "List is empty.\n";
			break;

		case 5:
			if (!isEmpty(start)) {
				cout << "\nIn list min value is " << findMin(start);
				printList(start);
			}
			else
				cout << "List is empty.\n";
			break;

		case 6:
			if (!isEmpty(start)) {
				deleteRepeats(start);
				cout << "\nAll repeats are deleted\n";
				printList(start);
			}
			else
				cout << "List is empty.\n";
			break;

		case 7:
			if (!isEmpty(start)) {
				cout << "Enter character to be deleted: ";
				elem = checkInt(elem);
				if (deleteRepeatsOfElement(start, elem) > 0)
					cout << elem << " deleted.\n";
				else
					cout << elem << " not found.\n";
				if (!isEmpty(start)) printList(start);
			}
			else
				cout << "List is empty.\n";
			break;

		default:
			cout << "Invalid choice.\n";
			instructions();
			break;
		}
		cout << "? ";
		choice = checkInt(choice);
	}
	cout << "End of run.\n";
	return 0;
}

void instructions() {
	cout << "Enter choice:\n"
		<< "1. Insert an element into the list.\n"
		<< "2. Delete an element from the list.\n"
		<< "3. Count of elements in the list.\n"
		<< "4. Find max.\n"
		<< "5. Find min.\n"
		<< "6. Delete all repeats.\n"
		<< "7. Delete all repeats of element.\n"
		<< "8. End program.\n";
}

void insert(ListNodePtr& s, int value) {
	ListNodePtr newP = new ListNode;
	newP->book = value;
	newP->next = nullptr;
	ListNodePtr previous = nullptr, current = s;
	while (current != nullptr && value > current->book) {
		previous = current;
		current = current->next;
	}
	if (previous == nullptr) {
		newP->next = s;
		s = newP;
	}
	else {
		previous->next = newP;
		newP->next = current;
	}
}

char del(ListNodePtr& s, int value) {
	ListNodePtr previous = nullptr, current = s, temp;
	if (value == s->book) {
		temp = s;
		s = s->next;
		delete temp;
		return value;
	}
	else {
		while (current != nullptr && current->book != value) {
			previous = current;
			current = current->next;
		}
		if (current != nullptr) {
			temp = current;
			previous->next = current->next;
			delete temp;
			return value;
		}
	}
	return '\0';
}

bool isEmpty(ListNodePtr s) {
	return s == nullptr;
}

void printList(ListNodePtr current) {
	if (isEmpty(current))
		cout << "\nThe list is empty.\n";
	else {
		cout << "\nThe list is:\n";
		while (current != nullptr) {
			cout << current->book << "-->";
			current = current->next;
		}
		cout << "NULL\n";
	}
}

int countList(ListNodePtr& s) {

	ListNodePtr previous = nullptr, current = s;
	int count = 0;

	while (current != nullptr) {
		previous = current;
		current = current->next;
		count++;
	}
	return count;
}

int findMax(ListNodePtr& s) {

	ListNodePtr previous = nullptr, current = s;
	int max = current->book;

	while (current != nullptr) {
		if (current->book > max) max = current->book;
		previous = current;
		current = current->next;

	}
	return max;
}

int findMin(ListNodePtr& s) {

	ListNodePtr previous = nullptr, current = s;
	int min = current->book;

	while (current != nullptr) {
		if (current->book < min) min = current->book;
		previous = current;
		current = current->next;

	}
	return min;
}

void deleteRepeats(ListNodePtr& s) {
	if (s == nullptr || s->next == nullptr) {
		return;
	}
	ListNodePtr previous = s, current = s->next;
	while (current != nullptr) {
		if (previous->book == current->book) {

			ListNodePtr temp = current;
			previous->next = current->next;
			current = current->next;
			delete temp;
		}
		else {
			previous = current;
			current = current->next;
		}
	}
}


int deleteRepeatsOfElement(ListNodePtr& s, int value) {
	if (s == nullptr) {
		return -1;
	}

	ListNodePtr previous = nullptr, current = s;
	int counter = 0;

	while (current != nullptr) {
		if (current->book == value) {
			if (previous == nullptr) {
				s = current->next;
			}
			else {
				previous->next = current->next;
			}
			ListNodePtr temp = current;
			current = current->next;
			delete temp;
			counter++;
		}
		else {
			previous = current;
			current = current->next;
		}
	}

	return counter;
}


int checkInt(int a) {
	while (true) {
		cin >> a;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "The input can include only numbers. Try again." << endl;
			continue;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1) {
			cout << "The input can include only numbers. Try again." << endl;
			continue;
		}
		break;
	}
	return a;
}