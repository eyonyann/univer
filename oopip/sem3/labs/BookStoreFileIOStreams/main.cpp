#include "libs.h"
#include "InputChecks.h"
#include "classes.h"

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

    ofstream outfile(ORDERSFILENAME);
    if (outfile.is_open()) {
        outfile.close();
    }

    try {
        BookStore myBookstore("My Bookstore");

        Category fiction("Художественная литература");
        fiction.AddBook(new Book("Война и мир", "Лев Толстой", 85.50));
        fiction.AddBook(new Book("Преступление и наказание", "Федор Достоевский", 45.25));
        fiction.AddBook(new Book("Мастер и Маргарита", "Михаил Булгаков", 32.00));
        fiction.AddBook(new Book("1984", "Джордж Оруэлл", 20.50));
        fiction.AddBook(new Book("Три товарища", "Эрих Мария Ремарк", 38.75));

        Category nonFiction("Научно-популярная литература");
        nonFiction.AddBook(new Book("Краткая история времени", "Стивен Хокинг", 28.75));
        nonFiction.AddBook(new Book("Человек и его символы", "Карл Юнг", 95.00));
        nonFiction.AddBook(new Book("Космос: Частная история", "Карл Саган", 42.30));
        nonFiction.AddBook(new Book("Биология человека", "Джон Джонсон", 55.90));

        Category biography("Биографии и мемуары");
        biography.AddBook(new Book("Стив Джобс: Биография", "Уолтер Айзексон", 42.75));
        biography.AddBook(new Book("Мой дедушка", "Артур Шопенгауэр", 18.90));

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