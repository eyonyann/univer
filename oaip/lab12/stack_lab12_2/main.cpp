#include "header.h"

int main() {
    int n = 0;
    char x, ch, el, check;
    int max_size;
    cout << "Enter max size of stack: ";
    cin >> max_size;

    do
    {
        cout << "Enter element of stack: " << endl;
        cin >> ch;

        if (peek() == ch) {
            pop();
            printStack();
        }
        else{
            push(ch, max_size);
        }
    } while (true);

    return 0;
}