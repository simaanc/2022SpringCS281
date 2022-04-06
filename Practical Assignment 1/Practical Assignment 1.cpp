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
int dispSum(int*); //gives sum of all elements in array
double dispAverage(int*); //gives average of elements in array.

unsigned short SIZE = 0;

int main()
{
	int input = 0;
	int arrayList[10];

	//begin menu choice
	do {
		input = menu();
		switch (input) {
			//exit program if input = 0
			case 0:
				break;
			case 1:
				//addToList function with arrayList pointer
				addToList(arrayList);
				pauseScreen();
				break;
			case 2: 
				//displayList function with arrayList pointer
				displayList(arrayList);
				pauseScreen();
				break;
			case 3: 
				//displaySum function with arrayList pointer
				cout << "The Sum is " << dispSum(arrayList) << "!" << endl;
				pauseScreen();
				break;
			case 4: 
				//dispAverage function with arrayList pointer
				cout << "The Average is " << fixed << setprecision(2) << dispAverage(arrayList) << "!" << endl;
				pauseScreen();
				break;
		}
		clearScreen();
	} while (input != 0);
	return 0;
}

void addToList(int *arrayList)
{
	int input;

	//verification that array isn't full
	if (SIZE == 10) {
		cout << "Max number reached" << endl;
	}
	else {
		cout << "Enter a number into the array: ";

		//verification that it's a valid number
		while (!(cin >> input)) {
			cout << "Please enter a valid number into the array: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		//add number to array
		arrayList[SIZE] = input;
		//increase counter by 1
		SIZE++;
	}
}

void displayList(int *arrayList) {
	//verifiy that array isn't empty
	if (SIZE == 0) {
		cout << "No numbers in list" << endl;
	}
	else {
		//go through the array and output each valid value
		for (int i = 0; i < SIZE; ++i) {
			cout << arrayList[i] << endl;
		}
	}
}

int dispSum(int *arrayList) {
	int sum = 0;
	//verify that the array isn't empty
	if (SIZE == 0) {
		cout << "No numbers in list" << endl;
	}
	else {
		//add each number in the array
		for (int i = 0; i < SIZE; ++i) {
			sum += arrayList[i];
		}
		return sum;
	}
}

double dispAverage(int* arrayList) {
	double sum = 0;
	double average = 0;
	//verify that the array isn't empty
	if (SIZE == 0) {
		cout << "No numbers in list" << endl;
	}
	else {
		//gets the average of each 
		sum = dispSum(arrayList);
		average = sum / SIZE;
		return average;
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