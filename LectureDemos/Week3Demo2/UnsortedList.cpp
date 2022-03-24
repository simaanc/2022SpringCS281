#include "UnsortedList.h"

 UnsortedList::UnsortedList()
{
	size = 0;
	iterator = 0;
	MaxSize = 10;

	list = new int[MaxSize];//Dynamic memory..heap



	//std::cout << "This is my constructor!" << std::endl;
}


 UnsortedList::~UnsortedList() {
	 if (list != nullptr) {
		 delete[] list;
		 list = nullptr;
	 }
 }

 void UnsortedList::putItem(int item)
 {
	 if (size >= MaxSize) {


		 int* temp = new int[MaxSize*2];

		 for (int i = 0; i < size; ++i)
			 temp[i] = list[i];

		 /*you have to do this delete if 
		 you don't old will still be in memory*/
		 delete [] list;
		 //sets list to be new address
		 list = temp;

		 MaxSize = MaxSize * 2;
	 }
		 return;

	 list[size] = item;
	 size++;

 }

 void UnsortedList::deleteItem(int item)
 {

	 if (!findItem(item))
		 return;

	 for (int i = iterator; i < size - 1; i++)
		 list[i] = list[i + 1];
	 size--;


 }

 void UnsortedList::makeEmpty()
 {
	 size = 0;
 }

 bool UnsortedList::listFull()
 {
	 if(size>=MaxSize)
		return true;

	return false;
 }

 int UnsortedList::getLength()
 {
	 return size;
 }

 void UnsortedList::resetList()
 {
	 iterator = 0;
 }

 int UnsortedList::getNextItem()
 {
	 if (size <= iterator + 1)
		 return list[iterator];

	 return list[++iterator];

	 return 0;
 }

 bool UnsortedList::findItem(int item)
 {
	 iterator = 0;

	 if (size == 0)
		 return false;

	 //Finds position of 
	 while (iterator < size and list[iterator] != item)
	 {
		 iterator++;
	 }

	 //item not found in list
	 if (iterator >= size)
		 return false;
	 //found item iterator at position
	 return true;
 }

 int UnsortedList::getItem()
 {
	 if (size == 0)
		 return -9999;

	 if (iterator >= size)
		 iterator = size - 1;

	 return list[iterator];
 }

 int UnsortedList::getItem(int pos)
 {
	 if (pos < 0 || pos >= size)
		 return -9999;

	 return list[pos];
 }
