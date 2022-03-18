#pragma once

class SortedList {
private:
	int MaxSize;
	int* list;
	int iterator;
	int size;

public:
	SortedList();
	~SortedList();

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