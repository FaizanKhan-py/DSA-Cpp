#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int size;
    int top;

public:
    Stack(int capacity) {
        size = capacity;
        arr = new T[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    T peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return T();
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    Stack<int> s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.display();

    cout << "Top element: " << s.peek() << "\n";

    s.pop();
    cout << "After pop: ";
    s.display();

    return 0;
}