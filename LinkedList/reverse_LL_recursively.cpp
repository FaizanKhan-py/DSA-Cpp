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

void delete_dublicate(Node*& head) {
	Node* currentNode = head;
	while (currentNode->next != NULL && currentNode != NULL) {
		if (currentNode->value == currentNode->next->value) {
			Node* temp = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(temp);
		}
		else
			currentNode = currentNode->next;
	}
}

void reversePrint(Node* head) {
	if (head == NULL) {
		return;
	}
	reversePrint(head->next);
	cout << head->value << " -> ";
}

Node* reverseLL(Node*& head) {
	Node* prev = NULL;
	Node* current = head;

	while (current != NULL && current->next != NULL) {
		Node* nex = current->next;
		current->next = prev;
		prev = current;
		current = nex;
	}
	Node* newhead = prev;
	return newhead;
}

Node* ReverseLL_Recursively(Node*& head) {

	//base case
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* new_head = ReverseLL_Recursively(head->next);
	head->next->next = head;
	head->next = NULL;
	return new_head;
}

int main() {
	LinkedList ll;
	ll.insert_at_tail(1);
	ll.insert_at_tail(2);
	ll.insert_at_tail(3);
	ll.insert_at_tail(3);
	ll.insert_at_tail(3);
	ll.insert_at_tail(3);

	ll.display();


	ll.head = reverseLL(ll.head);
	ll.display();

	ll.head = ReverseLL_Recursively(ll.head);
	ll.display();
}