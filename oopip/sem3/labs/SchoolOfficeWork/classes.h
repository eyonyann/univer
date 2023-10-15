#include "libs.h"

class Employee {
public:
    Employee(const string& name, int employeeID);
    Employee(const Employee& other); // ����������� �����������
    ~Employee(); // ����������

    string getName() const;
    void setName(const string& name);
    int getEmployeeID() const;
    void setEmployeeID(int employeeID);

    void runMenu();

private:
    string name;
    int employeeID;
};

template<typename T>
class Document {
public:
    Document();
    Document(const string& title, const T& content);
    Document(const Document& other); // ����������� �����������
    ~Document(); // ����������

    string getTitle() const;
    void setTitle(const string& title);
    T getContent() const;
    void setContent(const T& content);
    int getID() const; // ��������� ID ���������

private:
    static int count; // ����������� ���� ��� ������������ ���������� ��������� ����������
    int id; // ���������� ID ���������
    string title;
    T content;
};

class Transaction {
public:
    Transaction(Document<string>* document);
    ~Transaction(); // ����������

    // ����� ��� �������� ��������� � ���������
    void commit();

    // ����� ��� ������ ��������� � ���������
    void rollback();

private:
    Document<string>* document;
    string previousContent; // ���������� ��������� ���������
    bool committed; // ����, �����������, ���� �� ��������� �������������
};

class SmartPointer {
public:
    SmartPointer(Document<string>* ptr = nullptr);
    SmartPointer(const SmartPointer& other);
    ~SmartPointer();

    SmartPointer& operator=(const SmartPointer& other);

    Document<string>* operator->() const;
    Document<string>& operator*() const;

private:
    Document<string>* pointer;
    size_t* refCount;

    void release();
};

class DocumentManagement {
public:
    DocumentManagement();
    ~DocumentManagement(); // ����������

    Document<string>* FindDocumentByID(const int& docId);
    void EditDocument(const int& docId);
    void DeleteDocument(const int& docId);
    Document<string>* CreateDocument(const string& title, const string& content);

private:
    vector<Document<string>*> documents;
    vector<Employee*> employees;
};
