#include "libs.h"
#include "InputChecks.h"
#include "classes.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        BookStore myBookstore("My Bookstore");

        Category fiction("�������������� ����������");
        fiction.AddBook(new Book("����� � ���", "��� �������", 85.50));
        fiction.AddBook(new Book("������������ � ���������", "����� �����������", 45.25));
        fiction.AddBook(new Book("������ � ���������", "������ ��������", 32.00));
        fiction.AddBook(new Book("1984", "������ ������", 20.50));
        fiction.AddBook(new Book("��� ��������", "���� ����� ������", 38.75));

        Category nonFiction("������-���������� ����������");
        nonFiction.AddBook(new Book("������� ������� �������", "������ ������", 28.75));
        nonFiction.AddBook(new Book("������� � ��� �������", "���� ���", 95.00));
        nonFiction.AddBook(new Book("������: ������� �������", "���� �����", 42.30));
        nonFiction.AddBook(new Book("�������� ��������", "���� �������", 55.90));

        Category biography("��������� � �������");
        biography.AddBook(new Book("���� �����: ���������", "������ ��������", 42.75));
        biography.AddBook(new Book("��� �������", "����� ����������", 18.90));

        myBookstore.AddCategory(&fiction);
        myBookstore.AddCategory(&nonFiction);
        myBookstore.AddCategory(&biography);


        int choice = 0;

        while (true) {
            cout << "\nMenu options" << endl;
            cout << "1 - Place an order" << endl;
            cout << "2 - Show orders" << endl;
            cout << "3 - Find an order" << endl;
            cout << "4 - Delete an order" << endl;
            cout << "5 - Change an order" << endl;
            cout << "6 - Sort orders by price" << endl;
            cout << "7 - Sort books by price" << endl;
            cout << "0 - Exit" << endl;
            cout << "Choose an action: ";
            choice = GetIntNumber();

            switch (choice) {
            case 1: {
                myBookstore.PlaceOrder();
                break;
            }
            case 2: {
                myBookstore.ShowOrders();
                break;
            }
            case 3: {
                myBookstore.FindOrder();
                break;
            }
            case 4: {
                myBookstore.DeleteOrder();
                break;
            }
            case 5: {
                myBookstore.ChangeOrder();
                break;
            }
            case 6: {
                myBookstore.SortOrdersByPrice();
                break;
            }
            case 7: {
                myBookstore.SortBooksByPrice();
                break;
            }
            case 0: {
                std::cout << "Exiting the bookstore. Goodbye!" << std::endl;
                return 0;
            }
            default: {
                std::cerr << "Invalid choice. Please choose a valid option." << std::endl;
                break;
            }
            }
        }
    }
    catch (exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }


    return 0;
}