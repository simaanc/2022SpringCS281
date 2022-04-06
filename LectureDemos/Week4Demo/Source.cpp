#include <iostream>

using namespace std;

int main() {

	int x = 5;

	//Displays memory address of x because of &
	cout << &x << endl;

	int* ptr;

	//Stores the location of x not the value
	ptr = &x;

	cout << ptr << endl;

	//If use * on pointer it "unpointers" it
	cout << *ptr << endl;

	//At that memory location it is assigned 60 (also same memory location as x
	*ptr = 60;

	cout << x << endl;

	return 0;
}