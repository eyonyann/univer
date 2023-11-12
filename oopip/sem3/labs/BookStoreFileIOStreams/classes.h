#pragma once

#include "libs.h"


class BookNotFoundException : public std::exception {
public:
    BookNotFoundException();
    const char* what() const noexcept override;
private:
    std::string message;
};

class OrderNotFoundException : public std::exception {
public:
    OrderNotFoundException();
    const char* what() const noexcept override;
private:
    std::string message;
};

class OrderWithoutBooksException : public std::exception {
public:
    OrderWithoutBooksException();
    const char* what() const noexcept override;
private:
    std::string message;
};

class OutOfMemoryException : public std::exception {
public:
    OutOfMemoryException();
    const char* what() const noexcept override;
private:
    std::string message;
};

class MaxOrdersReachedException : public std::exception {
public:
    MaxOrdersReachedException();
    const char* what() const noexcept override;
private:
    std::string message;
};





class Book {
public:
    Book();
    Book(const std::string& title, const std::string& author, double price);

    ~Book();

    void DisplayInfo() const;
    std::string GetTitle();
    std::string GetAuthor();
    double GetPrice();
    int GetBookCount();
    int GetBookID();
    void SetTitle(std::string title);
    void SetAuthor(std::string author);
    void SetPrice(double price);

private:
    static int bookCount;
    int bookID;
    std::string title;
    std::string author;
    double price;
};

class Category {
public:
    Category(const std::string& name);

    void AddBook(Book* book);
    void DisplayBooks() const;
    std::vector<Book*>& GetBooks();

private:
    std::string name;
    std::vector<Book*> books;
};

class Order {
public:
    Order();
    void AddBook(Book& book);
    void DisplayOrder() const;
    int GetOrderCount();
    int GetOrderID();
    double GetTotalAmount();
    vector<Book> GetOrderBooks();

private:
    static int orderCount;
    int orderID;
    std::vector<Book> items;
    double totalAmount;
};

class BookStore {
public:
    BookStore(const std::string& name);

    void AddCategory(Category* category);
    Book GetBookByID(int id);
    Order& GetOrderByID(int id);
    int GetOrderPosition(Order& order);

    void DisplayCategories();
    void PlaceOrder();
    void PlaceOrderToFile(Order& newOrder);
    void ShowOrders();
    void FindOrder();
    void DeleteOrder();
    void ChangeOrder();
    void SortOrdersByPrice();
    void SortBooksByPrice();

private:
    std::vector<Order*> orders;
    std::string name;
    std::vector<Category*> categories;
};
