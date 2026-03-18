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

void insert_at_Start(Node*& head, int val) {

	Node* newnode = new Node(val);
	newnode->Next = head;
	head = newnode;
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
	insert_at_Start(head, 10);
	insert_at_Start(head, 8);
	insert_at_Start(head, 6);
	insert_at_Start(head, 400);

	display(head);
}