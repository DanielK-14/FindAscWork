#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

#define WHITE 0
#define BLACK 1

class ListNode
{
public:
	int PC_Number;
	ListNode* next;

	ListNode();
	ListNode(int number, ListNode* ptr = nullptr);
	void insertAfter(ListNode* newNode);
	void deleteAfter();
};

#endif 