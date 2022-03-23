#pragma once
#include <iostream>


class UnsortedList
{
private:
	int MaxSize = 10000;
	//int list[MaxSize];
	int* list;
	int iterator;
	int size;

public:
	 UnsortedList(); //Constructor
	 ~UnsortedList();//Destructor

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


