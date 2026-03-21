#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;

	Node(int v) {
		val = v;
		next = NULL;
	}

};

class LinkedList {
private:
	Node* head;

public:
	LinkedList() {
		head = NULL;
	}

	void insert_at_head(int value) {
		Node* newnode = new Node(value);
		newnode->next = head;
		head = newnode;
	}

	void insert_at_tail(int value) {

		Node* newnode = new Node(value);
		if (head == NULL) { // If the list is empty
			head = newnode;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}

	void insert_at_pos(int value, int pos) {
		if (pos == 0) {
			insert_at_head(value);
			return;
		}
		Node* newnode = new Node(value);
		int currentPos = 0;
		Node* temp = head;
		while (currentPos != pos - 1) {
			temp = temp->next;
			currentPos++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}

	void update_value(int value, int pos) {

		int currentPos = 0;
		Node* temp = head;
		while (currentPos != pos) {
			temp = temp->next;
			currentPos++;
		}
		temp->val = value;
	}

	void delete_node_at_start() {
		Node* temp = head;
		head = head->next;
		free(temp);
	}

	void delete_node_at_end() {
		Node* secondlast = head;
		while (secondlast->next->next != NULL) {
			secondlast = secondlast->next;
		}
		Node* temp = secondlast->next;
		secondlast->next = NULL;
		free(temp);
	}

	void delete_node_at_pos(int pos) {
		if (pos == 0) {
			delete_node_at_start();
			return;
		}
		Node* prev = head;
		int currentPos = 0;
		while (currentPos != pos - 1) {
			currentPos++;
			prev = prev->next;
		}
		Node* temp = prev->next;
		prev = prev->next->next;
		free(temp);
	}

	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->val << " -> ";
			temp = temp->next;
		}
		cout << "NULL";
	}

	Node* get_head() {
		return head;
	}
};

void removedublicates(Node*& head) {
	if (head == NULL) {
		return;
	}
	Node* current = head;

	while (current != NULL) {
		Node* runner = current;

		while (runner->next != NULL) {
			if (current->val == runner->next->val) {
				Node* temp = runner->next;
				runner->next = runner->next->next;
				free(temp);
			}
			else {
				runner = runner->next;
			}
		}
		current = current->next;

	}

}

class Stack {
	LinkedList list;

public:
	void push(int value) {
		list.insert_at_tail(value);
	}
	void pop() {
		list.delete_node_at_end();
	}
	void display() {
		list.display();
	}
};


class Queue {
	LinkedList list;
public:
	void enqueue(int value) {
		list.insert_at_tail(value);
	}
	void dequeue() {
		list.delete_node_at_start();
	}
	void display() {
		list.display();
	}
};


int main() {

	cout << "-----STACK-----\n";
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.display();
	cout << endl << endl;

	s.pop();
	s.display();
	cout << endl << endl;

	cout << "------Queue------\n";
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();
	cout << endl << endl;

	q.dequeue();
	q.display();
	cout << endl << endl;
}