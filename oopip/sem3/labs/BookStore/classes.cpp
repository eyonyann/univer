#include "libs.h"
#include "InputChecks.h"
#include "classes.h"

//BookNotFoundException methods
BookNotFoundException::BookNotFoundException() 
    : message("Book with the specified ID was not found.") {}

const char* BookNotFoundException::what() const noexcept { return message.c_str(); }

//OrderNotFoundException methods
OrderNotFoundException::OrderNotFoundException()
    : message("Book with the specified ID was not found.") {}

const char* OrderNotFoundException::what() const noexcept { return message.c_str(); }

//OrderWithoutBooksException methods
OrderWithoutBooksException::OrderWithoutBooksException() 
    : message("The order does not contain any books.") {}

const char* OrderWithoutBooksException::what() const noexcept { return message.c_str(); }

//OutOfMemoryException methods
OutOfMemoryException::OutOfMemoryException() : message("Out of memory!") {}

const char* OutOfMemoryException::what() const noexcept { return message.c_str(); }

//MaxOrdersReachedException methods
MaxOrdersReachedException::MaxOrdersReachedException()
    : message("The maximum number of orders has been reached") {}

const char* MaxOrdersReachedException::what() const noexcept { return message.c_str(); }

//Book methods
int Book::bookCount = 0;

Book::Book() {
    title = "";
    author = "";
    price = 0;
    ++bookCount;
    bookID = bookCount;
}
Book::Book(const std::string& title, const std::string& author, double price)
    : title(title), author(author), price(price) {
    ++bookCount;
    bookID = bookCount;
}

Book::~Book() {}

void Book::DisplayInfo() const {
    std::cout << std::left << std::setw(5) << bookID << " | "
        << std::left << std::setw(30) << title << " | "
        << std::left << std::setw(30) << author << " | "
        << std::left << std::setw(10) << price << std::endl;
}

std::string Book::GetTitle() { return title; }
std::string Book::GetAuthor() { return author; }
double Book::GetPrice() { return price; }
int Book::GetBookCount() { return bookCount; }
int Book::GetBookID() { return bookID; }

void Book::SetTitle(std::string title) { this->title = title; }
void Book::SetAuthor(std::string author) { this->author = author; }
void Book::SetPrice(double price) { this->price = price; }

//Category methods
Category::Category(const std::string& name) : name(name) {}

void Category::AddBook(Book* book) {
    books.push_back(book);
}

void Category::DisplayBooks() const {
    std::cout << "Category: " << name << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << " | "
        << std::left << std::setw(30) << "Title" << " | "
        << std::left << std::setw(30) << "Author" << " | "
        << std::left << std::setw(10) << "Price (BYN)" << std::endl;
    for (const Book* book : books) {
        book->DisplayInfo();
    }
}

const std::vector<Book*>& Category::GetBooks() const {
    return books;
}

//Order methods
int Order::orderCount = 0;
Order::Order() : totalAmount(0) {
    if (orderCount >= MAX_ORDERS) {
        throw MaxOrdersReachedException();
    }
    ++orderCount;
    orderID = orderCount; 
}

Order::~Order() {
    std::cout << "Order " << orderID << " destroyed." << std::endl;
}

void Order::AddBook(Book& book) {
    items.push_back(book);
    totalAmount += book.GetPrice();
}

void Order::DisplayOrder() const {
    std::cout << "Order " << orderID << " Contents:" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << " | "
        << std::left << std::setw(30) << "Title" << " | "
        << std::left << std::setw(30) << "Author" << " | "
        << std::left << std::setw(10) << "Price (BYN)" << std::endl;
    for (const Book& book : items) {
        book.DisplayInfo();
    }
    std::cout << "Total Amount: " << totalAmount << " BYN" << std::endl;
}

int Order::GetOrderCount() { return orderCount; }
int Order::GetOrderID() { return orderID; }

//BookStore methods
BookStore::BookStore(const std::string& name) : name(name) {}

void BookStore::AddCategory(Category* category) {
    categories.push_back(category);
}

Book BookStore::GetBookByID(int id) {
    for (Category* category : categories) {
        for (Book* book : category->GetBooks()) {
            if (book->GetBookID() == id) {
                return *book;
            }
        }
    }
    throw BookNotFoundException();
}

Order BookStore::GetOrderByID(int id) {
    for (Order* order : orders) {
        if (order->GetOrderID() == id) {
            return *order;
        }
    }
    throw OrderNotFoundException();
}

void BookStore::DisplayCategories() {
    for (const Category* category : categories) {
        category->DisplayBooks();
    }
}

void BookStore::PlaceOrder() {
    Order* newOrder = nullptr;
    bool isMax = false;

    try {
        newOrder = new Order();
    }
    catch (const std::bad_alloc& e) {
        if (newOrder != nullptr) {
            delete newOrder;
        }
        throw OutOfMemoryException();
    }
    catch (const MaxOrdersReachedException& e) {
        cout << "Error: " << e.what() << endl;
        isMax = true;
    }

    if(!isMax) {
        bool hasBooks = false;

        while (true) {
            int bookID;
            std::string confirm;
            DisplayCategories();
            std::cout << "Enter the number of the book you'd like to add to your order: " << std::endl;
            bookID = GetIntNumber();
            Book book;

            try {
                book = GetBookByID(bookID);
            }
            catch (const BookNotFoundException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                continue;
            }

            newOrder->AddBook(book);
            hasBooks = true;

            std::cout << "Do you want to add another book? (y/n) " << std::endl;
            std::cin >> confirm;
            if (!GetBoolAnswer(confirm)) {
                if (!hasBooks) {
                    delete newOrder;
                    throw OrderWithoutBooksException();
                }
                orders.push_back(newOrder);
                std::cout << "Your order with number " << newOrder->GetOrderID() << " has been successfully placed!" << std::endl;
                break;
            }
        }
    }
}




void BookStore::ShowOrders() {
    for (int i = 0; i < orders.size(); i++) {
        orders[i]->DisplayOrder();
    }
}

void BookStore::FindOrder() {
    int orderID;
    std::cout << "Enter the order number: " << std::endl;
    orderID = GetIntNumber();
    try {
        Order order = GetOrderByID(orderID);
        order.DisplayOrder();
    }
    catch (const OrderNotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
