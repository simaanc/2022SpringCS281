#pragma once

class Node {
public:
	int data;
	Node* tail;

	Node(int i) {
		data = i;
		tail = nullptr;
	}
};

class LinkListStack
{
private:
	Node* topPtr;

public:
	//constructor
	LinkListStack();
	LinkListStack(LinkListStack&);
	//descructor
	~LinkListStack();

	void copy(LinkListStack&);

	void push(int);
	void pop();
	int top();

	void clearList();

	void operator=(LinkListStack &Left);
};

