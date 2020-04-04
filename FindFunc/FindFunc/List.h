#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

#include "ListNode.h"

class List
{
private:
	ListNode* first;
	ListNode* last;
	int size;
public:
	List();
	void MakeEmpty();
	bool IsEmpty();
	ListNode* First();
	ListNode* Last();
	int Size();
	void InsertAtTheEnd(ListNode* new_node);
	void Print();
	void DeleteList();
};

#endif