#include <iostream>
#include "SortedList.h"

using namespace std;

void displayList(SortedList& const list);

int main() {
	SortedList l1;

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

	displayList(l1);
}

void displayList(SortedList& const list)
{

	for (int i = 0; i < list.getLength(); i++)
		cout << list.getItem(i) << endl;


}