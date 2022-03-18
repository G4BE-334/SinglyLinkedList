#include "SinglyLL.h"

SinglyLL::SinglyLL() {
	head = NULL;
}

int SinglyLL::front() {
	node* temp = head;
	if (!isEmpty()) {
		return temp -> data;
	}
	else {
		cout << "This list is empty" << endl;
		return 0;
	}
}

int SinglyLL::back() {
	node* temp = head;
	if (!isEmpty()) {
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		return temp -> data;
	}
	else {
		cout << "This list is empty" << endl;
		return 0;
	}
}

void SinglyLL::insertFront(int newData) {
	node* newNode = new node;
	newNode-> data = newData;
	newNode-> next = head;
	head = newNode;
	length++;
}

void SinglyLL::insertEnd(int newData) {
	node* newNode = new node;
	node * temp = head;
	newNode-> data = newData;
	newNode-> next = NULL;
	while (temp -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = newNode;
	length++;
}

void SinglyLL::insert(int newData) {
	node* newNode = new node;
	node* temp = head;
	node* previous = new node;
	newNode -> data = newData;
	if (head == NULL) {
		head = newNode;
	}
	else {
    	while (temp != NULL) {
    		previous = temp;
    		temp = temp -> next;
    		
    		if (newData > previous -> data && (temp == NULL || newData < temp -> data )) {
    		    previous -> next = newNode;
    		    newNode -> next = temp;
    		    break;
    		}
    		else if (newData < previous -> data && previous == head) {
    		    newNode -> next = previous;
    		    head = newNode;
    		}
    	}
	}
	length++;
}

void SinglyLL::popFront() {
	node* temp = head;
	head = temp -> next;
	delete temp;
	length--;
}

void SinglyLL::popBack() {
	node* temp = head;
	node* previous = new node;

	while (temp -> next != NULL) {
		previous = temp;
		temp = temp -> next;
	}

	previous -> next = NULL;
	delete(temp);
	length--;
}

void SinglyLL::deleteNode(int d) {
	bool check = false;
	node* temp = head;
	node* previous = new node;
	if (temp != NULL && temp -> data == d) {
		head = temp->next;
		check = true;
	}
	while (temp != NULL && temp -> data != d) {
		previous = temp;
		temp = temp-> next;
	}
	if (temp != NULL) {
		previous -> next = temp -> next;
		if (check == true || temp->data == d) {
			delete(temp);
			length--;
		}
	}
	else {
		cout << "The data "<< d << " is not in the List" << endl;
	} 
} 

bool SinglyLL::isEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

int SinglyLL::size() {
	return length;
}

void SinglyLL::reverse() {
	int tempArray[length];
	node* temp = head;
	
	for (int i = 0; i < length; i++) {
		tempArray[i] = temp -> data;
		temp = temp -> next;
	}
	head = NULL;
	int tempL = length;
	for (int i = 0; i < tempL; i++) {
		insertFront(tempArray[i]);
		length--;
	}
}

void SinglyLL::display() {
	node* temp;
	temp = head;
	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

// This method will only work if both LL are already sorted
node* SinglyLL::merge(node* hd, node* nd) {
	node* a = hd;
	node* b = nd; 
	if (a == NULL) { return b; }
	if (b == NULL) { return a; }
	if (a->data < b->data) {
		a->next = merge(a->next, b);
		return a;
	}
	else {
		b->next = merge(a, b->next);
		return b;
	}
}