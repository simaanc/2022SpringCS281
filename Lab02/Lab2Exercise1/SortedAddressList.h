#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string fname;
	string lname;
	string address;
	string phone;

	Node* tail;

	//constructor
	Node(string fn, string ln, string a, string p) {
		fname = fn;
		lname = ln;
		address = a;
		phone = p;
		tail = nullptr;
	}
};

class SortedAddressList
{
private:
	Node* head;
	Node* pos;
	int size;
public: 
	SortedAddressList();
	~SortedAddressList();
	void putContact(string, string, string, string);
	void deleteContact(string, string);
	void deleteContact();
	void makeEmpty();
	void displayList();
	bool findItem(string, string);
	void getItem();//returns current iterator position
	//int getItem(string); //returns value at postion passed in.

};

