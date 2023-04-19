#include "header.h"

aeroflot* front = nullptr;
aeroflot* rear = nullptr;

int checkInt(int a) {
	while (true) {
		cin >> a;
		if (cin.fail()) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Check the input! It can contain only numbers!\n";
			continue;
		}
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		if (cin.gcount() > 1) {
			cout << "Check the input! It can contain only numbers!\n";
			continue;
		}
		break;
	}
	return a;
}

string containsonlyletters(string str) {
	while (true) {
		cin >> str;
		if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTSTUVWXYZ") ==
			string::npos) {
			break;
		}
		else {
			cout << "the input can include only letters. try again." << endl;
			continue;
		}
	}
	return str;
}

void enqueue(string name, string type, int num) {
	aeroflot* temp = new aeroflot;
	temp->destination_name = name;
	temp->flight_type = type;
	temp->flight_num = num;
	temp->next = nullptr;
	if (rear == nullptr) {
		front = rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}

void dequeue() {
	if (front == nullptr) {
		cout << "The queue is empty.\n";
		return;
	}
	aeroflot* temp = front;
	front = front->next;
	if (front == nullptr) {
		rear = nullptr;
	}
	cout << "\Flights removed from the queue:\n";
	cout << "Name: " << temp->destination_name << endl;
	cout << "Type: " << temp->flight_type << endl;
	cout << "Number: " << temp->flight_num << endl;
	delete temp;
}

void display() {
	if (front == nullptr) {
		cout << "The queue is empty.\n";
		return;
	}
	cout << "The queue contains the following flights:\n";
	aeroflot* temp = front;
	while (temp != nullptr) {
		cout << "\nName: " << temp->destination_name << endl;
		cout << "Type: " << temp->flight_type << endl;
		cout << "Numb: " << temp->flight_num << endl;
		temp = temp->next;
	}
}