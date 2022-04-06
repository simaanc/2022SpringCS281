#pragma once
#include <iostream>
#include <string>

class Node {
public:
	std::string data;
	Node* tail;

	Node(std::string d) {
		data = d;
		tail = nullptr;
	}
};

class LinkedListQueue
{
private:
	Node* front;
	Node* back;



public:
	LinkedListQueue();
	~LinkedListQueue();

	bool enqueue(std::string);
	std::string dequeue();
	bool isEmpty();
	void MakeEmpty();
};

