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
	int color;
	ListNode* next;

	ListNode();
	ListNode(int number, int newColor, ListNode* ptr = nullptr);
	void insertAfter(ListNode* newNode);
	void deleteAfter();
};

#endif 