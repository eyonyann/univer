#include "header.h"

int main() {
    const int MAX_TEACHERS = 100;
    Person** teachers = new Person * [MAX_TEACHERS];
    int numTeachers = 0;

    ofstream outFile("teachers.txt", ios::app);

    int choice = 0;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add University Teacher" << endl;
        cout << "2. Add Commission Teacher" << endl;
        cout << "3. Add Commission Member" << endl;
        cout << "4. Show Teachers" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        choice = checkInt(choice);

        switch (choice) {
        case 1: {
            string name, birthDate, position, academicDegree, specialization;
            int numScientificWorks = 0;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter birth date: ";
            cin >> birthDate;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter academic degree: ";
            cin >> academicDegree;
            cout << "Enter specialization: ";
            cin >> specialization;
            cout << "Enter the number of scientific works: ";
            numScientificWorks = checkInt(numScientificWorks);

            string* scientificWorks = new string[numScientificWorks];
            cout << "Enter scientific works:" << endl;
            for (int i = 0; i < numScientificWorks; i++) {
                cout << "Scientific work " << i + 1 << ": ";
                cin >> scientificWorks[i];
            }

            teachers[numTeachers] = new UniversityTeacher(name, birthDate, position, academicDegree, specialization, scientificWorks, numScientificWorks);
            numTeachers++;

            delete[] scientificWorks;
            break;
        }
        case 2: {
            string name, birthDate, position, academicDegree, specialization;
            int numScientificWorks = 0, numCommissionWorks = 0;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter birth date: ";
            cin >> birthDate;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter academic degree: ";
            cin >> academicDegree;
            cout << "Enter specialization: ";
            cin >> specialization;
            cout << "Enter the number of scientific works: ";
            numScientificWorks = checkInt(numScientificWorks);

            string* scientificWorks = new string[numScientificWorks];
            cout << "Enter scientific works:" << endl;
            for (int i = 0; i < numScientificWorks; i++) {
                cout << "Scientific work " << i + 1 << ": ";
                cin >> scientificWorks[i];
            }

            cout << "Enter the number of commission works: ";
            numCommissionWorks = checkInt(numCommissionWorks);

            string* commissionWorks = new string[numCommissionWorks];
            cout << "Enter commission works:" << endl;
            for (int i = 0; i < numCommissionWorks; i++) {
                cout << "Commission work " << i + 1 << ": ";
                cin >> commissionWorks[i];
            }

            teachers[numTeachers] = new CommissionTeacher(name, birthDate, position, academicDegree, specialization, scientificWorks, numScientificWorks, commissionWorks, numCommissionWorks);
            numTeachers++;

            delete[] scientificWorks;
            delete[] commissionWorks;
            break;
        }
        case 3: {
            string name, birthDate, commissionName;
            int appointmentYear = 0;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter birth date: ";
            cin >> birthDate;
            cout << "Enter commission name: ";
            cin >> commissionName;
            cout << "Enter appointment year: ";
            appointmentYear = checkInt(appointmentYear);

            teachers[numTeachers] = new CommissionMember(name, birthDate, commissionName, appointmentYear);
            numTeachers++;
            break;
        }
        case 4: {
            if (numTeachers == 0) {
                cout << "No teachers to show." << endl;
            }
            else {
                for (int i = 0; i < numTeachers; i++) {
                    if (teachers[i]->isUniversityTeacher()) {
                        teachers[i]->printDetails(cout);
                    }
                }

            }
            break;
        }
        case 5:
        {
            break;
        }

        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    } while (choice != 5);

    for (int i = 0; i < numTeachers; i++) {
        if (teachers[i]->isUniversityTeacher()) {
            teachers[i]->printDetails(outFile);
        }

    }
    for (int i = 0; i < numTeachers; i++) {
        delete teachers[i];
    }
    delete[] teachers;

    return 0;
}