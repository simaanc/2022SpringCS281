#include "LinkListStack.h"


LinkListStack::LinkListStack() {
	topPtr = nullptr;
}

LinkListStack::~LinkListStack() {
	
	Node* pos = topPtr;
	Node* next = nullptr;

	while (pos != nullptr) {
		next = pos->tail;
		delete pos;
		pos = next;
	}

	topPtr = nullptr;
}

void LinkListStack::push(int input) {
	Node* temp = new Node(input);

	temp->tail = topPtr;
	topPtr = temp;
}

void LinkListStack::pop() {
	if (topPtr == nullptr)
		return;
	Node* temp;

	temp = topPtr;
	topPtr = topPtr->tail;

	delete temp;
}

int LinkListStack::top() {
	
	if (topPtr == nullptr)
		return -9999;
	return topPtr->data;
}
