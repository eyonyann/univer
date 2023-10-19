#include "classes.h"
#include "libs.h"
#include "InputChecks.h"


//Employee
int Employee::count = 0;

Employee::Employee() :  name("") {
    ++count;
    employeeID = count;
}

Employee::Employee(const std::string& name, int employeeID) : name(name), employeeID(employeeID) {

}

Employee::Employee(const Employee& other) : name(other.name), employeeID(other.employeeID) {

}

Employee::~Employee() {

}

string Employee::getName() const {
    return name;
}

void Employee::setName(const string& name) {
    this->name = name;
}

int Employee::getEmployeeID() const {
    return employeeID;
}

void Employee::runMenu() {
    DocumentManagement documentManager;
    
    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Create document" << endl;
        cout << "2. Edit document" << endl;
        cout << "3. View documents" << endl;
        cout << "4. Delete document" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an action: ";

        choice = GetIntNumber();

        switch (choice) {
        case 1:
        {
            string title, content;
            cout << "Enter the document title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the document content: ";
            getline(cin, content);

            SmartPointer<Document<string>> newDocument = documentManager.CreateDocument(title, content);
            cout << "Document created with ID: " << newDocument->getID() << endl;

        }
        break;
        case 2:
        {
            int docID;
            cout << "Enter the ID of the document to edit: ";
            docID = GetIntNumber();
            documentManager.EditDocument(docID);
        }
        break;
        case 3:
            cout << "\nHere are your documents: \n";
            documentManager.PrintAllDocuments();
            break;
        case 4:
        {
            int docID;
            cout << "Enter the ID of the document to delete: ";
            docID = GetIntNumber();
            documentManager.DeleteDocument(docID);
        }
        break;
        case 5:
            cout << "Exiting the program." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    }
}

//Document

template<typename T>
int Document<T>::count = 0;

template<typename T>
Document<T>::Document() : title(""), content(0) {
    ++count;
    id = count;
}

template<typename T>
Document<T>::Document(const string& title, const T& content) : title(title), content(content) {
    ++count;
    id = count;
}

template<typename T>
Document<T>::Document(const Document& other) : title(other.title), content(other.content) {
    ++count;
    id = count;
}

template<typename T>
Document<T>::~Document() {
}

template<typename T>
string Document<T>::getTitle() const {
    return title;
}

template<typename T>
void Document<T>::setTitle(const std::string& title) {
    this->title = title;
}


template<typename T>
T Document<T>::getContent() const {
    return content;
}

template<typename T>
void Document<T>::setContent(const T& content) {
    this->content = content;
}

template<typename T>
int Document<T>::getID() const {
    return id;
}

//Transaction
Transaction::Transaction(SmartPointer<Document<string>> document) : document(document), committed(false) {
    previousContent = document->getContent();
    previousTitle = document->getTitle();
}

Transaction::~Transaction() {
    if (!committed) {
        document->setContent(previousContent);
        document->setTitle(previousTitle);
    }
}

void Transaction::commit() {
    committed = true;
}

void Transaction::rollback() {
    if (!committed) {
        document->setContent(previousContent);
        document->setTitle(previousTitle);
    }
}

//DocumentManagement
DocumentManagement::DocumentManagement() {
}

DocumentManagement::~DocumentManagement() {
}

SmartPointer<Document<string>> DocumentManagement::CreateDocument(const string& title, const string& content) {
    SmartPointer<Document<string>> document(new Document<string>(title, content));
    documents.push_back(document);
    return document;
}


SmartPointer<Document<string>> DocumentManagement::FindDocumentByID(int docId) {
    for (int i = 0; i < documents.size(); i++) {
        if (documents[i]->getID() == docId) {
            return SmartPointer<Document<string>>(documents[i]);
        }
    }
    return SmartPointer<Document<string>>();
}

void DocumentManagement::EditDocument(int docId) {
    SmartPointer<Document<string>> document = FindDocumentByID(docId);

    if (document != nullptr) {
        Transaction transaction(document);

        string newTitle, newContent;
        std::cin.ignore();
        std::cout << "Enter the new document title: ";
        getline(std::cin, newTitle);
        std::cout << "Enter the new document content: ";
        getline(std::cin, newContent);

        document->setTitle(newTitle);
        document->setContent(newContent);

        char confirm;
        std::cout << "Save changes (y/n)? ";
        std::cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            transaction.commit();
            std::cout << "Changes saved." << std::endl;
        }
        else {
            transaction.rollback();
            std::cout << "Changes rolled back." << std::endl;
        }
    }

    else {
        cout << "Document with the specified ID was not found." << endl;
    }
}

void DocumentManagement::DeleteDocument(int docId) {
    SmartPointer<Document<string>> document = FindDocumentByID(docId);

    if (document != nullptr) {
        Transaction transaction(document);

        char confirm;
        PrintDocument(FindDocumentByID(docId));
        cout << "\nAre you sure you want to delete this document?\n";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            documents.erase(remove(documents.begin(), documents.end(), document), documents.end());
            transaction.commit();
            std::cout << "Document deleted." << std::endl;
        }
        else {
            transaction.rollback();
            std::cout << "Document not deleted." << std::endl;
        }
    }
    else {
        std::cout << "\nDocument with ID " << docId << " not found.\n" << std::endl;
    }
}


void DocumentManagement::PrintDocument(SmartPointer<Document<string>> document)  {
    std::cout << "\nDocument ID: " << document->getID() << std::endl;
    std::cout << "Title: " << document->getTitle() << std::endl;
    std::cout << "Content: " << document->getContent() << std::endl << endl;
}

void DocumentManagement::PrintAllDocuments() {
    if (documents.size() == 0)
    {
        cout << "\nYou don't have any documents yet.\n";
    } 
    else {
        for (int i = 0; i < documents.size(); i++) {
            PrintDocument(documents[i]);
        }
    }
}


//SmartPointer
template <typename T>
SmartPointer<T>::SmartPointer(T* ptr) : pointer(ptr), refCount(new std::size_t(1)) {}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& other) : pointer(other.pointer), refCount(other.refCount) {
    if (refCount) {
        ++(*refCount);
    }
}

template <typename T>
SmartPointer<T>::~SmartPointer() {
    release();
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& other) {
    if (this != &other) {
        release();
        pointer = other.pointer;
        refCount = other.refCount;
        if (refCount) {
            ++(*refCount);
        }
    }
    return *this;
}

template <typename T>
T* SmartPointer<T>::operator->() const {
    return pointer;
}

template <typename T>
T& SmartPointer<T>::operator*() const {
    return *pointer;
}

template <typename T>
bool SmartPointer<T>::operator==(const SmartPointer<T>& other) const {
    return this->pointer == other.pointer;
}

template <typename T>
bool SmartPointer<T>::operator!=(const SmartPointer<T>& other) const {
    return this->pointer != other.pointer;
}

template <typename T>
void SmartPointer<T>::release() {
    if (refCount && --(*refCount) == 0) {
        delete pointer;
        delete refCount;
    }
}
