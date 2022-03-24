#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
	front = 0;
	back = 0;
	size = 0;
}

bool ArrayQueue::enqueue(std::string input)
{
	if (isFull()) {
		return false;
	}
	
	list[back] = input;
	back = (back + 1) % MaxSize;
	size++;
}

std::string ArrayQueue::dequeue()
{
	if (isEmpty())
		return "!Queue Empty!";
	
	std::string output = list[front];

	front = (front + 1) % MaxSize;

	size--;

	return output;
}

bool ArrayQueue::isEmpty()
{
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool ArrayQueue::isFull()
{
	if (size >= MaxSize)
		return true;
	else
		return false;
}

void ArrayQueue::MakeEmpty()
{
	size = 0;
	front = 0;
	back = 0;
}
