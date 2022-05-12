#include <iostream>
#include "UnsortedLinkList.h"

using namespace std;

int factorial(int);

int main()
{

	UnsortedLinkList ll;

	ll.putItem(10);
	ll.putItem(15);
	ll.putItem(25);
	ll.putItem(50);
	ll.putItem(17);
	ll.putItem(32);

	ll.printReverse();


	//cout << factorial(10) << endl;

	return 0;

}





int factorial(int n)
{

	if (n == 0)
		return 1;

	return n * (factorial(n - 1));

}