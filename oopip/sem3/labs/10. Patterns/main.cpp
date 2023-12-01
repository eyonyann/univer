#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

class Document {
public:
    virtual void display() const = 0;
    virtual ~Document() {}
};

class MeetingMinutes : public Document {
public:
    void display() const override {
        std::cout << "Meeting Minutes Document\n";
    }
};

class Report : public Document {
public:
    void display() const override {
        std::cout << "Report Document\n";
    }
};

class DocumentFactory {
public:
    virtual Document* createDocument() const = 0;
    virtual ~DocumentFactory() {}
};

class MeetingMinutesFactory : public DocumentFactory {
public:
    Document* createDocument() const override {
        return new MeetingMinutes();
    }
};

class ReportFactory : public DocumentFactory {
public:
    Document* createDocument() const override {
        return new Report();
    }
};

class DocumentManager {
private:
    std::vector<Document*> documents;

public:
    void addDocument(DocumentFactory* factory) {
        documents.push_back(factory->createDocument());
    }

    void displayAllDocuments() const {
        std::cout << std::left << std::setw(20) << "Document Type" << std::endl;
        std::cout << "-------------------\n";
        for (const auto& document : documents) {
            document->display();
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& document : documents) {
                document->display();
                outFile << std::endl;
            }
            outFile.close();
            std::cout << "Documents saved to file: " << filename << std::endl;
        }
        else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    ~DocumentManager() {
        for (auto& document : documents) {
            delete document;
        }
    }
};

void displayMenu() {
    std::cout << "==========================\n";
    std::cout << "1. Add Meeting Minutes\n";
    std::cout << "2. Add Report\n";
    std::cout << "3. Display All Documents\n";
    std::cout << "4. Save to File\n";
    std::cout << "5. Exit\n";
    std::cout << "==========================\n";
}

int getUserChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    while (std::cin.fail()) {
        std::cin.clear(); // clear input buffer to restore cin to a usable state
        std::cin.ignore(INT_MAX, '\n'); // ignore last input
        std::cout << "Invalid input. Please enter a number: ";
        std::cin >> choice;
    }
    return choice;
}

int main() {
    DocumentManager manager;

    int choice;
    do {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
        case 1:
            manager.addDocument(new MeetingMinutesFactory());
            std::cout << "Meeting Minutes added.\n";
            break;
        case 2:
            manager.addDocument(new ReportFactory());
            std::cout << "Report added.\n";
            break;
        case 3:
            manager.displayAllDocuments();
            break;
        case 4: {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            manager.saveToFile(filename);
            break;
        }
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
