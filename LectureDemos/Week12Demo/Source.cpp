#include <iostream>
#include "BST.h"

using namespace std;


int main()
{
	BST bst;

	bst.putItem(5);
	bst.putItem(3);
	bst.putItem(10);
	bst.putItem(7);
	bst.putItem(9);

	bst.printOrderedList();

	if (bst.findItem(7))
	{
		cout << "item found" << endl;
	}
	else
		cout << "item not found" << endl;


	return 0;
}