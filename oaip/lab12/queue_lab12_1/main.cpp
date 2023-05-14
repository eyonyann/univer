#include <iostream>

using namespace std;

struct Queue {
    int front, rear, maxSize;
    char* elements;
};

void createQueue(Queue& q, int size) {
    q.front = 0;
    q.rear = -1;
    q.maxSize = size;
    q.elements = new char[size];
}

bool isFull(Queue& q) {
    return q.rear == q.maxSize - 1;
}

bool isEmpty(Queue& q) {
    return q.front == q.rear + 1;
}

void enqueue(Queue& q, char ch) {
    if (isFull(q)) {
        cout << "Queue is full!" << endl;
    }
    else {
        q.rear++;
        q.elements[q.rear] = ch;
    }
}

char dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
        return '\0';
    }
    else {
        char ch = q.elements[q.front];
        q.front++;
        return ch;
    }
}

void print(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Elements in the queue: ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.elements[i] << " ";
        }
        cout << endl;
    }
}

int checkInt(int a) {
    while (true) {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Check the input! It can contain only numbers!\n";
            continue;
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        if (cin.gcount() > 1) {
            cout << "Check the input! It can contain only numbers!\n";
            continue;
        }
        break;
    }
    return a;
}

int main() {

        int maxSize = 0;
        cout << "Enter the maximum size of the queue: ";
        maxSize = checkInt(maxSize);

        Queue q;
        createQueue(q, maxSize);

        char ch;
        int choice = 0;
        do {
            cout << "Queue Menu:" << endl;
            cout << "1. Enqueue" << endl;
            cout << "2. Dequeue" << endl;
            cout << "3. Print" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            choice = checkInt(choice);

            switch (choice) {
            case 1:
                cout << "Enter a character to enqueue: ";
                cin >> ch;
                enqueue(q, ch);
                break;
            case 2:
                ch = dequeue(q);
                if (ch != '\0') {
                    cout << "Dequeued element: " << ch << endl;
                }
                break;
            case 3:
                print(q);
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
                break;
            }
        } while (choice != 4);

        delete[] q.elements;

        return 0;
    }