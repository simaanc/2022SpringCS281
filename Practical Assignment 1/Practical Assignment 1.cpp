/* Name: Christopher Simaan
** Practical Exam 1
** CS 281 - Intermediate C++
** Spring 2022
** Instructor: Jaime Sanchez
**
** There are logical and run time errors in the code, as well as compilation errors.
** Your objective is get the code to run, fix any bugs in the code and
** place validation needed to prevent any memory issues. Each function has a
** description of what it does next to its prototype.
** If you can recognize the code issue but do not know how to fix add a comment for partial credit
** This has a hard due date because I will be reviewing in class.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int menu();
void clearScreen();
void pauseScreen();

void addToList(int*); // adds integer to integer array
void displayList(int*); //displays all items in array
void dispSum(int*); //gives sum of all elements in array
void dispAverage(int*); //gives average of elements in array.

unsigned short SIZE = 0;

int main()
{
	int input = 0;
	int arrayList[10];

	do {
		input = menu();
		switch (input) {
			case 0:
				break;
			case 1:
				addToList(arrayList);
				pauseScreen();
				break;
			case 2: 
				displayList(arrayList);
				pauseScreen();
				break;
			case 3: 
				dispSum(arrayList);
				pauseScreen();
				break;
			case 4: 
				dispAverage(arrayList);
				pauseScreen();
				break;
		}
		clearScreen();
	} while (input != 0);
	return 0;
}

void addToList(int *arrayList)
{
	if (SIZE == 10) {
		cout << "Max number reached" << endl;
	}
	else {
		int input;
		cout << "Enter a number into the array: ";
		cin >> input;
		arrayList[SIZE] = input;
		SIZE++;
	}
}

void displayList(int *arrayList) {
	if (SIZE == 0) {
		cout << "No numbers in list" << endl;
	}
	else {
		for (int i = 0; i < SIZE; ++i) {
			cout << arrayList[i] << endl;
		}
	}
}

void dispSum(int *arrayList) {
	int sum = 0;
	if (SIZE == 0) {
		cout << "No numbers in list" << endl;
	}
	else {
		for (int i = 0; i < SIZE; ++i) {
			sum += arrayList[i];
		}
		cout << "The Sum is " << sum << "!" << endl;
	}
}

void dispAverage(int* arrayList) {
	double sum = 0;
	double average = 0;
	if (SIZE == 0) {
		cout << "No numbers in list" << endl;
	}
	else {
		for (int i = 0; i < SIZE; ++i) {
			sum += arrayList[i];
		}
		average = sum / SIZE;
		cout << "The Average is " << fixed << setprecision(2) << average << "!" << endl;
	}
}

int menu() {
	int input;
	cout << "***Main Menu***" << endl
		<< "1. Add Number to List" << endl
		<< "2. Display List." << endl
		<< "3. Display Sum." << endl
		<< "4. Display Average." << endl
		<< "0. Quit" << endl
		<< endl;
	cout << "Enter Choice: ";
	cin >> input;
	while (input < 0 or input > 4) {
		cout << "Enter a valid Choice from the menu: ";
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		cin >> input;
	}
	return input;
}

void clearScreen() {
	system("CLS");
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}
void pauseScreen() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "\n---Enter to Continue!---\n";
	std::cin.get();
}