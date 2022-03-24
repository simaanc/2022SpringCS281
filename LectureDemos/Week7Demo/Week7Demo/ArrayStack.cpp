#include "ArrayStack.h"

ArrayStack::ArrayStack()
{
	maxSize = 10;
	size = 0;
	list = new int[maxSize];

}

ArrayStack::~ArrayStack() 
{
	delete[] list;
}

void ArrayStack::push(int input)
{
	if (size >= maxSize) {
		
		maxSize = 2 * maxSize;
		int* temp = new int[maxSize];

		for (int i = 0; i < size; ++i) {
			temp[i] = list[i];
		}

		delete[] list;
		list = temp;
	}

	list[size] = input;
	size++;
}

void ArrayStack::pop()
{

	if (isEmpty()) {
		return;
	}
	size--;

	if (size < maxSize / 3) {
		maxSize = maxSize/3;
		int* temp = new int[maxSize];

		for (int i = 0; i < size; ++i) {
			temp[i] = list[i];
		}

		delete[] list;
		list = temp;
	}
}

int ArrayStack::top()
{
	if (isEmpty()) {
		return -99999;
	}

	return list[size - 1];
}

bool ArrayStack::isEmpty()
{
	if (size <= 0) 
		return true;
	else	
		return false;
}
