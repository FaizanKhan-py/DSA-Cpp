#include <iostream>
using  namespace std;

class Node {
public:
	int value;
	Node* Next;

	Node(int val) {
		value = val;
		Next = NULL;
	}
};

void insert_at_tail(Node*& head, int val) {

	Node* newNode = new Node(val);

	Node* temp = head;

	while (temp->Next != NULL) {
		temp = temp->Next;
	}
	//temp reached last
	temp->Next = newNode;

}

void display(Node* head) {

	Node* temp = head;

	while (temp != NULL) {
		cout << temp->value << " -> ";
		temp = temp->Next;

	}
	cout << "NULL" << endl;
}

int main() {

	Node* head = new Node(2);
	insert_at_tail(head, 10);
	insert_at_tail(head, 8);
	insert_at_tail(head, 6);
	insert_at_tail(head, 400);

	display(head);
}