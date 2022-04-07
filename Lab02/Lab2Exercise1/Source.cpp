/*
	CS281 – Spring 2022
	Lab 2: Phone Book
	Christopher Simaan
	March 26th 2022
	Create an address book that sorts contacts alphabetically
	and include a way to find and edit the contact
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "SortedAddressList.h"

using namespace std;

int menu();
void clearScreen();
void pauseScreen();

string selectedfirst;
string selectedlast;

bool contactselected = false;

int main() {

	SortedAddressList s;

	int input = 0;

	string firstname;
	string lastname;
	string phone;
	string address;

	//begin menu choice
	do {
		input = menu();
		switch (input) {
			//exit program if input = 0
			case 0:
				break;
			case 1:
				//Add Contact
				cout << "Enter First Name: ";
				cin >> firstname;
				cout << "Enter Last Name: ";
				cin >> lastname;
				cout << "Enter Phone Number: ";
				cin >> phone;
				cout << "Enter Address: ";
				cin >> address;

				s.putContact(firstname, lastname, phone, address);
				pauseScreen();
				break;
			case 2:
				//Find Contact
				cout << "Enter First Name: ";
				cin >> firstname;
				cout << "Enter Last Name: ";
				cin >> lastname;

				if (s.findItem(firstname, lastname) == true) {
					s.findItem(firstname, lastname);
					cout << "Found Contact" << endl;
					selectedfirst = firstname;
					selectedlast = lastname;
					contactselected = true;
				}
				else {
					cout << "Could Not Find Contact";
					contactselected = false;
				}

				pauseScreen();
				break;
			case 3:
				//Edit Contact
				if (contactselected) {
					cout << "Now Editing: " 
						 << selectedfirst 
						 << " " 
						 << selectedlast 
						 << endl;
					s.deleteContact();
					
					cout << "Enter New First Name: ";
					cin >> firstname;
					cout << "Enter New Last Name: ";
					cin >> lastname;
					cout << "Enter New Phone Number: ";
					cin >> phone;
					cout << "Enter New Address: ";
					cin >> address;

					s.putContact(firstname, lastname, phone, address);
					s.findItem(firstname, lastname);
					selectedfirst = firstname;
					selectedlast = lastname;
				}
				else {
					cout << "No Contact Selected!" << endl;
				}
				
				pauseScreen();
				break;
			case 4:
				//Delete Contact
				if (contactselected) {
					cout << "Deleted: "
						<< selectedfirst
						<< " "
						<< selectedlast
						<< endl;
					s.deleteContact();
					selectedfirst.clear();
					selectedlast.clear();
					contactselected = false;
				}
				else {
					cout << "No Contact Selected!" << endl;
				}


				pauseScreen();
				break;		
			case 5:
				//Display Contact
				if (contactselected) {
					s.getItem();
				}
				else {
					cout << "No Contact Selected!" << endl;
				}


				pauseScreen();
				break;
		}
		clearScreen();
	} while (input != 0);
	return 0;
}

//Create a menu
int menu() {
	int input;
	cout << "***Main Menu***" << endl
		<< "1. Add Contact" << endl
		<< "2. Find Contact" << endl
		<< "3. Edit Contact" << endl
		<< "4. Delete Contact" << endl
		<< "5. Display Current Contact" << endl
		<< "0. Quit" << endl
		<< endl;
	if (contactselected) {
		cout << "Current Contact: "
			<< selectedfirst
			<< " "
			<< selectedlast
			<< endl;
	}
	else {
		cout << "Current Contact: None" << endl;
	}
	cout << endl;
	cout << "Enter Choice: ";
	cin >> input;
	while (input < 0 or input > 5) {
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