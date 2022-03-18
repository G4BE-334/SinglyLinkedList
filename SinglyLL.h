#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	};

class SinglyLL{
	private:
	int length = 0;
	
	public:
	node* head = NULL;
	SinglyLL();
	int front();
	int back();
	void insertFront(int data);
	void insertEnd(int data);
	void insert(int newData);
	void popFront();
	void popBack();
	void deleteNode(int n);
	bool isEmpty();
	int size();
	void reverse();
	void display();
	node* merge(node* hd, node* nd);
};

#endif