#include <iostream>
#include <string>
#include <fstream>

#define FILE_EMPLOYEES "employees.txt"

using namespace std;

//void readEmployeesFromFile( employee*& employees, int numEmployees);
void printEmployees(int numEmployees);

void printEmployee();

void addEmployee();
void addToFile();

bool isDigit(string text);
bool isFloat(string str);

class date {
private:
	int day;
	int month;
	int year;

public:

	date() {
		day = 1;
		month = 1;
		year = 2000;
	}

	date(int d, int m, int y) {
		setDay(d);
		setMonth(m);
		setYear(y);
	}

	void setDay(int d) {
		if (d > 0 && d <= 31) {
			day = d;
		}
		else {
			cout << "������: ������������ �������� ���\n";
		}
	}

	void setMonth(int m) {
		if (m > 0 && m <= 12) {
			month = m;
		}
		else {
			cout << "������: ������������ �������� ������\n";
		}
	}

	void setYear(int y) {
		if (y >= 2000 && y <= 2050) {
			year = y;
		}
		else {
			cout << "������: ������������ �������� ����\n";
		}
	}


	int getDay() {
		return day;
	}

	int getMonth() {
		return month;
	}

	int getYear() {
		return year;
	}


	void printDate() {
		cout << day << "." << month << "." << year << endl;
	}
};

enum position {
	LABORATORY_ASSISTANT,
	SECRETARY,
	MANAGER
};

class employee {
private:
	int id;
	float salary;

	date hire_date;
	position emp_position;

public:
	employee() {
		id = 0;
		salary = 0;
		emp_position = LABORATORY_ASSISTANT;
	}

	employee(int id, float salary, date hire_date, position emp_position) {
		setId(id);
		setSalary(salary);
		setHireDate(hire_date);
		setPosition(emp_position);
	}

	employee(const employee& other) {
		id = other.id;
		salary = other.salary;
		hire_date = other.hire_date;
		emp_position = other.emp_position;
	}

	//~employee() {
	//	delete[] employees;
	//}



	void setId(int id) {

	if (id >= 0) {
		this->id = id;
	}
	else {
		cout << "������: ������������ �������� ������������������ ������\n";
	}
}

	void setSalary(float salary) {
		if (salary >= 0) {
			this->salary = salary;
		}
		else {
			cout << "������: ������������ �������� ������\n";
		}
	}

	void setHireDate(date hire_date) {
		this->hire_date = hire_date;
	}

	void setPosition(position emp_position) {
		this->emp_position = emp_position;
	}



	int getId() {
		return id;
	}

	float getSalary() {
		return salary;
	}

	int getHireDay() {
		return hire_date.getDay();
	}
	int getHireMonth() {
		return hire_date.getMonth();
	}
	int getHireYear() {
		return hire_date.getYear();
	}

	position getPosition() {
		return emp_position;
	}


	void printEmployee() {

		cout << "����������������� �����: " << id << endl;
		cout << "�����: " << salary << endl;
		cout << "���� ������ �� ������: ";
		hire_date.printDate();

		cout << "���������: ";
		switch (emp_position) {
		case LABORATORY_ASSISTANT:
			cout << "��������\n";
			break;
		case SECRETARY:
			cout << "���������\n";
			break;
		case MANAGER:
			cout << "��������\n";
			break;
		}
	}

	void addEmployee(int num) {

		setId(num);

		float salary;
		string check;
		do {
			check = "";
			cout << endl << "������� ����� ����������: ";
			cin >> check;
		} while (!isFloat(check));
		salary = stof(check);
		setSalary(salary);

		int day;
		string check_input;
		do {
			check_input = "";
			cout << "������� ����: ";
			cin >> check_input;
		} while (!isDigit(check_input) || stoi(check_input) <= 0 || stoi(check_input) > 30);
		day = stoi(check_input);
		hire_date.setDay(day);

		int month;
		do {
			check_input = "";
			cout << "������� �����: ";
			cin >> check_input;
		} while (!isDigit(check_input) || stoi(check_input) <= 0 || stoi(check_input) > 12);
		month = stoi(check_input);
		hire_date.setMonth(month);

		int year;
		do {
			check_input = "";
			cout << "������� ���: ";
			cin >> check_input;
		} while (!isDigit(check_input) || stoi(check_input) < 2000 || stoi(check_input) > 2023);
		year = stoi(check_input);
		hire_date.setYear(year);

		int choice;
		
		do {
			cout << "�������� ���������: " << endl;
			cout << "1. ��������; " << endl;
			cout << "2. ���������; " << endl;
			cout << "3. ��������; " << endl;
			check_input = "";
			cin >> check_input;
		} while (!isDigit(check_input) || stoi(check_input) <= 0 || stoi(check_input) > 3);
		 choice = stoi(check_input);

		switch (choice)
		{
		case 1:
			emp_position = LABORATORY_ASSISTANT;
			break;
		case 2:
			emp_position = SECRETARY;
			break;
		case 3:
			emp_position = MANAGER;
			break;
		}


	}
};

