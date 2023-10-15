#include "libs.h"

class Employee {
public:
    Employee(const string& name, int employeeID);
    Employee(const Employee& other); // Конструктор копирования
    ~Employee(); // Деструктор

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
    Document(const Document& other); // Конструктор копирования
    ~Document(); // Деструктор

    string getTitle() const;
    void setTitle(const string& title);
    T getContent() const;
    void setContent(const T& content);
    int getID() const; // Получение ID документа

private:
    static int count; // Статическое поле для отслеживания количества созданных документов
    int id; // Уникальный ID документа
    string title;
    T content;
};

class Transaction {
public:
    Transaction(Document<string>* document);
    ~Transaction(); // Деструктор

    // Метод для фиксации изменений в документе
    void commit();

    // Метод для отката изменений в документе
    void rollback();

private:
    Document<string>* document;
    string previousContent; // Предыдущее состояние документа
    bool committed; // Флаг, указывающий, были ли изменения зафиксированы
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
    ~DocumentManagement(); // Деструктор

    Document<string>* FindDocumentByID(const int& docId);
    void EditDocument(const int& docId);
    void DeleteDocument(const int& docId);
    Document<string>* CreateDocument(const string& title, const string& content);

private:
    vector<Document<string>*> documents;
    vector<Employee*> employees;
};
