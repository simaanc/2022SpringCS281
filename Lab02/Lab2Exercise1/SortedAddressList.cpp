/*
	CS281 – Spring 2022
	Lab 2: Phone Book
	Christopher Simaan
	March 26th 2022
	Create an address book that sorts contacts alphabetically
	and include a way to find and edit the contact
*/

#include "SortedAddressList.h"

SortedAddressList::SortedAddressList()
{
	//Constructor
	head = nullptr;
	pos = nullptr;
	size = 0;
}

SortedAddressList::~SortedAddressList()
{
	//Deconstructor
	makeEmpty();
}

void SortedAddressList::putContact(string fninput, string lninput, string ainput, string pinput)
{
	//Creates the contact in alphabetical order
	Node* temp = new Node(fninput, lninput, ainput, pinput);
	if (head == nullptr) {
		head = temp;
	}
	else {
		if (temp->fname < head->fname) {
			temp->tail = head;
			head = temp;
		}
		else {
			pos = head;

			bool found = false;

			while (pos->tail != nullptr && found == false) {
				if (pos->tail->fname > temp->fname) {
					found = true;
				}
				else {
					pos = pos->tail;
				}
			}

			if (pos->tail == nullptr) {
				pos->tail = temp;
			}
			else {
				temp->tail = pos->tail;
				pos->tail = temp;
			}
		}
	}
	size++;
	pos = nullptr;
}

//Contact delete but with a search
void SortedAddressList::deleteContact(string fname, string lname) {
	//set pos to be at the contact we want deleted
	findItem(fname, lname);

	if (pos != nullptr) {
		Node* previous = head;

		if (previous == pos) { //if item is head
			head = pos->tail;
			delete previous;
			pos = head;
			size--;
		}
		else {
			while (previous->tail != pos) {
				previous = previous->tail;
			}

			previous->tail = pos->tail;
			delete pos;
			pos = previous;
			size--;
		}
	}
}

//Deleted currently selected contact
void SortedAddressList::deleteContact()
{
	if (pos != nullptr) {
		Node* previous = head;

		if (previous == pos) { //if item is head
			head = pos->tail;
			delete previous;
			pos = head;
			size--;
		}
		else {
			while (previous->tail != pos) {
				previous = previous->tail;
			}

			previous->tail = pos->tail;
			delete pos;
			pos = previous;
			size--;
		}
	}
}

//Empty out linked list
void SortedAddressList::makeEmpty()
{
	pos = head;
	Node* next = nullptr;
	while (pos != nullptr) {
		next = pos->tail;
		delete pos;
		pos = next;
	}
	head = nullptr;
	size = 0;
}

//Display entire list
void SortedAddressList::displayList()
{
	pos = head;
	while (pos != nullptr) {
		cout << "Name: " << pos->fname << " " << pos->lname << endl;
		cout << "Address: " << pos->address << endl;
		cout << "Phone: " << pos->phone << endl;

		pos = pos->tail;
	}
}

//Find a contact based on first and last name
bool SortedAddressList::findItem(string fninput, string lninput)
{
	if (head == nullptr) {
		return false;
	}

	pos = head;

	bool found = false;

	while (pos != nullptr && found == false) {
		if (pos->fname == fninput && pos->lname == lninput) {
			found = true;
		}
		else {
			pos = pos->tail;
		}
	}

	return found;
}

//Display contact information
void SortedAddressList::getItem()
{
	if (pos != nullptr) {
		cout << "Name: " << pos->fname << " " << pos->lname << endl;
		cout << "Address: " << pos->address << endl;
		cout << "Phone: " << pos->phone << endl;
	}
	else {
		cout << "No Contact is Selected" << endl;
	}
}
