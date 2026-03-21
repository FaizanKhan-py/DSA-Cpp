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

class linkedlist {
public:
	Node* head;
	linkedlist() {
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
		while (temp != NULL)
		{
			cout << temp->value << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}

};

void delete_dublicates(Node*& head) {
	Node* temp = head;


	while (temp != NULL && temp->next != NULL)
	{
		Node* temp2 = temp;
		while (temp2->next != NULL)
		{
			if (temp2->next->value == temp->value) {
				Node* del = temp2->next;
				temp2->next = temp2->next->next;
				free(del);
			}
			else {
				temp2 = temp2->next;
			}
		}
		temp = temp->next;
	}
}

int main() {
	linkedlist LL;
	LL.insert_at_tail(7);
	LL.insert_at_tail(7);
	LL.insert_at_tail(5);
	LL.insert_at_tail(3);
	LL.insert_at_tail(5);
	LL.insert_at_tail(2);
	LL.insert_at_tail(7);
	LL.display();

	delete_dublicates(LL.head);
	LL.display();
}