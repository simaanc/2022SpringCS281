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
	//descructor
	~LinkListStack();

	void push(int);
	void pop();
	int top();

};

