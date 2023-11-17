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
    std::cout.setf(std::ios::left);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << std::setw(5) << bookID << " | "
        << std::setw(30) << title << " | "
        << std::setw(30) << author << " | "
        << std::setw(10) << price << std::endl;

    if (std::cout.eof()) {
        std::cerr << "Error: End of file reached during output." << std::endl;
    }
    else if (std::cout.fail()) {
        std::cerr << "Error: Output operation failed." << std::endl;
    }
    else if (std::cout.bad()) {
        std::cerr << "Error: Fatal output error." << std::endl;
    }

    std::cout.unsetf(std::ios::left);
    std::cout.unsetf(std::ios::fixed);
}

void Book::WriteBookToFile(ofstream& outfile) {
    outfile.setf(std::ios::left);
    outfile.setf(std::ios::fixed);
    outfile.precision(2);

    outfile << std::setw(5) << bookID << " | "
        << std::setw(30) << title << " | "
        << std::setw(30) << author << " | "
        << std::setw(10) << price << std::endl;

    if (outfile.eof()) {
        std::cerr << "Error: End of file reached during output." << std::endl;
    }
    else if (outfile.fail()) {
        std::cerr << "Error: Output operation failed." << std::endl;
    }
    else if (outfile.bad()) {
        std::cerr << "Error: Fatal output error." << std::endl;
    }

    outfile.unsetf(std::ios::left);
    outfile.unsetf(std::ios::fixed);
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
    std::cout.setf(std::ios::left);
    std::cout << std::left << std::setw(5) << "ID" << " | "
        << std::left << std::setw(30) << "Title" << " | "
        << std::left << std::setw(30) << "Author" << " | "
        << std::left << std::setw(10) << "Price (BYN)" << std::endl;
    for (const Book* book : books) {
        book->DisplayInfo();
    }
    std::cout.unsetf(std::ios::left);

    if (std::cout.eof()) {
        std::cerr << "Error: End of file reached during output." << std::endl;
    }
    else if (std::cout.fail()) {
        std::cerr << "Error: Output operation failed." << std::endl;
    }
    else if (std::cout.bad()) {
        std::cerr << "Error: Fatal output error." << std::endl;
    }
}

std::vector<Book*>& Category::GetBooks() {
    return books;
}

//Order methods
int Order::orderCount = 0;
Order::Order() : totalAmount(0) {
    ++orderCount;
    orderID = orderCount;
}


void Order::AddBook(Book& book) {
    items.push_back(book);
    totalAmount += book.GetPrice();
}

void Order::DisplayOrder() const {
    std::cout << "\n" << "Order " << orderID << " Contents:" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << " | "
        << std::left << std::setw(30) << "Title" << " | "
        << std::left << std::setw(30) << "Author" << " | "
        << std::left << std::setw(10) << "Price (BYN)" << std::endl;
    for (const Book& book : items) {
        book.DisplayInfo();
    }
    std::cout << "Total Amount: " << totalAmount << " BYN" << std::endl;
}


void Order::WriteOrderToFile(std::ofstream& outfile) {
        outfile << "\n" << "Order " << orderID << " Contents:" << std::endl;
        outfile << std::left << std::setw(5) << "ID" << " | "
            << std::left << std::setw(30) << "Title" << " | "
            << std::left << std::setw(30) << "Author" << " | "
            << std::left << std::setw(10) << "Price (BYN)" << std::endl;
        for (Book book : items) {
            book.WriteBookToFile(outfile);
        }
        outfile << "Total Amount: " << totalAmount << " BYN" << std::endl;
}

int Order::GetOrderCount() { return orderCount; }
int Order::GetOrderID() { return orderID; }
int Order::GetCountOfBooks() { return items.size(); }

float Order::GetTotalAmount() { return this->totalAmount; };

vector<Book> Order::GetOrderBooks() { return items; }


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

Order& BookStore::GetOrderByID(int id) {
    for (Order* order : orders) {
        if (order->GetOrderID() == id) {
            return *order;
        }
    }
    throw OrderNotFoundException();
}

int BookStore::GetOrderPosition(Order& order) {
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i] == &order) {
            return i;
        }
    }
    return -1;
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
    ofstream outfile(ORDERSFILENAME, ios::app);
    if (outfile.is_open()) {
        newOrder->WriteOrderToFile(outfile);
        outfile.close();
    }
}

void BookStore::DeleteOrder() {
    int orderID;
    std::cout << "Enter the order number: " << std::endl;
    orderID = GetIntNumber();
    try {
        Order& order = GetOrderByID(orderID);
        int orderPosition = GetOrderPosition(order);
        if (orderPosition != -1) {
            orders.erase(orders.begin() + orderPosition);

            ofstream outfile(ORDERSFILENAME);
            if (outfile.is_open()) {
                for (Order* ord : orders) {
                    ord->WriteOrderToFile(outfile);
                }
                outfile.close();
            }

            std::cout << "You have successfully deleted order number: "
                << orderID << std::endl;
        }
        else {
            throw OrderNotFoundException();
        }
    }
    catch (const OrderNotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void BookStore::ChangeOrder() {
    int orderID;
    std::cout << "Enter the order number: " << std::endl;
    orderID = GetIntNumber();
    try {
        Order& order = GetOrderByID(orderID);
        int orderPosition = GetOrderPosition(order);
        if (orderPosition != -1) {
            orders.erase(orders.begin() + orderPosition);

            ofstream outfile(ORDERSFILENAME);
            if (outfile.is_open()) {
                for (Order* ord : orders) {
                    ord->WriteOrderToFile(outfile);
                }
                outfile.close();
            }

            PlaceOrder();
            cout << "You have successfully changed order" << endl;
        }
        else throw OrderNotFoundException();
    }
    catch (const OrderNotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void BookStore::ShowOrders() {
    std::string fileData;
    std::ifstream readfile(ORDERSFILENAME, std::ios::in);
    if (readfile.is_open()) {
        std::string line;
        while (std::getline(readfile, line)) {
            fileData += line + "\n";
        }
        readfile.close();

        std::cout << fileData << std::endl;
    }
    if (fileData == "") {
        std::cout << "You have no orders yet" << std::endl;
    }
}

void BookStore::FindOrder() {
    std::ifstream readFile(ORDERSFILENAME, std::ios::in);
    std::string line;
    bool found = false;

    int orderID;
    std::cout << "Enter the order number: " << std::endl;
    orderID = GetIntNumber();
    Order order = GetOrderByID(orderID);
    std::string searchString = "Order " + std::to_string(orderID) + " Contents:";
    std::string orderInfo;

    try {
        while (getline(readFile, line)) {
            if (line.find(searchString) != std::string::npos) {
                found = true;
                std::cout << "\nFound order with number " << orderID << ":\n";
            }
            if (found) {
                for (int i = 0; i < order.GetCountOfBooks() + 2; i++) {
                    if (getline(readFile, line)) {
                        orderInfo += line + "\n";
                    }
                }
                std::cout << orderInfo << std::endl;
                break;
            }
        }

        if (!found) {
            throw OrderNotFoundException();
        }
    }
    catch (const OrderNotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
