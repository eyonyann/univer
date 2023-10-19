#include "libs.h"

template <typename T>
class SmartPointer {
public:
    SmartPointer(T* ptr = nullptr);
    SmartPointer(const SmartPointer& other);
    ~SmartPointer();

    SmartPointer& operator=(const SmartPointer& other);
    bool operator==(const SmartPointer<T>& other) const;
    bool operator!=(const SmartPointer<T>& other) const;

    T* operator->() const;
    T& operator*() const;

private:
    T* pointer;
    size_t* refCount;

    void release();
};

class Employee {
public:
    Employee();
    Employee(const string& name, int employeeID);
    Employee(const Employee& other); // Конструктор копирования
    ~Employee(); // Деструктор

    string getName() const;
    void setName(const string& name);
    int getEmployeeID() const;

    void runMenu();

private:
    static int count;
    int employeeID;
    string name;
    
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
    Transaction(SmartPointer<Document<string>> document);
    ~Transaction(); // Деструктор

    void commit();

    void rollback();

private:
    SmartPointer<Document<string>> document;
    string previousContent; // Предыдущее состояние документа
    string previousTitle;
    bool committed; // Флаг, указывающий, были ли изменения зафиксированы
};

class DocumentManagement {
public:
    DocumentManagement();
    ~DocumentManagement(); // Деструктор

    SmartPointer<Document<string>> FindDocumentByID(int docId);
    void EditDocument(int docId);
    void DeleteDocument(int docId);
    SmartPointer<Document<string>> CreateDocument(const string& title, const string& content);
    void PrintDocument(SmartPointer<Document<string>> document);
    void PrintAllDocuments();

private:
    vector<SmartPointer<Document<string>>> documents;
};
