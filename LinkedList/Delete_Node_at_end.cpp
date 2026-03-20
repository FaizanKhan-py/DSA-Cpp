#include<iostream>
using namespace std;

class Node {
public:
	int value;
	Node* Next;

	Node(int val) {
		value = val;
		Next = NULL;
	}
};

void insert_at_position(Node*& head, int val, int pos) {

	Node* newNode = new Node(val);
	Node* temp = head;
	int currentPos = 0;

	while (currentPos != pos - 1) {
		temp = temp->Next;
		currentPos++;
	}

	newNode->Next = temp->Next;
	temp->Next = newNode;
}

void insert_at_head(Node*& head, int val) {
	Node* newNode = new Node(val);
	newNode->Next = head;
	head = newNode;
}

void insert_at_tail(Node*& head, int val) {

	Node* temp = head;
	Node* newNode = new Node(val);

	while (temp->Next != NULL) {
		temp = temp->Next;
	}

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

void update_at_pos(Node*& head, int pos, int val) {

	Node* temp = head;
	int currentPos = 0;
	while (currentPos != pos) {
		temp = temp->Next;
		currentPos++;
	}
	temp->value = val;
}

void delete_node_at_start(Node*& head) {

	Node* temp = head;
	head = head->Next;
	free(temp);
}

void delete_at_end(Node*& head) {

	Node* secondlast = head;
	while (secondlast->Next->Next != NULL) {
		secondlast = secondlast->Next;
	}
	//second last has reached to second last position
	Node* temp = secondlast->Next;
	secondlast->Next = NULL;
	free(temp);
}

int main() {

	Node* head = NULL;
	insert_at_head(head, 21);
	insert_at_head(head, 32);

	insert_at_tail(head, 88);
	insert_at_tail(head, 102);

	insert_at_position(head, 007, 2);

	display(head);

	update_at_pos(head, 2, 123);
	display(head);

	delete_node_at_start(head);
	display(head);

	delete_at_end(head);
	display(head);
	return 0;
}