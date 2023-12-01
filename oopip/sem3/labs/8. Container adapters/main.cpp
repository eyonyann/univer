#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <vector>
#include <Windows.h>

class BankEmployee {
public:
    std::string name;
    int employeeID;

    BankEmployee(std::string n, int id) : name(n), employeeID(id) {}

    bool operator<(const BankEmployee& other) const {
        return employeeID < other.employeeID;
    }
};


class Bank {
private:
    std::queue<BankEmployee> employeeQueue;
    std::stack<BankEmployee> employeeStack;
    std::priority_queue<BankEmployee> employeePriorityQueue;

public:
    void addEmployee(const BankEmployee& employee) {
        employeeQueue.push(employee);
        employeeStack.push(employee);
        employeePriorityQueue.push(employee);
    }

    void removeEmployee() {
        if (!employeeQueue.empty()) {
            employeeQueue.pop();
        }

        if (!employeeStack.empty()) {
            employeeStack.pop();
        }

        if (!employeePriorityQueue.empty()) {
            employeePriorityQueue.pop();
        }
    }

    void displayEmployees() const {
        std::cout << "\nEmployees in the queue:" << std::endl;
        std::cout << std::setw(20) << "Employee Name" << std::setw(15) << "Employee ID" << std::endl;
        std::cout << std::setw(35) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
        std::queue<BankEmployee> tempQueue = employeeQueue;
        while (!tempQueue.empty()) {
            std::cout << std::setw(20) << tempQueue.front().name << std::setw(15) << tempQueue.front().employeeID << std::endl;
            tempQueue.pop();
        }

        std::cout << "\nEmployees in the stack:" << std::endl;
        std::cout << std::setw(20) << "Employee Name" << std::setw(15) << "Employee ID" << std::endl;
        std::cout << std::setw(35) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
        std::stack<BankEmployee> tempStack = employeeStack;
        while (!tempStack.empty()) {
            std::cout << std::setw(20) << tempStack.top().name << std::setw(15) << tempStack.top().employeeID << std::endl;
            tempStack.pop();
        }

        std::cout << "\nEmployees in the priority queue:" << std::endl;
        std::cout << std::setw(20) << "Employee Name" << std::setw(15) << "Employee ID" << std::endl;
        std::cout << std::setw(35) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
        std::priority_queue<BankEmployee> tempPriorityQueue = employeePriorityQueue;
        while (!tempPriorityQueue.empty()) {
            std::cout << std::setw(20) << tempPriorityQueue.top().name << std::setw(15) << tempPriorityQueue.top().employeeID << std::endl;
            tempPriorityQueue.pop();
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Bank bank;

    while (true) {
        std::cout << "\nBank Employee Management System\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Remove Employee\n";
        std::cout << "3. Display Employees\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name;
            int id;
            std::cout << "Enter employee name: ";
            std::cin >> name;
            std::cout << "Enter employee ID: ";
            std::cin >> id;
            bank.addEmployee(BankEmployee(name, id));
            break;
        }
        case 2:
            bank.removeEmployee();
            std::cout << "Employee removed.\n";
            break;
        case 3:
            bank.displayEmployees();
            break;
        case 4:
            std::cout << "Exiting program.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