employee* employees;

int num_of_employees = 0;


int main() {

	while (true) {
		int choice;
		cout << endl << endl << "��������: " << endl << endl;
		cout << "1. ������ ���������� � �����������; " << endl;
		cout << "2. ������� ���������� � ����������; " << endl;
		cout << "3. �������� �����������; " << endl;
		cout << "4. �����. " << endl << endl;

		string check_input;
		cin >> check_input;
		if (isDigit(check_input)) choice = stoi(check_input);

		switch (choice)
		{
		case 1:
			printEmployees(num_of_employees); 
			break;
		case 2:
			printEmployee();
			break;
		case 3:
			addEmployee();
			break;
		case 4: 
			exit(1); 
			break;
		default:
			cout << "���������  ��������� ����������.";
		}
	}
	return 0;
}



void printEmployees( int numEmployees) {
	if (num_of_employees == 0) {
		cout << endl << "�� ��� �� ����� �� ������ ����������!" << endl;
		return;
	}
	for (int i = 0; i < numEmployees; i++) {
		employees[i].printEmployee();
		cout << endl;
	}
}

void printEmployee() {
	if (num_of_employees == 0) {
		cout << endl << "�� ��� �� ����� �� ������ ����������!" << endl;
		return;
	}
	int num;
	string check_input;

	do {
		check_input = "";
		cout << "������� ����� ����������: ";
		cin >> check_input;
	} while (!isDigit(check_input) || stoi(check_input) -1 > num_of_employees);
	num = stoi(check_input) - 1;
	employees[num].printEmployee();
}

void addEmployee() {

	int add;
	string check_input;
	do {
		check_input = "";
		cout << "������� ����������� ������ ��������? ";
		cin >> check_input;
	} while (!isDigit(check_input));

	add = stoi(check_input);
	employee* new_employees = new employee[num_of_employees + add];
	for (int i = 0; i < num_of_employees; i++) {
		new_employees[i] = employees[i];
	}
	for (int i = num_of_employees; i < num_of_employees + add; i++) {
		new_employees[i].addEmployee(i - num_of_employees);
	}
	delete[] employees;
	employees = new_employees;
	num_of_employees += add;
	addToFile();
}

void addToFile() {
	fstream file(FILE_EMPLOYEES);
	if (file.is_open()) {
		for (int i = 0; i < num_of_employees; i++) {
			file << employees[i].getId() << " "
				<< employees[i].getSalary() << " "
				<< employees[i].getPosition() << " "
				<< employees[i].getHireDay() << " "
				<< employees[i].getHireMonth() << " "
				<< employees[i].getHireYear() <<endl;
		}

		file.close();
	}
	else {
		cout << "������ �������� ����� " << FILE_EMPLOYEES << endl;
	}
}


bool isDigit(string text) {
	for (int i = 0; text[i] != '\0'; ++i) {
		if (text[i] == '0' || text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4'
			|| text[i] == '5' || text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9') {
			return true;
		}
	}
	return false;
}

bool isFloat(std::string str) {
	try {
		size_t pos;
		float num = std::stof(str, &pos);
		// ���� pos ����� ����� ������, �� ������ ��������� ������������� � ����� ���� float.
		// ���������� true.
		return pos == str.length();
	}
	catch (...) {
		// � ������ ������ �������������� (��������, ���� ������ �� �������� ������),
		// ���������� false.
		return false;
	}
}