#include <iostream>
using namespace std;
class PriorityQueue {
private:
    int* arr;
    int size;
    int capacity;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        int i;
        for (i = size - 1; i >= 0 && arr[i] < value; i--) {
            arr[i + 1] = arr[i];
        }

        arr[i + 1] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[0];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(5);

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(50);
    pq.enqueue(20);

    pq.display();
    cout << "Top: " << pq.peek() << endl;
    pq.dequeue();
    pq.display();

    return 0;
}