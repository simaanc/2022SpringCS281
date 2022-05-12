#pragma once
#include <iostream>


class Node
{

public:

	int data;

	Node* right, * left;//child nodes;

	Node(int d)
	{
		data = d;

		right = nullptr;
		left = nullptr;
	}
};


class BST
{
private:
	
	Node* Root;
	Node* current;

	void put(Node*,int);
	void empty(Node*);
	void orderPrint(Node*);
	void deleteNode(Node*);
	Node* findParent(Node*);
	Node* rightMostLeft(Node*);

public:

	BST();
	~BST();

	void putItem(int);
	bool deleteItem(int);
	bool findItem(int); // sets current to located node
	bool isEmpty();
	void makeEmpty();
	void printOrderedList();
	int getCurrent();

};
