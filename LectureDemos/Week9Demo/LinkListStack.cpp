#include "LinkListStack.h"


LinkListStack::LinkListStack() {
	topPtr = nullptr;
}

LinkListStack::LinkListStack(LinkListStack &left) {
	copy(left);
}

LinkListStack::~LinkListStack() {
	clearList();
}

void LinkListStack::copy(LinkListStack& left)
{
	clearList();

	if (left.topPtr == nullptr)
		return;

	Node *tempLeft = left.topPtr;

	topPtr = new Node(tempLeft->data);

	Node* loc = topPtr;

	tempLeft = tempLeft->tail;
	while (tempLeft != nullptr) {
		//push(temp->data);

		loc->tail = new Node(tempLeft->data);
		tempLeft = tempLeft->tail;
		loc = loc->tail;
	}
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

void LinkListStack::clearList()
{
	Node* pos = topPtr;
	Node* next = nullptr;

	while (pos != nullptr) {
		next = pos->tail;
		delete pos;
		pos = next;
	}

	topPtr = nullptr;
}

void LinkListStack::operator=(LinkListStack &Left)
{
	copy(Left);
}
