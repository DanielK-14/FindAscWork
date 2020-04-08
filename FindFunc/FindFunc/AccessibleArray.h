#ifndef ACCESSIBLEARRAY_H
#define ACCESSIBLEARRAY_H

#include "ArrayNode.h"

#define EMPTY -1

class AccessibleArray
{
private: 
	ArrayNode* arr;
	int size;
	int headList;
	int tailList;
public:
	AccessibleArray(int _size);
	~AccessibleArray();
	void makeEmpty();
	int getSize();
	int getHeadList();
	int getTailList();
	void InsertAtTheEnd(int PC_number);
	void print();
};

#endif