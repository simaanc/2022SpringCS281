#include "SortedAddressList.h"

SortedAddressList::SortedAddressList()
{
	head = nullptr;
	pos = nullptr;
	size = 0;
}

SortedAddressList::~SortedAddressList()
{
	makeEmpty();
}

void SortedAddressList::putContact(string fninput, string lninput, string ainput, string pinput)
{
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

void SortedAddressList::deleteContact(string fname, string lname) {
	//set pos
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
