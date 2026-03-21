#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{ value, NULL };

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void removeduplicates(Node*& head) {
    if (head == NULL) return;

    Node* current = head;

    while (current != NULL) {
        Node* runner = current;

        while (runner->next != NULL) {
            if (current->val == runner->next->val) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            }
            else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 2);
    append(head, 4);
    append(head, 1);

    cout << "Original: ";
    printList(head);

    removeduplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}