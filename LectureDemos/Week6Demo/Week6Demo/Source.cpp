// Example program
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
	int data;
	string firstName, lastname, phone;

	Node* tail;
	//constructor
	Node(int d)
	{
		data = d;
		tail = nullptr;
	}
};
class SortedLinkList
{
private:
	Node* head;
	Node* pos;
	int size;
public:
	SortedLinkList();
	~SortedLinkList();
	void putItem(int);
	void deleteItem(int);
	void makeEmpty();
	bool listFull();
	int getLength();
	void resetList();
	int getNextItem();
	void displayList();
	bool findItem(int);
	int getItem();//returns current iterator position
	int getItem(int); //returns value at postion passed in.
};
int main()
{

	SortedLinkList sLL;

	sLL.putItem(100);
	sLL.putItem(75);
	sLL.putItem(32);
	sLL.putItem(10);
	sLL.putItem(15);
	sLL.putItem(99);


	sLL.displayList();



}
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
		cout << pos->data << " " << endl;
		pos = pos->tail;
	}

}