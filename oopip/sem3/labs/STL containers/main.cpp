#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#define GAMESFILENAME "files\\games.txt"

using namespace std;




class Game {
protected:
    string title;
    string company;
    int year;

public:
    Game() {}
    Game(string title, string company, int year)
    {
        this->title = title;
        this->company = company;
        this->year = year;
    }
    ~Game() {}
    string getTitle() const {
        return title;
    }
    void setTitle(string newTitle) {
        title = newTitle;
    }
    string getCompany() const {
        return company;
    }
    void setCompany(string company) {
        this->company = company;
    }
    int getYear() const {
        return year;
    }
    void setYear(int newYear) {
        year = newYear;
    }
    void displayGame()
    {
        cout << "\n��������: " << title << endl;
        cout << "��������: " << company << endl;
        cout << "���: " << year << endl;
    }
};

class RaceGame : public Game {
protected:
    string raceType;
public:
    RaceGame() : Game("", "", 0), raceType("") {}
    RaceGame(string title, string company, int year, string raceType) :Game(title, company, year)
    {
        this->raceType = raceType;
    }
    string getRaceType() const {
        return raceType;
    }
    void setRaceType(string raceType) {
        this->raceType = raceType;
    }
    ~RaceGame() {}
    void displayRace()
    {
        cout << "\n���� ��� �����" << endl;
        Game::displayGame();
        cout << "��� �����: " << raceType << endl;
    }
};

class ShooterGame : public Game {
protected:
    string shooterType;
public:
    ShooterGame() : Game("", "", 0), shooterType("") {}
    ShooterGame(string title, string company, int year, string shooterType) :Game(title, company, year)
    {
        this->shooterType = shooterType;
    }
    string getShooterType() const {
        return shooterType;
    }
    void setCrime(string newCrime) {
        this->shooterType = shooterType;
    }
    ~ShooterGame() {}
    void displayShooter()
    {
        cout << "\n������" << endl;
        Game::displayGame();
        cout << "��� ������: " << shooterType << endl;
    }
};

class FantasyGame : public Game {
protected:
    string worldName;
public:
    FantasyGame() : Game("", "", 0), worldName("") {}
    FantasyGame(string title, string author, int year, string worldName) :Game(title, company, year)
    {
        this->worldName = worldName;
    }
    string getName() const {
        return worldName;
    }
    void setName(string worldName) {
        worldName = worldName;
    }
    ~FantasyGame() {}
    void displayFantasy()
    {
        cout << "\n����������" << endl;
        Game::displayGame();
        cout << "�������� ����: " << worldName << endl;
    }
};

class MyException : public exception {
public:
    const char* what() const throw() {
        return "������: ������������ ���������� ��� ���� ����������!";
    }
};

class MyExceptionComputer : public exception
{
public:
    const char* what() const throw() {
        return "��� ���!";
    }
};


