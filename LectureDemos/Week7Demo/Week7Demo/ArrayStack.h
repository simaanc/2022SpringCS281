#pragma once

class ArrayStack {

private:
	int* list;
	int size;
	int maxSize;
public:

	ArrayStack();//constructor
	~ArrayStack();//destructor

	void push(int);
	void pop();
	int top();
	bool isEmpty();
	//bool isFull();

};

