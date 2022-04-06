#include <iostream>
#include "UnsortedList.h"
#include "UnsortedLinkList.h"

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

void displayList(UnsortedList& const);

int main()
{

	int* ptr = nullptr;


	ptr = new int;


	function1();
	function2();
	function3();

	delete ptr;
	ptr = nullptr;


	UnsortedList list1;

	list1.putItem(15);
	list1.putItem(20);
	list1.putItem(22);
	list1.putItem(14);
	list1.putItem(6);
	list1.putItem(8);
	list1.putItem(34);
	list1.putItem(99);
	list1.putItem(67);
	list1.putItem(12);


	list1.putItem(3);
	list1.putItem(78);

	list1.deleteItem(8);

	displayList(list1);
	cout << "-----" << endl;

	list1.makeEmpty();

	displayList(list1);

	cout << "-----" << endl;


	UnsortedList* listPtr = new UnsortedList;

	//The same thing except top is cleaner
	listPtr->putItem(14);
	(*listPtr).putItem(22);

	cout << "-----" << endl;

	UnsortedLinkList l1;

	cout << l1.getLength() << endl;

	l1.putItem(15);
	l1.putItem(8);
	l1.putItem(99);
	l1.putItem(2);

	cout << l1.getLength() << endl;

	l1.deleteItem(22);

	cout << l1.getLength() << endl;
	return 0;
}

void displayList(UnsortedList & const list)
{

	for(int i=0;i<list.getLength();i++)
		cout << list.getItem(i) << endl;


}