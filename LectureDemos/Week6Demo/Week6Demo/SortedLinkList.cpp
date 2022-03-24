#include "SortedLinkList.h"
#include <iostream>

SortedLinkList::SortedLinkList()
{
	head = nullptr;
	pos = nullptr;
}
SortedLinkList::~SortedLinkList()
{
	makeEmpty();
}
void SortedLinkList::putItem(int input)
{
	Node* temp = new Node(input);
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		if (temp->data < head->data)
		{
			temp->tail = head;
			head = temp;
		}
		else
		{
			pos = head;

			bool found = false;

			while (pos->tail != nullptr and found == false)
			{
				if (pos->tail->data > temp->data)
					found = true;
				else
					pos = pos->tail;

			}

			if (pos->tail == nullptr)
				pos->tail = temp;
			else
			{
				temp->tail = pos->tail;
				pos->tail = temp;

			}


		}


	}
}

void SortedLinkList::makeEmpty()
{
	pos = head;
	Node* next = nullptr;
	while (pos != nullptr)
	{
		next = pos->tail;
		delete pos;
		pos = next;
	}
	head = nullptr;
}
void SortedLinkList::displayList()
{
	pos = head;
	while (pos != nullptr)
	{
		std::cout << pos->data << " " << std::endl;
		pos = pos->tail;
	}

}