#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>

struct Employee {
    std::wstring lastName;
    std::wstring firstName;
    std::wstring middleName;
    std::wstring salary;
    std::wstring rating;
    std::wstring specialization;
    std::wstring education;
};

void printTable(const std::vector<Employee>& employees) {
    const int width = 15;
    const char separator = '|';
    const char fill = '-';
    const std::wstring line(width * 7 + 6, fill);

    std::wcout << separator << std::internal <<  std::setw(width)  << "Фамилия"
        << separator << std::internal << std::setw(width) << "Имя"
        << separator << std::internal << std::setw(width) << "Отчество"
        << separator << std::internal << std::setw(width) << "Зарплата"
        << separator << std::internal << std::setw(width) << "Рейтинг"
        << separator << std::internal << std::setw(width) << "Специализация"
        << separator << std::internal << std::setw(width) << "Образование"
        << separator << std::endl;
    std::wcout << line << std::endl;

    for (const auto& employee : employees) {
        std::wcout << std::internal << std::setw(width) << separator << employee.lastName
            << std::internal << std::setw(width) << separator << employee.firstName
            << std::internal << std::setw(width) << separator << employee.middleName
            << std::internal << std::setw(width) << separator << employee.salary
            << std::internal << std::setw(width) << separator << employee.rating
            << std::internal << std::setw(width) << separator << employee.specialization
            << std::internal << std::setw(width) << separator << employee.education
            << separator << std::endl;
        std::wcout << line << std::endl;
    }
}

int wmain() {

    system("chcp 65001");


    std::vector<Employee> employees{
        {L"Иванов", L"Иван", L"Иванович", L"50000.0", L"7", L"Программист", L"Высшее"},
        {L"Петров", L"Петр", L"Петрович", L"40000.0", L"5", L"Дизайнер", L"Среднее"},
        {L"Сидоров", L"Сидор", L"Сидорович", L"60000.0", L"9", L"Менеджер", L"Высшее"}
    };

    printTable(employees);

    return 0;
}
