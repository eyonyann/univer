#include "libs.h"
#include "classes.h"


int main()
{

    Employee* employee = new Employee("Nikita", 0);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    employee->runMenu();
    return 0;
}
