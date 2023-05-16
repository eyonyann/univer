#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int checkInt(int a);

class Person {
private:
    string name;
    string birthDate;

public:
    Person(const string& name, const string& birthDate)
        : name(name), birthDate(birthDate) {}
    string getName() const {
        return name;
    }

    string getBirthDate() const {
        return birthDate;
    }

    virtual bool isUniversityTeacher() const {
        return false;
    }

    virtual void printDetails(ostream& out) const = 0;
    virtual void printDetails(ofstream& outFile) const = 0;
};

class UniversityTeacher : public Person {
private:
    string position;
    string academicDegree;
    string specialization;
    string* scientificWorks;
    int numScientificWorks;

public:
    UniversityTeacher(const string& name, const string& birthDate,
        const string& position, const string& academicDegree,
        const string& specialization,
        const string* scientificWorks, int numScientificWorks)
        : Person(name, birthDate), position(position), academicDegree(academicDegree),
        specialization(specialization), scientificWorks(new string[numScientificWorks]),
        numScientificWorks(numScientificWorks) {
        for (int i = 0; i < numScientificWorks; i++) {
            this->scientificWorks[i] = scientificWorks[i];
        }
    }

    ~UniversityTeacher() {
        delete[] scientificWorks;
    }

    string getPosition() const {
        return position;
    }

    string getAcademicDegree() const {
        return academicDegree;
    }

    string getSpecialization() const {
        return specialization;
    }

    string* getScientificWorks() const {
        return scientificWorks;
    }

    int getNumScientificWorks() const {
        return numScientificWorks;
    }

    bool isUniversityTeacher() const override {
        return true;
    }

    void printDetails(ostream& out) const override {
        if (!getAcademicDegree().empty()) {
            out << "Name: " << getName() << endl;
            out << "Position: " << getPosition() << endl;
            out << "Academic Degree: " << getAcademicDegree() << endl;
            out << "Specialization: " << getSpecialization() << endl;
            out << "Scientific Works:" << endl;
            string* scientificWorks = getScientificWorks();
            int numScientificWorks = getNumScientificWorks();
            for (int j = 0; j < numScientificWorks; j++) {
                out << "- " << scientificWorks[j] << endl;
            }
            out << "------------------------------" << endl;
        }
    }

    void printDetails(ofstream& outFile) const override {
        if (!getAcademicDegree().empty()) {
            outFile << "Name: " << getName() << endl;
            outFile << "Position: " << getPosition() << endl;
            outFile << "Academic Degree: " << getAcademicDegree() << endl;
            outFile << "Specialization: " << getSpecialization() << endl;
            outFile << "Scientific Works:" << endl;
            string* scientificWorks = getScientificWorks();
            int numScientificWorks = getNumScientificWorks();
            for (int j = 0; j < numScientificWorks; j++) {
                outFile << "- " << scientificWorks[j] << endl;
            }
            outFile << "------------------------------" << endl;
        }
    }
};

class CommissionMember : public Person {
private:
    string commissionName;
    int appointmentYear;

public:
    CommissionMember(const string& name, const string& birthDate, const string& commissionName, int appointmentYear)
        : Person(name, birthDate), commissionName(commissionName), appointmentYear(appointmentYear) {}
    string getCommissionName() const {
        return commissionName;
    }

    int getAppointmentYear() const {
        return appointmentYear;
    }

    void printDetails(ostream& out) const override {
        out << "Name: " << getName() << endl;
        out << "Commission Name: " << getCommissionName() << endl;
        out << "Appointment Year: " << getAppointmentYear() << endl;
        out << "------------------------------" << endl;
    }

    void printDetails(ofstream& outFile) const override {
        outFile << "Name: " << getName() << endl;
        outFile << "Commission Name: " << getCommissionName() << endl;
        outFile << "Appointment Year: " << getAppointmentYear() << endl;
        outFile << "------------------------------" << endl;
    }
};

class CommissionTeacher : public UniversityTeacher {
private:
    string* commissionWorks;
    int numCommissionWorks;

public:
    CommissionTeacher(const string& name, const string& birthDate,
        const string& position, const string& academicDegree,
        const string& specialization,
        const string* scientificWorks, int numScientificWorks,
        const string* commissionWorks, int numCommissionWorks) :
        UniversityTeacher(name, birthDate, position, academicDegree, specialization, scientificWorks, numScientificWorks),
        commissionWorks(new string[numCommissionWorks]), numCommissionWorks(numCommissionWorks) {
        for (int i = 0; i < numCommissionWorks; i++) {
            this->commissionWorks[i] = commissionWorks[i];
        }
    }
    ~CommissionTeacher() {
        delete[] commissionWorks;
    }

    string* getCommissionWorks() const {
        return commissionWorks;
    }

    int getNumCommissionWorks() const {
        return numCommissionWorks;
    }

    void printDetails(ostream& out) const override {
        UniversityTeacher::printDetails(out);
        out << "Commission Works:" << endl;
        string* commissionWorks = getCommissionWorks();
        int numCommissionWorks = getNumCommissionWorks();
        for (int j = 0; j < numCommissionWorks; j++) {
            out << "- " << commissionWorks[j] << endl;
        }
        out << "------------------------------" << endl;
    }

    void printDetails(ofstream& outFile) const override {
        UniversityTeacher::printDetails(outFile);
        outFile << "Commission Works:" << endl;
        string* commissionWorks = getCommissionWorks();
        int numCommissionWorks = getNumCommissionWorks();
        for (int j = 0; j < numCommissionWorks; j++) {
            outFile << "- " << commissionWorks[j] << endl;
        }
        outFile << "------------------------------" << endl << endl;
    }
};