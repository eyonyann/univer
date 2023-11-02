#include "libs.h"
#include "InputChecks.h"
#include "classes.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
        const int maxOrders = 10;

        while (true) {
            cout << "\nMenu Options" << endl;
            cout << "1 - Place an Order" << endl;
            cout << "2 - Show Orders" << endl;
            cout << "3 - Find an Order" << endl;
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