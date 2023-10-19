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
    Employee(const Employee& other);
    ~Employee();

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
    Document(const Document& other);
    ~Document(); 

    string getTitle() const;
    void setTitle(const string& title);
    T getContent() const;
    void setContent(const T& content);
    int getID() const; 

private:
    static int count;
    int id;
    string title;
    T content;
};

class Transaction {
public:
    Transaction(SmartPointer<Document<string>> document);
    ~Transaction();

    void commit();

    void rollback();

private:
    SmartPointer<Document<string>> document;
    string previousContent;
    string previousTitle;
    bool committed;
};

class DocumentManagement {
public:
    DocumentManagement();
    ~DocumentManagement();

    SmartPointer<Document<string>> FindDocumentByID(int docId);
    void EditDocument(int docId);
    void DeleteDocument(int docId);
    SmartPointer<Document<string>> CreateDocument(const string& title, const string& content);
    void PrintDocument(SmartPointer<Document<string>> document);
    void PrintAllDocuments();

private:
    vector<SmartPointer<Document<string>>> documents;
};
