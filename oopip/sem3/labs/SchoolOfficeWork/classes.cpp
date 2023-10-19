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
        cout << "\n����:" << endl;
        cout << "1. ������� ��������" << endl;
        cout << "2. �������� ��������" << endl;
        cout << "3. ���������� ���������" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. �����" << endl;
        cout << "�������� ��������: ";
        choice = GetIntNumber();

        switch (choice) {
        case 1:
        {
            string title, content;
            cout << "������� ��������� ���������: ";
            cin.ignore();
            getline(cin, title);
            cout << "������� ���������� ���������: ";
            getline(cin, content);

            SmartPointer<Document<string>> newDocument = documentManager.CreateDocument(title, content);
            cout << "�������� ������ � ID: " << newDocument->getID() << endl;
        }
        break;
        case 2:
        {
            int docID;
            cout << "������� ID ���������, ������� ����� ��������: ";
            docID = GetIntNumber();
            documentManager.EditDocument(docID);
        }
        break;
        case 3:
            cout << "\n��� ���� ���������: \n";
            documentManager.PrintAllDocuments();
            break;
        case 4:
        {
            int docID;
            cout << "������� ID ���������, ������� ����� �������: ";
            docID = GetIntNumber();
            documentManager.DeleteDocument(docID);
        }
        break;
        case 5:
            cout << "����� �� ���������." << endl;
            return;
        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
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
        std::cout << "������� ����� ��������� ���������: ";
        getline(std::cin, newTitle);
        std::cout << "������� ����� ���������� ���������: ";
        getline(std::cin, newContent);


        document->setTitle(newTitle);
        document->setContent(newContent);

        char confirm;
        std::cout << "��������� ��������� (y/n)? ";
        std::cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            transaction.commit();
            std::cout << "��������� ���������." << std::endl;
        }
        else {
            transaction.rollback();
            std::cout << "��������� ������������." << std::endl;
        }
    }
    else {
        std::cout << "�������� � ��������� ID �� ������." << std::endl;
    }
}

void DocumentManagement::DeleteDocument(int docId) {
    SmartPointer<Document<string>> document = FindDocumentByID(docId);


    if (document != nullptr) {
        Transaction transaction(document);

        char confirm;
        PrintDocument(FindDocumentByID(docId));
        cout << "\n�� ����� ������ ������� ���� ��������?\n";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            documents.erase(remove(documents.begin(), documents.end(), document), documents.end());
            transaction.commit();
            std::cout << "�������� ������." << std::endl;
        }
        else {
            transaction.rollback();
            std::cout << "�������� �� ������." << std::endl;
        }
        
    }
    else {
        std::cout << "\n�������� � ID " << docId << " �� ������.\n" << std::endl;
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
        cout << "\n� ��� ���� ��� �� ������ ���������\n";
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
