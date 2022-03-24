#pragma once
#include <iostream>
#include <string>

class ArrayQueue
{
private:
	static const int MaxSize = 10;
	std::string list[MaxSize];


	int front;
	int back;
	int size;

public:
	ArrayQueue();

	bool enqueue(std::string);
	std::string dequeue();
	bool isEmpty();
	bool isFull();
	void MakeEmpty();

};

