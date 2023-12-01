#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <Windows.h>

class BankEmployee {
public:
    std::string name;
    std::string position;
    double salary;

    BankEmployee(const std::string& n, const std::string& pos, double sal) : name(n), position(pos), salary(sal) {}

    void displayInfo() const {
        std::cout << "Name: " << name << "\tPosition: " << position << "\tSalary: " << salary << std::endl;
    }

    size_t hash() const {
        return std::hash<std::string>()(name) ^ std::hash<std::string>()(position) ^ std::hash<double>()(salary);
    }

    bool operator<(const BankEmployee& other) const {
        return name < other.name;
    }

    bool operator==(const BankEmployee& other) const {
        return name == other.name && position == other.position && salary == other.salary;
    }
};

namespace std {
    template <>
    struct hash<BankEmployee> {
        size_t operator()(const BankEmployee& employee) const {
            return employee.hash();
        }
    };
}

template<typename Container>
void displayContainer(const Container& container) {
    for (const auto& item : container) {
        item.second.displayInfo();
    }
}

template<typename Container>
void saveToFile(const Container& container, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& item : container) {
        file << item.first << "," << item.second.name << "," << item.second.position << "," << item.second.salary << "\n";
    }
    file.close();
}

template<typename Container>
void addEmployee(Container& container) {
    int id;
    std::string name, position;
    double salary;
    std::cout << "Enter employee ID: ";
    std::cin >> id;

    std::cout << "Enter employee name: ";
    std::cin >> name;

    std::cout << "Enter employee position: ";
    std::cin >> position;

    std::cout << "Enter employee salary: ";
    std::cin >> salary;

    container.emplace(id, BankEmployee(name, position, salary));
    std::cout << "Employee added successfully!\n";
}

template<typename Container>
void deleteEmployee(Container& container) {
    int id;
    std::cout << "Enter the ID of the employee to delete: ";
    std::cin >> id;

    auto it = container.find(id);

    if (it != container.end()) {
        container.erase(it);
        std::cout << "Employee deleted successfully!\n";
    }
    else {
        std::cout << "Employee not found!\n";
    }
}

template<typename Container>
void searchEmployee(const Container& container) {
    int id;
    std::cout << "Enter the ID of the employee to search: ";
    std::cin >> id;

    auto it = container.find(id);

    if (it != container.end()) {
        it->second.displayInfo();
    }
    else {
        std::cout << "Employee not found!\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::map<int, BankEmployee> employeeMap;
    std::set<BankEmployee> employeeSet;
    std::multimap<int, BankEmployee> employeeMultimap;
    std::multiset<BankEmployee> employeeMultiset;
    std::unordered_map<int, BankEmployee> employeeUnorderedMap;
    std::unordered_set<BankEmployee> employeeUnorderedSet;
    std::unordered_multimap<int, BankEmployee> employeeUnorderedMultimap;
    std::unordered_multiset<BankEmployee> employeeUnorderedMultiset;

    int choice;

    do {
        std::cout << "\n=== Bank Employee Management System ===\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Delete Employee\n";
        std::cout << "3. Display Employees\n";
        std::cout << "4. Save to File\n";
        std::cout << "5. Search Employee\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addEmployee(employeeMap);
            break;
        case 2:
            deleteEmployee(employeeMap);
            break;
        case 3:
            displayContainer(employeeMap);
            break;
        case 4:
            saveToFile(employeeMap, "employees.txt");
            std::cout << "Employees saved to file successfully!\n";
            break;
        case 5:
            searchEmployee(employeeMap);
            break;
        case 6:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
