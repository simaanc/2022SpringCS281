#pragma once

class Node {
public:
	int data;

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
