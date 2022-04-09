#include <iostream>
#include "List.h"
#include "LinkListStack.h"

using namespace std;

template <class itemType>
void displayList(List<itemType> &l);

int main() {
	List<int> intList;
	List<string> stringList;


	intList.addItem(15);
	
	stringList.addItem("Hello");
	stringList.addItem("World");
	stringList.addItem("This");
	stringList.addItem("Is");
	stringList.addItem("Fun");

	displayList(stringList);

	LinkListStack as1,as2;

	as1.push(15);
	as1.push(22);
	as1.push(30);
	as1.push(10);
	as1.push(17);
	as1.push(80);

	as2 = as1;
	
	//as2.operator=(as1);


	LinkListStack as3(as1);

	return 0;
}

template <class itemType>
void displayList(List<itemType> &l) {
	for (int i = 0; i < l.getSize(); ++i) {
		cout << l.getItem(i) << endl;
	}
}