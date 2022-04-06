#include <iostream>
#include "ArrayQueue.h"
#include "LinkedListQueue.h"

using namespace std;

int main() {
	//ArrayQueue q;
	LinkedListQueue q;


	q.enqueue("Tom");
	q.enqueue("Bill");
	q.enqueue("Lisa");
	q.enqueue("Jenny");
	q.enqueue("Frank");
	q.enqueue("Jim");

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	q.enqueue("Jill");
	q.enqueue("Mark");
	q.enqueue("Paul");
	q.enqueue("Peter");
	q.enqueue("John");
	q.enqueue("Mary");

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;




	return 0;
}