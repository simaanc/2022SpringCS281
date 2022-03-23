#pragma once

class Node {
public:
	int data;
	Node *tail;

	//constructor
	Node(int d) {
		
		data = d;

		tail = nullptr;
	}


};

class UnsortedLinkList {
	
private:
	Node* head;
	Node* pos;
	int size;

public:
	UnsortedLinkList();
	~UnsortedLinkList();

	void putItem(int);
	void deleteItem(int);
	void makeEmpty();
	bool listFull();
	int getLength();
	void resetList();
	int getNextItem();
	bool findItem(int);
	int getItem();//returns current iterator position
	int getItem(int); //returns value at postion passed in.

};