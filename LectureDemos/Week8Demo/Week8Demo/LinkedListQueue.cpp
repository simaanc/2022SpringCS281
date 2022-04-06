#include "LinkedListQueue.h"

LinkedListQueue::LinkedListQueue()
{
	front = nullptr;
	back = nullptr;
}

LinkedListQueue::~LinkedListQueue()
{
	MakeEmpty();
}

bool LinkedListQueue::enqueue(std::string s)
{
	Node* temp = new Node(s);

	if (isEmpty()) {
		front = temp;
		back = temp;
	}
	else {
		back->tail = temp;
		back = temp;
	}


	return true;
}

std::string LinkedListQueue::dequeue()
{
	if (isEmpty()) {
		return "!!Queue Empty!!";
	} else {

		std::string output = front->data;
		
		Node* temp = front;
		front = front->tail;
		delete temp;

		if (front == nullptr) {
			back = nullptr;
		}

		return output;
	}
}

bool LinkedListQueue::isEmpty()
{
	if (front == nullptr)
		return true;
	else
		return false;
}

void LinkedListQueue::MakeEmpty()
{
	Node* pos = front;
	Node* next = nullptr;

	while (pos != nullptr) {
		next = pos->tail;
		delete pos;
		pos = next;

	}

	front = nullptr;
	back = nullptr;
}
