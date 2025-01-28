#include <iostream>
using namespace std;

#define MAX 100

int top = -1;
int stack[MAX];

void push(int x) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        stack[++top] = x;
    }
}

void pop() {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << stack[top--] << endl;
    }
}

int peek() {
    if (top < 0) {
        cout << "Stack is Empty" << endl;
        return -1;
    } else {
        return stack[top];
    }
}

bool isEmpty() {
    return top < 0;
}

int main() {
    push(10);
    push(20);
    push(30);
    cout << peek() << endl;
    pop();
    cout << peek() << endl;
    pop();
    cout << peek() << endl;
    pop();
    cout << peek() << endl;
    pop();
    return 0;
}