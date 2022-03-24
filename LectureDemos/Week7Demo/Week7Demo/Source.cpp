#include <iostream>
#include "ArrayStack.h"
#include "LinkListStack.h"

using namespace std;

int menu();

int main() {

	//ArrayStack s;
	LinkListStack s;

	/*
	s.push(15);
	s.push(22);
	s.push(99);
	s.push(1);
	s.push(87);
	s.push(32);
	
	cout << s.top() << endl;

	s.pop();
	cout << s.top() << endl;
	
	*/

	int choice = 0;
	do {
		choice = menu();

		switch (choice) {
		
		case 1:
			int input;
			cout << "Please enter an integer: " << endl;
			cin >> input;
			s.push(input);
			cout << "Integer was successfully added" << endl;
			break;
		case 2:
			s.pop();
			cout << "The top number was removed" << endl;
			break;
		case 3:
			cout << "Top is " << s.top() << endl;
			break;
		case 0:
			cout << "Goodbye" << endl;
			break;
		
		default:
			cout << "That is not a choice";
		}




	} while (choice != 0);


	return 0;

}


int menu() {
	int choice;

	cout << "1. Push Integer" << endl;
	cout << "2. Pop Integer" << endl;
	cout << "3. Display Top" << endl;
	cout << "0. Exit" << endl << endl;

	cout << "Enter a menu choice: " << endl;

	cin >> choice;
	return choice;
}