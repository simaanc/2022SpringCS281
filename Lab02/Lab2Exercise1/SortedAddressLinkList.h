#pragma once
#include <string>

using namespace std;

class Node {
public: 
	string data;
	string firstName, lastname, phone;

	Node* tail;

	Node(string d) {
		data = d;
		tail = nullptr;
	}
};

class SortedAddressLinkList
{
private:
	Node* head;
	Node* pos;
	int size;
public:
	SortedAddressLinkList();
	~SortedAddressLinkList();
	void putItem(string);
	void deleteItem(string);
	void makeEmpty();
	bool listFull();
	int getLength();
	void resetList();
	int getNextItem();
	void displayList();
	bool findItem(string);
	int getItem();
	int getItem(string);


};

