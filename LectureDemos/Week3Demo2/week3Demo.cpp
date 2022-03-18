#include <iostream>
#include "UnsortedList.h"
using namespace std;


void function1()
{

	cout << "This is function 1" << endl;
}



void function2()
{

	cout << "This is function 2" << endl;
}

void function3()
{

	cout << "This is function 3" << endl;

	function1();
}

void displayList(UnsortedList);

int main()
{

	int* ptr = nullptr;


	ptr = new int;


	function1();
	function2();
	function3();

	delete ptr;
	ptr = nullptr;


	UnsortedList l1;

	l1.putItem(15);
	l1.putItem(20);
	l1.putItem(22);
	l1.putItem(14);
	l1.putItem(6);
	l1.putItem(8);
	l1.putItem(34);
	l1.putItem(99);
	l1.putItem(67);
	l1.putItem(12);


	l1.putItem(3);
	l1.putItem(78);

	l1.deleteItem(8);

	displayList(l1);
	cout << "-----" << endl;

	l1.makeEmpty();

	displayList(l1);

	cout << "-----" << endl;


	return 0;
}

void displayList(UnsortedList list)
{

	for(int i=0;i<list.getLength();i++)
		cout << list.getItem(i) << endl;


}