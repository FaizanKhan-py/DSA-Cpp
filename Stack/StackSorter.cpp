#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& s, int x) {
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(temp);
}


void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        sortStack(s);
        insertSorted(s, x);
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    cout << "Original Stack: ";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}