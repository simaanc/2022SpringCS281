#pragma once

template <class itemType>

class List
{
private:
	int MaxSize = 10;
	int size = 0;
	itemType* list;

public:

	List() {
		MaxSize = 10;
		size = 0;

		list = new itemType[MaxSize];
	}
	~List() {
		delete[] list;
	}

	void addItem(itemType);
	void deleteItem(itemType);
	
	bool isEmpty() {
		if (size == 0)
			return true;
		else
			return false;
	}
	bool isFull();
	itemType getItem(int);
	int getSize() {
		return size;
	}

};

template<class itemType>
inline void List<itemType>::addItem(itemType item)
{
	if (isFull()) {
		return;
	}

	list[size++] = item;
}

template<class itemType>
inline void List<itemType>::deleteItem(itemType)
{
}

template<class itemType>
inline bool List<itemType>::isFull()
{
	if (size >= MaxSize) {
		return true;
	}

	return false;
}

template<class itemType>
inline itemType List<itemType>::getItem(int idx) 
{
	return list[idx];
}
