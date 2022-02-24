#include "UnsortedLinkList.h"
UnsortedLinkList::UnsortedLinkList()
{
	head = nullptr;
	pos = nullptr;
}

UnsortedLinkList::~UnsortedLinkList()
{
	makeEmpty();
}

void UnsortedLinkList::putItem(int input)
{
	Node* temp = new Node(input);

	if (head == nullptr) {
		head = temp;
	}
	else {
		temp->tail = head;
		head = temp;
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

}
