#pragma once

#include <iostream>
using namespace std;

struct Stack {
    char data;
    Stack* next;
};

int checkInt(int a);
void push(char c, int max_size);
void pop();
void printStack();
char peek();