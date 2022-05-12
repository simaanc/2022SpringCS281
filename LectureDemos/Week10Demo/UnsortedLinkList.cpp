#include "UnsortedLinkList.h"

std::string UnsortedLinkList::printReverseNodes(Node* pos)
{
	if (pos == nullptr)
		return "";

	return printReverseNodes(pos->tail)  + std::to_string(pos->data)+ ", ";
}

UnsortedLinkList::UnsortedLinkList()
{
	head = nullptr;
	pos = nullptr;

}

UnsortedLinkList::~UnsortedLinkList()
{
	makeEmpty();
}

void UnsortedLinkList::printReverse()
{
	if (head == nullptr)
		std::cout << "List is empty" << std::endl;

	std::cout << printReverseNodes(head->tail) << head->data  << std::endl;

}

void UnsortedLinkList::putItem(int input)
{
	Node* temp = new Node(input);

	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		temp->tail = head;
		head = temp;
	}


}

void UnsortedLinkList::makeEmpty()
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
