#include "header.h"


Stack* top = nullptr;
int counter = 0;

void push(char c, int max_size) {
    if (counter == max_size)
    {
        cout << "stack overflow " << endl;
        printStack();
        return;
    }
    else
    {
        Stack* newElement = new Stack;
        newElement->data = c;
        newElement->next = top;
        top = newElement;
        counter++;
    }
}

void pop() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    Stack* toDelete = top;
    top = top->next;
    cout << "Deleted element: " << toDelete->data << endl;
    delete toDelete;
    counter--;
}

void printStack() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    else {
        cout << "Stack elements:" << endl;
        Stack* temp = top;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

char peek() {
    if (top == nullptr) return '\0';
    return top->data;
}
