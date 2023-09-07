#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

string isDigit(string text);
int checkInt(int a);

class Log {
	int amount;
	string* id;
	string* password;
public:
	Log() {
		this->amount = 0;
		this->id = new string[1];
		this->password = new string[1];

		this->id[0] = "";
		this->password[0] = "";
	}

	Log(int amount) {
		this->amount = amount;
		this->id = new string[amount];
		this->password = new string[amount];

		for (int i = 0; i < amount; i++) {
			this->id[i] = "";
			this->password[i] = "";
		}
	}

	Log(const Log& other) {
		this->amount = other.amount;
		this->id = new string[other.amount];
		this->password = new string[other.amount];

		for (int i = 0; i < amount; i++) {
			this->id[i] = other.id[i];
			this->password[i] = other.password[i];
		}
	}

	~Log() {
		delete[]id;
		delete[]password;
	}




	void addData(int count) {

		string* newIdArray = new string[amount + count];
		string* newPasswordArray = new string[amount + count];

		for (int i = 0; i < amount; i++) {
			newIdArray[i] = this->id[i];
			newPasswordArray[i] = this->password[i];
		}

		delete[] this->id;
		delete[] this->password;

		this->id = newIdArray;
		this->password = newPasswordArray;

		this->amount += count;

		string newId, newPw;

		for (int i = amount - count; i < amount; i++) {
			newId = "";
			newPw = "";

			cout << "Введите id:";
			cin >> newId;
			cout << "Введите пароль: ";
			cin >> newPw;

			this->id[i] = newId;
			this->password[i] = newPw;
		}

		cout << "\nДанные введены успешно!\n";
	}

	friend ostream& operator<<(ostream& os, const Log& log) {
		os << "Количество записей: " << log.amount << endl;
		for (int i = 0; i < log.amount; i++) {
			os << "id: " << log.id[i] << ", password: " << log.password[i] << endl;
		}
		return os;
	}

	friend istream& operator>>(istream& is, Log& log) {
		cout << "Введите количество записй: ";
		is >> log.amount;
		//delete[] log.id;
		//delete[] log.password;
		//log.id = new std::string[log.amount];
		//log.password = new std::string[log.amount];

		for (int i = 0; i < log.amount; i++) {
			cout << "Введите id и пароль для входа в журнал " << i << ": ";
			is >> log.id[i] >> log.password[i];
		}

		return is;
	}

	void GetData() {

		cout << endl << "ID\t\tPW\n";
		for (int i = 0; i < this->GetAmount(); i++)
			cout << this->id[i] << "\t\t" << this->password[i] << endl;
	}


	Log& operator +(const Log& other) {
		string* tmp_id = new string[amount + other.amount];
		string* tmp_password = new string[amount + other.amount];

		for (int i = 0; i < amount; i++) {
			tmp_id[i] = id[i];
			tmp_password[i] = password[i];
		}

		for (int i = 0; i < other.amount; i++) {
			tmp_id[amount + i] = other.id[i];
			tmp_password[amount + i] = other.password[i];
		}

		amount += other.amount;

		delete[] id;
		delete[] password;

		id = tmp_id;
		password = tmp_password;

		return *this;
	}

	bool operator==(const Log& other) {
		if (amount != other.amount) {
			return false;
		}
		for (int i = 0; i < amount; i++) {
			if (id[i] != other.id[i] || password[i] != other.password[i]) {
				return false;
			}
		}
		return true;
	}

	void operator-(const Log& other) {
		Log diffLog(amount + other.amount); // создаем объект diffLog с тем же количеством элементов
		bool found = false;
		for (int i = 0; i < amount; i++) {
			found = false;
			for (int j = 0; j < other.amount; j++) {
				if (id[i] == other.id[j] && password[i] == other.password[j]) {
					found = true;
					break;
				}
				if (!found) {
					diffLog.id[i] = this->id[i]; // добавляем новый элемент в конец массива
					diffLog.password[i] = this->password[i];
				}
			}

		}
		cout << endl << "ID\t\tPW\n";
		for (int i = 0; i < diffLog.amount; i++)
			cout << diffLog.id[i] << "\t\t" << diffLog.password[i] << endl;
	}





	int GetAmount() {

		return this->amount;
	}

	string GetID(int num) {

		return this->id[num - 1];
	}

	string GetPW(int num) {

		return this->password[num - 1];
	}

	void SetAmount(int amount) {
		this->amount = amount;
	}

	void SetID(string id, int num) {
		this->id[num] = id;
	}

	void SetPW(string pw, int num) {
		this->id[num] = pw;
	}

};




int main() {

	Log log[2];
	Log loga(1);

	while (true) {
		char choice = 0;
		int count = 0, logNum = 0;
		cout << endl << endl << "Выбирите: " << endl << endl;
		cout << "1. Пополнить журнал; " << endl;
		cout << "2. Показать записи журнала; " << endl;
		cout << "3. Сравнить журналы; " << endl;
		cout << "4. Сложить журналы; " << endl;
		cout << "5. Отнять журналы; " << endl;
		cout << "6. Выйти. " << endl << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':

			cout << endl << "Выбирите 1 или 2 журнал: ";
			cin >> logNum;

			cout << endl << "В этом журнале " << log[logNum - 1].GetAmount() << " записей " << endl;
			cout << "Сколько еще записей вы хотите добавить? ";
			cin >> count;

			log[logNum - 1].addData(count);

			break;
		case '2':

			cout << endl << "Выбирите 1 или 2 журнал: ";
			cin >> logNum;
			cout << endl << "В этом журнале " << log[logNum - 1].GetAmount() << " записей " << endl;
			cout << log[logNum - 1];
			//log[logNum - 1].GetData();

			break;
		case '3':

			if (log[0] == log[1]) cout << "\nОни равны\n";
			else cout << "\nОни не равны\n";
			break;
		case '4':
			log[0] + log[1];
			break;
		case '5':
			log[0] - log[1];
			break;
		case '6':
			exit(1);
			break;
		default:
			cout << "Нет такого пункта!";
		}
	}
	return 0;
}

string isDigit(string text) {
	bool result = false;

	while (!result) {
		cin >> text;
		for (int i = 0; text[i] != '\0'; ++i) {
			if (text[i] == '0' || text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4'
				|| text[i] == '5' || text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9') {
				result = true;
				return text;
			}
		}
		result = false;

	}
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