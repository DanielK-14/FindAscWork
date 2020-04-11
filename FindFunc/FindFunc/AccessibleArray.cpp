#include "AccessibleArray.h"

AccessibleArray::AccessibleArray(int _size) :size(_size)
{
	arr = new ArrayNode[size];
	makeEmpty();
}

AccessibleArray::~AccessibleArray()
{
	delete[] arr;
}

void AccessibleArray::makeEmpty()
{
	for (int i = 0; i < size; i++)
	{
		arr[i].data = EMPTY;	///-1 will represent an empty cell.
		arr[i].next = EMPTY;	///Initializes the free positions list.
	}
	headList = EMPTY;
	tailList = EMPTY;
}

int AccessibleArray::getSize()
{
	return size;
}

int AccessibleArray::getHeadList()
{
	return headList;
}

int AccessibleArray::getTailList()
{
	return headList;
}

void AccessibleArray::InsertAtTheEnd(int PC_number)
{
	if (headList == EMPTY)	///Adding first value to the array.
	{
		headList = PC_number - 1;
		tailList = PC_number - 1;
		arr[headList].data = PC_number;
	}
	else if (arr[PC_number - 1].data == EMPTY)	///Adding not first value and not inputed value yet.
	{
		arr[tailList].next = PC_number - 1;
		arr[PC_number - 1].data = PC_number;
		tailList = PC_number - 1;
	}
}

void AccessibleArray::print()
{
	int i = headList;
	while (i != EMPTY)
	{
		cout << arr[i].data << " ";
		i = arr[i].next;
	}
	cout << endl;
}
