#include "SortedList.h"

SortedList::SortedList()
{

	MaxSize = 10;
	size = 0;
	iterator = 0;

	list = new int[MaxSize]; //Dynamic Memory..HEAP
}

SortedList::~SortedList()
{
	if (list != nullptr) {
		delete[] list;
		list = nullptr;
	}
}

int SortedList::getLength()
{
	return size;
}

int SortedList::getItem()
{
	if (size == 0)
		return -9999;

	if (iterator >= size)
		iterator = size - 1;

	return list[iterator];
}

int SortedList::getItem(int pos)
{
	if (pos < 0 || pos >= size)
		return -9999;

	return list[pos];
}

void SortedList::putItem(int item)
{
	if (size == 0) { //empty list
		list[size] = item;
		size++;
	}
	else {
		if (size >= MaxSize) {
			int* temp = new int[MaxSize * 2];

			for (int i = 0; i < size; ++i)
				temp[i] = list[i];

			/*you have to do this delete if
			you don't old will still be in memory*/
			delete[] list;
			//sets list to be new address
			list = temp;

			MaxSize = MaxSize * 2;
		}

		iterator = 0;

		while (iterator < size && list[iterator] < item) {
			++iterator;
		}

		for (int i = size; i > iterator; --i) {
			list[i] = list[i - 1];
		}

		list[iterator] = item;

		size++;
	}

}


bool SortedList::findItem(int item)
{
	iterator = 0;

	if (size == 0)
		return false;

	//Finds position of 
	while (iterator < size and list[iterator] != item)
	{
		iterator++;
	}

	//item not found in list
	if (iterator >= size)
		return false;
	//found item iterator at position
	return true;
}

void SortedList::makeEmpty()
{
	size = 0;
}

