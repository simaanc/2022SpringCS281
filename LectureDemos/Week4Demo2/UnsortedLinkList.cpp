#include "UnsortedLinkList.h"
UnsortedLinkList::UnsortedLinkList()
{
	head = nullptr;
	pos = nullptr;
	size = 0;
}

UnsortedLinkList::~UnsortedLinkList()
{
	makeEmpty();
}

void UnsortedLinkList::putItem(int input)
{
	Node* temp = new Node(input);

	if (head == nullptr)// checks for empty list 
	{
		head = temp;
	}
	else {
		temp->tail = head;
		head = temp;
	}

	size++;

}

void UnsortedLinkList::deleteItem(int item)
{

	findItem(item); //sets POS to position


	if (pos != nullptr) {
		Node* previous = head;

		if (previous == pos) { //if item is head
			head = pos->tail;
			delete previous;
			pos = head;
			size--;
		}
		else {
			while (previous->tail != pos) {
				previous = previous->tail;
			}

			previous->tail = pos->tail;
			delete pos;
			pos = previous;
			size--;
		}
	}
}

void UnsortedLinkList::makeEmpty()
{
	pos = head;
	Node* next = nullptr;

	while (pos != nullptr) {
		next = pos->tail;
		delete pos;

		pos = next;
	}

	head = nullptr;

	size = 0;

}

int UnsortedLinkList::getLength()
{
	return size;
}

bool UnsortedLinkList::findItem(int input)
{
	if (head == nullptr) {
		return false;
	}

	pos = head;

	bool found = false;

	while (pos != nullptr && found == false) {
		if (pos->data == input) {
			found = true;
		}
		else {
			pos = pos->tail;
		}
	}

	return found;
}