void termFunc()
{
    cout << "��������� ����������� ������� ����������\n";
    exit(-1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const wchar_t* directoryPath = L"files";

    if (!CreateDirectory(directoryPath, NULL)) {
        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            std::wcout << L"Directory 'files' already exists.\n";
        }
        else {
            std::cerr << "Error creating directory 'files'.\n";
        }
    }
    else {
        std::wcout << L"Directory 'files' created successfully.\n";
    }

    ofstream outfile(GAMESFILENAME);
    if (outfile.is_open()) {
        outfile.close();
    }

    RaceGame* race = NULL;
    std::vector<RaceGame*> raceGames;
    int current_race = 0;
    ShooterGame* shooter = NULL;
    std::list<ShooterGame*> shooterGames;
    int current_shooter = 0;
    FantasyGame* fantasy = NULL;
    std::array<FantasyGame*, 5> fantasyGames;
    int current_fantasy = 0;
    int choice;
    do {
        try {
            cout << "\n���� ������" << endl;
            cout << "1 - �������� ����" << endl;
            cout << "2 - �������� ���" << endl;
            cout << "3 - ����� ����" << endl;
            cout << "4 - ������� ����" << endl;
            cout << "5 - �������� ����" << endl;
            cout << "6 - ����������� ����" << endl;
            cout << "7 - ��������� � ����" << endl;
            cout << "0 - �����" << endl;

            while (true) {
                cout << "�������� ��������: ";
                cin >> choice;
                if (cin.good() && choice >= 0 && choice <= 7) {
                    break;
                }
                cin.clear();
                cout << "������������ ���� ������\n";
                cin.ignore(100, '\n');
            }

            switch (choice) {
            case 1: {
                system("cls");
                int choice1;
                do {
                    cout << "\n���� ������" << endl;
                    cout << "1 - �������� �����" << endl;
                    cout << "2 - �������� �����" << endl;
                    cout << "3 - �������� �������" << endl;
                    cout << "0 - �����" << endl;

                    while (true) {
                        cout << "�������� ��������: ";
                        cin >> choice1;
                        if (cin.good() && choice1 >= 0 && choice1 <= 3) {
                            break;
                        }
                        cin.clear();
                        cout << "������������ ���� ������\n";
                        cin.ignore(100, '\n');
                    }

                    switch (choice1) {
                    case 1: {
                        system("cls");
                        string title;
                        cout << "������� �������� ����" << endl;
                        cin >> title;
                        string company;
                        cout << "������� �������� ����" << endl;
                        cin >> company;
                        int year;
                        while (true) {
                            cout << "������� ��� �������" << endl;
                            cin >> year;
                            if (cin.good() && year >= 1000 && year <= 2023) {
                                break;
                            }
                            cin.clear();
                            cout << "������������ ���� ������\n";
                            cin.ignore(100, '\n');
                        }
                        string raceType;
                        cout << "������� ��� �����" << endl;
                        cin >> raceType;
                        race = new RaceGame(title, company, year, raceType);
                        raceGames.push_back(race);
                        current_race++;
                        cout << "���� ������� ���������" << endl;
                        vector<RaceGame*>::iterator i = raceGames.begin();
                        break;
                    }
                    case 2: {
                        system("cls");
                        string title;
                        cout << "������� �������� ����" << endl;
                        cin >> title;
                        string company;
                        cout << "������� �������� ����" << endl;
                        cin >> company;
                        int year;
                        while (true) {
                            cout << "������� ��� �������" << endl;
                            cin >> year;
                            if (cin.good() && year >= 1000 && year <= 2023) {
                                break;
                            }
                            cin.clear();
                            cout << "������������ ���� ������\n";
                            cin.ignore(100, '\n');
                        }
                        string shooterType;
                        cout << "������� ��� ������" << endl;
                        cin >> shooterType;
                        shooter = new ShooterGame(title, company, year, shooterType);
                        shooterGames.push_back(shooter);
                        cout << "���� ������� ���������" << endl;
                        current_shooter++;
                        break;
                    }
                    case 3: {
                        system("cls");
                        if (current_fantasy < 6)
                        {
                            string title;
                            cout << "������� �������� ����" << endl;
                            cin >> title;
                            string company;
                            cout << "������� �������� ����" << endl;
                            cin >> company;
                            int year;
                            while (true) {
                                cout << "������� ��� �������" << endl;
                                cin >> year;
                                if (cin.good() && year >= 1000 && year <= 2023) {
                                    break;
                                }
                                cin.clear();
                                cout << "������������ ���� ������\n";
                                cin.ignore(100, '\n');
                            }
                            string worldName;
                            cout << "������� �������� ����" << endl;
                            cin >> worldName;
                            fantasy = new FantasyGame(title, company, year, worldName);
                            fantasyGames[current_fantasy] = fantasy;
                            cout << "���� ������� ���������" << endl;
                            current_fantasy++;
                        }
                        cout << "\n";
                        break;
                    }
                    }
                } while (choice1 != 0);
                break;
            }
            case 2: {
                system("cls");
                if (current_race > 0)
                {
                    cout << "-------------------------------------------------------------------------------------\n";
                    cout << "|                                      �����                                         |\n";
                    cout << "-------------------------------------------------------------------------------------\n";
                    cout << '|' << setw(25) << left << "�������� ����" << '|' << setw(20) << "�������� " << '|' << setw(10) << "���" << '|' << setw(25) << "��� �����" << '|' << endl;
                    cout << "-------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < raceGames.size(); i++)
                    {
                        cout << '|' << setw(25) << left << raceGames[i]->getTitle() << '|' << setw(20)
                            << raceGames[i]->getCompany() << '|' << setw(10) << raceGames[i]->getYear() << "|" << setw(25) << raceGames[i]->getRaceType() << "|" << endl;
                        cout << "-------------------------------------------------------------------------------------\n";
                    }

                }
                else
                {
                    cout << "����������� �����" << endl;
                }
                std::cout << "\n";
                if (current_shooter > 0)
                {
                    cout << "-------------------------------------------------------------------------------------\n";
                    cout << "|                                     ������                                         |\n";
                    cout << "-------------------------------------------------------------------------------------\n";
                    cout << '|' << setw(25) << left << "�������� ����" << '|' << setw(20) << "�������� " << '|' << setw(10) << "���" << '|' << setw(25) << "��� ������" << '|' << endl;
                    cout << "-------------------------------------------------------------------------------------\n";
                    for (std::list<ShooterGame*>::iterator p = shooterGames.begin(); p != shooterGames.end(); ++p)
                    {
                        cout << '|' << setw(25) << left << (*p)->getTitle() << '|' << setw(20) << (*p)->getCompany() << '|' << setw(10) << (*p)->getYear() << "|" << setw(25) << (*p)->getShooterType() << "|" << endl;
                        cout << "-------------------------------------------------------------------------------------\n";
                    }

                }
                else
                {
                    cout << "���������� ������" << endl;
                }
                std::cout << "\n";
                if (current_fantasy > 0)
                {

                    cout << "-------------------------------------------------------------------------------------\n";
                    cout << "|                                      �������                                       |\n";
                    cout << "-------------------------------------------------------------------------------------\n";
                    cout << '|' << setw(25) << left << "�������� ����" << '|' << setw(20) << "�������� " << '|' << setw(10) << "���" << '|' << setw(25) << " �������� ����" << '|' << endl;
                    cout << "-------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < current_fantasy; i++)
                    {
                        cout << '|' << setw(25) << left << fantasyGames[i]->getTitle() << '|' << setw(20) << fantasyGames[i]->getCompany() << '|' << setw(10) << fantasyGames[i]->getYear() << "|" << setw(25) << fantasyGames[i]->getName() << "|" << endl;
                        cout << "-------------------------------------------------------------------------------------\n";
                        cout << "\n";

                    }
                }
                else
                {
                    cout << "���������� �������" << endl;
                }
                cout << "\n";

                break;
            }
            case 3: {
                system("cls");
                int choice1;
                do {
                    cout << "\n���� ������" << endl;
                    cout << "1 - ����� �����" << endl;
                    cout << "2 - ����� ������" << endl;
                    cout << "3 - ����� �������" << endl;
                    cout << "0 - �����" << endl;

                    while (true) {
                        cout << "�������� ��������: ";
                        cin >> choice1;
                        if (cin.good() && choice1 >= 0 && choice1 <= 3) {
                            break;
                        }
                        cin.clear();
                        cout << "������������ ���� ������\n";
                        cin.ignore(100, '\n');
                    }

                    switch (choice1) {
                    case 1: {
                        system("cls");
                        if (current_race > 0)
                        {
                            string title;
                            cout << "������� �������� ����:" << endl;
                            cin >> title;
                            for (std::vector<RaceGame*>::iterator i = raceGames.begin(); i != raceGames.end(); i++)
                            {
                                if ((*i)->getTitle() == title)
                                {
                                    cout << "��������� ����\n" << endl;
                                    (*i)->displayRace();

                                }
                                else { cout << "��� ����� ����"; }
                            }
                        }
                        else
                        {
                            cout << "��� ���" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 2: {
                        system("cls");
                        if (current_shooter > 0)
                        {
                            string title;
                            cout << "������� �������� ����:" << endl;
                            cin >> title;
                            for (std::list<ShooterGame*>::iterator i = shooterGames.begin(); i != shooterGames.end(); i++)
                            {
                                if ((*i)->getTitle() == title)
                                {
                                    cout << "��������� ����\n" << endl;
                                    (*i)->displayShooter();

                                }
                                else { cout << "��� ����� ����"; }
                            }
                        }
                        else
                        {
                            cout << "��� ���" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 3: {
                        system("cls");
                        if (current_fantasy > 0)
                        {
                            string title;
                            cout << "������� �������� ����:" << endl;
                            cin >> title;
                            for (std::array<FantasyGame*, 5>::iterator i = fantasyGames.begin(); i != fantasyGames.end(); i++)
                            {
                                if ((*i)->getTitle() == title)
                                {
                                    cout << "��������� ����\n" << endl;
                                    (*i)->displayFantasy();

                                }
                                else { cout << "��� ����� ����"; }
                            }
                        }
                        else
                        {
                            cout << "��� ���" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    }
                } while (choice1 != 0);
                break;
            }
            case 4: {
                system("cls");
                int choice1;
                do {
                    cout << "\n���� ������" << endl;
                    cout << "1 - ������� �����" << endl;
                    cout << "2 - ������� �����" << endl;
                    cout << "3 - ������� �������" << endl;
                    cout << "0 - �����" << endl;

                    while (true) {
                        cout << "�������� ��������: ";
                        cin >> choice1;
                        if (cin.good() && choice1 >= 0 && choice1 <= 3) {
                            break;
                        }
                        cin.clear();
                        cout << "������������ ���� ������\n";
                        cin.ignore(100, '\n');
                    }

                    switch (choice1) {
                    case 1: {
                        system("cls");
                        if (current_race > 0)
                        {
                            std::vector<RaceGame*>::const_iterator p = raceGames.cbegin();
                            while (p != raceGames.cend())
                            {
                                (*p)->displayRace();
                                p++;
                            }
                            cout << "\n";
                            string name_poi;
                            cout << "������� �������� ����, ������� ������ �������" << endl;
                            cin >> name_poi;
                            int x = 0;
                            int flag = 0;
                            for (std::vector<RaceGame*>::iterator i = raceGames.begin(); i != raceGames.end(); i++)
                            {
                                if ((*i)->getTitle() == name_poi)
                                {
                                    flag = 1;
                                    raceGames.erase(raceGames.begin() + x);
                                    cout << "���� �������" << endl;
                                    current_race;
                                    break;
                                }
                                x++;
                            }
                            if (flag == 0)
                            {
                                cout << "����� ���� ���" << endl;
                            }
                            std::vector<RaceGame*>::iterator i = raceGames.begin();

                        }
                        else
                        {
                            cout << "����������� �����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 2: {
                        system("cls");
                        if (current_shooter > 0)
                        {
                            std::list<ShooterGame*>::const_iterator p = shooterGames.cbegin();
                            while (p != shooterGames.cend())
                            {
                                (*p)->displayShooter();
                                p++;
                            }
                            cout << "\n";
                            string name_poi;
                            cout << "������� �������� ����, ������� �� ������ �������" << endl;
                            cin >> name_poi;
                            int x = 0;
                            int flag = 0;
                            for (std::list<ShooterGame*>::iterator i = shooterGames.begin(); i != shooterGames.end(); i++)
                            {
                                if ((*i)->getTitle() == name_poi)
                                {
                                    flag = 1;
                                    shooterGames.erase(i);
                                    cout << "���� �������" << endl;
                                    current_shooter--;
                                    break;
                                }
                                x++;
                            }
                            if (flag == 0)
                            {
                                cout << "����� ���� ���" << endl;
                            }
                        }
                        else
                        {
                            cout << "����������� ����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 3: {
                        system("cls");
                        if (current_fantasy > 0)
                        {
                            for (int i = 0; i < current_fantasy; i++)
                            {
                                fantasyGames[i]->displayFantasy();
                            }
                            cout << "\n";
                            string name_poi;
                            cout << "������� �������� ����, ������� ������ �������" << endl;
                            cin >> name_poi;
                            int x = 0;
                            for (int i = 0; i < current_fantasy; i)
                            {
                                if (fantasyGames[i]->getTitle() == name_poi)
                                {
                                    for (int j = i; j < current_fantasy; j)
                                    {
                                        fantasyGames[j] = fantasyGames[j + 1];
                                    }
                                    cout << "���� �������" << endl;
                                    current_fantasy--;
                                    x;
                                    break;
                                }
                            }
                            if (x == 0)
                            {
                                cout << "����� ���� ���" << endl;
                            }
                        }
                        else
                        {
                            cout << "����������� ����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    }
                } while (choice1 != 0);
                break;
            }
            case 5: {
                system("cls");
                int choice1;
                do {
                    cout << "\n���� ������" << endl;
                    cout << "1 - �������� �������� �����" << endl;
                    cout << "2 - �������� �������� ������" << endl;
                    cout << "3 - �������� �������� �������" << endl;
                    cout << "0 - �����" << endl;

                    while (true) {
                        cout << "�������� ��������: ";
                        cin >> choice1;
                        if (cin.good() && choice1 >= 0 && choice1 <= 3) {
                            break;
                        }
                        cin.clear();
                        cout << "������������ ���� ������\n";
                        cin.ignore(100, '\n');
                    }
                    switch (choice1) {
                    case 1: {
                        system("cls");
                        if (current_race > 0)
                        {
                            std::vector<RaceGame*>::const_iterator p = raceGames.cbegin();
                            while (p != raceGames.cend())
                            {
                                (*p)->displayRace();
                                p++;
                            }
                            string name_poi;
                            cout << "������� ��������, ������� ������ ��������:" << endl;
                            cin >> name_poi;
                            int poi = 0;
                            for (std::vector<RaceGame*>::iterator i = raceGames.begin(); i != raceGames.end(); i++)
                            {
                                if ((*i)->getTitle() == name_poi)
                                {
                                    poi = 1;
                                    std::string name_new;
                                    cout << "������� ����� �������� ����:" << endl;
                                    cin >> name_new;
                                    (*i)->setTitle(name_new);
                                    cout << "�������� ��������" << endl;
                                    break;
                                }
                            }
                            if (poi == 0)
                            {
                                cout << "����� ���� ���" << endl;
                            }
                            std::vector<RaceGame*>::iterator i = raceGames.begin();

                        }
                        else
                        {
                            cout << "����������� ����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 2: {
                        system("cls");
                        if (current_shooter > 0)
                        {
                            std::list<ShooterGame*>::const_iterator it = shooterGames.cbegin();
                            while (it != shooterGames.cend())
                            {
                                (*it)->displayShooter();
                                it++;
                            }
                            cout << "\n";
                            string name_poi;
                            cout << "������� �������� ����, ������� ������ ��������:" << endl;
                            cin >> name_poi;
                            int poi = 0;
                            for (std::list<ShooterGame*>::iterator i = shooterGames.begin(); i != shooterGames.end(); i++)
                            {
                                if ((*i)->getTitle() == name_poi)
                                {
                                    string name_new;
                                    poi = 1;
                                    cout << "������� ����� ��������" << endl;
                                    cin >> name_new;
                                    (*i)->setTitle(name_new);
                                    cout << "�������� ��������" << endl;
                                    break;
                                }
                            }
                            if (poi == 0)
                            {
                                cout << "����� ���� ���" << endl;
                            }
                        }
                        else
                        {
                            cout << "����������� ����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 3: {
                        system("cls");
                        if (current_fantasy > 0)
                        {
                            for (int i = 0; i < current_fantasy; i++)
                            {
                                fantasyGames[i]->displayFantasy();
                            }
                            cout << "\n";
                            string name_poi;
                            cout << "������� ��������, ������� ������ ��������:" << endl;
                            cin >> name_poi;
                            int poi = 0;
                            for (int i = 0; i < current_fantasy; i++)
                            {
                                if (fantasyGames[i]->getTitle() == name_poi)
                                {
                                    string name_new;
                                    poi = 1;
                                    cout << "������� ����� ��������:" << endl;
                                    cin >> name_new;
                                    fantasyGames[i]->setTitle(name_new);
                                    cout << "�������� ��������" << endl;
                                    break;
                                }
                            }
                            if (poi == 0)
                            {
                                cout << "����� ���� ���" << endl;
                            }

                        }
                        else
                        {
                            cout << "����������� ����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    }
                } while (choice1 != 0);
                break;
            }
            case 6: {
                system("cls");
                int choice1;
                do {
                    cout << "\n���� ������" << endl;
                    cout << "1 - ������������� ����� �� ��������" << endl;
                    cout << "2 - ������������� ������ �� ���� �������" << endl;
                    cout << "3 - ������������� ������� �� �������� ����" << endl;
                    cout << "0 - �����" << endl;

                    while (true) {
                        cout << "�������� ��������: ";
                        cin >> choice1;
                        if (cin.good() && choice1 >= 0 && choice1 <= 3) {
                            break;
                        }
                        cin.clear();
                        cout << "������������ ���� ������\n";
                        cin.ignore(100, '\n');
                    }

                    switch (choice1) {
                    case 1: {
                        system("cls");
                        if (current_race > 0)
                        {
                            std::list<std::string> sort;
                            for (std::vector<RaceGame*>::iterator it = raceGames.begin(); it != raceGames.end(); it++)
                            {
                                sort.push_back((*it)->getTitle());
                            }
                            sort.sort();
                            cout << "��������������� ������:" << endl;
                            for (std::list<std::string>::iterator it = sort.begin(); it != sort.end(); it++)
                            {
                                for (std::vector<RaceGame*>::iterator i = raceGames.begin(); i != raceGames.end(); i++)
                                {
                                    if ((*i)->getTitle() == *it)
                                    {
                                        (*i)->displayRace();
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "����������� ����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 2: {
                        system("cls");
                        if (current_shooter > 0)
                        {
                            std::list<int> sort;
                            for (std::list<ShooterGame*>::iterator it = shooterGames.begin(); it != shooterGames.end(); it++)
                            {
                                sort.push_back((*it)->getYear());
                            }

                            sort.sort();

                            cout << "��������������� ������:" << endl;
                            for (std::list<int>::iterator it = sort.begin(); it != sort.end(); it++)
                            {
                                for (std::list<ShooterGame*>::iterator i = shooterGames.begin(); i != shooterGames.end(); i++)
                                {
                                    if ((*i)->getYear() == *it)
                                    {
                                        (*i)->displayShooter();
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "����������� ������" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    case 3: {
                        system("cls");
                        if (current_fantasy > 0)
                        {
                            std::string* temporary = new std::string[current_fantasy];
                            for (int i = 0; i < current_fantasy; i++) {
                                temporary[i] = fantasyGames[i]->getName();
                            }
                            for (int i = 0; i < current_fantasy; i++) {
                                for (int j = current_fantasy - 1; j > i; j--) {
                                    if (temporary[j - 1] > temporary[j]) {
                                        swap(temporary[j - 1], temporary[j]);
                                    }
                                }
                            }
                            for (int i = 0; i < current_fantasy; i++) {
                                for (int j = 0; j < current_fantasy; j++)
                                {
                                    if (temporary[i] == fantasyGames[j]->getName())
                                    {
                                        fantasyGames[j]->displayFantasy();
                                    }
                                }
                            }
                        }
                        else
                        {
                            cout << "����������� ����" << endl;
                        }
                        cout << "\n";
                        break;
                    }
                    }
                } while (choice1 != 0);
                break;
            }
            case 7: {
                system("cls");
                std::ofstream File;
                File.open(GAMESFILENAME, std::ios::binary);
                if (File.is_open())
                {
                    File << "-------------------------------------------------------------------------------------\n";
                    File << "|                                      �����                                         |\n";
                    File << "-------------------------------------------------------------------------------------\n";
                    File << '|' << setw(25) << left << "�������� ����" << '|' << setw(20) << "�������� " << '|' << setw(10) << "���" << '|' << setw(25) << "��� �����" << '|' << endl;
                    File << "-------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < raceGames.size(); i++)
                    {
                        File << '|' << setw(25) << left << raceGames[i]->getTitle() << '|' << setw(20)
                            << raceGames[i]->getCompany() << '|' << setw(10) << raceGames[i]->getYear() << "|" << setw(25) << raceGames[i]->getRaceType() << "|" << endl;
                        File << "-------------------------------------------------------------------------------------\n";
                    }
                    File << "-------------------------------------------------------------------------------------\n";
                    File << "|                                     ������                                         |\n";
                    File << "-------------------------------------------------------------------------------------\n";
                    File << '|' << setw(25) << left << "�������� ����" << '|' << setw(20) << "�������� " << '|' << setw(10) << "���" << '|' << setw(25) << "��� ������" << '|' << endl;
                    File << "-------------------------------------------------------------------------------------\n";
                    for (std::list<ShooterGame*>::iterator p = shooterGames.begin(); p != shooterGames.end(); ++p)
                    {
                        File << '|' << setw(25) << left << (*p)->getTitle() << '|' << setw(20) << (*p)->getCompany() << '|' << setw(10) << (*p)->getYear() << "|" << setw(25) << (*p)->getShooterType() << "|" << endl;
                        File << "-------------------------------------------------------------------------------------\n";
                    }
                    File << "-------------------------------------------------------------------------------------\n";
                    File << "|                                      �������                                       |\n";
                    File << "-------------------------------------------------------------------------------------\n";
                    File << '|' << setw(25) << left << "�������� ����" << '|' << setw(20) << "�������� " << '|' << setw(10) << "���" << '|' << setw(25) << " �������� ����" << '|' << endl;
                    File << "-------------------------------------------------------------------------------------\n";
                    for (int i = 0; i < current_fantasy; i++)
                    {
                        File << '|' << setw(25) << left << fantasyGames[i]->getTitle() << '|' << setw(20) << fantasyGames[i]->getCompany() << '|' << setw(10) << fantasyGames[i]->getYear() << "|" << setw(25) << fantasyGames[i]->getName() << "|" << endl;
                        File << "-------------------------------------------------------------------------------------\n";
                        File << "\n";

                    }
                    std::cout << "������ ������� �������� � ����\n";
                }
                else std::cout << "������ �������� �����\n";
                File.close();
                break;
            }
            }
        }
        catch (invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (MyException& e) {
            cout << e.what() << endl;
        }
        catch (MyExceptionComputer& e) {
            cout << e.what() << endl;
        }
    } while (choice != 0);
    return 0;
}
