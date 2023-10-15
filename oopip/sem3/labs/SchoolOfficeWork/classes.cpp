#include "classes.h"

//Employee
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

void Employee::setEmployeeID(int employeeID) {
    this->employeeID = employeeID;
}

void Employee::runMenu() {
    DocumentManagement documentManager;
    
    int choice;

    while (true) {
        cout << "����:" << endl;
        cout << "1. ������� ��������" << endl;
        cout << "2. �������� ��������" << endl;
        cout << "3. ���������� ���������" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            string title, content;
            cout << "������� ��������� ���������: ";
            cin.ignore();
            getline(cin, title);
            cout << "������� ���������� ���������: ";
            getline(cin, content);

            Document<string>* newDocument = documentManager.CreateDocument(title, content);
            cout << "�������� ������ � ID: " << newDocument->getID() << endl;
        }
        break;
        case 2:
        {
            int docID;
            cout << "������� ID ���������, ������� ����� ��������: ";
            cin >> docID;
            documentManager.EditDocument(docID);
        }
        break;
        case 3:
            
            break;
        case 4:
        {
            int docID;
            cout << "������� ID ���������, ������� ����� �������: ";
            cin >> docID;
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
Document<T>::Document(const Document& other) : title(other.title), content(other.content), id(other.id) {
    // �������������� ������ �����������, ���� ����������
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
Transaction::Transaction(Document<string>* document) : document(document), committed(false) {
    previousContent = document->getContent();
}

Transaction::~Transaction() {
    if (!committed) {
        document->setContent(previousContent);
    }
}

void Transaction::commit() {
    committed = true;
}

void Transaction::rollback() {
    if (!committed) {
        document->setContent(previousContent);
    }
}

//DocumentManagement
DocumentManagement::DocumentManagement() {
}

DocumentManagement::~DocumentManagement() {
}

Document<string>* DocumentManagement::CreateDocument(const string& title, const string& content) {
    Document<string>* document = new Document<string>(title, content);
    documents.push_back(document);
    return document;
}

Document<string>* DocumentManagement::FindDocumentByID(const int& docId) {
    bool found = false;
    for (int i = 0; i < documents.size(); i++)
    {
        if (documents[i]->getID() == docId)
        {
            found = true;
            return documents[i];
        }
    }
}

void DocumentManagement::EditDocument(const int& docId) {
    DocumentManagement documentManager;
    Document<string>* document = documentManager.FindDocumentByID(docId);

    if (document) {
        string newTitle, newContent;
        cout << "������� ����� ��������� ���������: ";
        cin.ignore();
        getline(cin, newTitle);
        cout << "������� ����� ���������� ���������: ";
        getline(cin, newContent);

        // ������� ���������� ��� ��������� ���������
        Transaction transaction(document);
        document->setTitle(newTitle);
        document->setContent(newContent);

        char confirm;
        cout << "��������� ��������� (y/n)? ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            transaction.commit();
            cout << "��������� ���������." << endl;
        }
        else {
            transaction.rollback();
            cout << "��������� ������������." << endl;
        }
    }
    else {
        cout << "�������� � ��������� ID �� ������." << endl;
    }
}

void DocumentManagement::DeleteDocument(const int& docId) {

}

//void DocumentManagement::assignEmployeeToDocument(Employee* employee, Document<string>* document) {
//    // ������ ���������� ���������� � ���������
//}
//
//void DocumentManagement::finalizeDocument(Document<string>* document) {
//    // ������ ���������� ������ � ����������
//}
//
//void DocumentManagement::rollbackDocument(Document<string>* document) {
//    // ������ ������ ��������� � ���������
//}


//SmartPointer
SmartPointer::SmartPointer(Document<string>* ptr) : pointer(ptr), refCount(new std::size_t(1)) {}

SmartPointer::SmartPointer(const SmartPointer& other) : pointer(other.pointer), refCount(other.refCount) {
    if (refCount) {
        ++(*refCount);
    }
}

SmartPointer::~SmartPointer() {
    release();
}

SmartPointer& SmartPointer::operator=(const SmartPointer& other) {
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

Document<string>* SmartPointer::operator->() const {
    return pointer;
}

Document<string>& SmartPointer::operator*() const {
    return *pointer;
}

void SmartPointer::release() {
    if (refCount && --(*refCount) == 0) {
        delete pointer;
        delete refCount;
    }
}
