#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int val) {
		value = val;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* head;

	LinkedList() {
		head = NULL;
	}

	void insert_at_tail(int val) {
		Node* newNode = new Node(val);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->value << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

void delete_alternative_values(Node*& head) {
	Node* currentNode = head;
	while (currentNode != NULL && currentNode->next != NULL) {
		Node* temp = currentNode->next;
		currentNode->next = currentNode->next->next;
		free(temp);
		currentNode = currentNode->next;
	}
}

int main() {
	LinkedList ll;
	ll.insert_at_tail(1);
	ll.insert_at_tail(2);
	ll.insert_at_tail(3);
	ll.insert_at_tail(4);
	ll.insert_at_tail(5);
	ll.insert_at_tail(6);

	ll.display();

	delete_alternative_values(ll.head);
	ll.display();
}