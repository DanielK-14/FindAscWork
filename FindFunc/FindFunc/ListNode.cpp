#include "ListNode.h"

ListNode::ListNode()
{
	PC_Number = 0;
	color = WHITE;
	next = NULL;
}

ListNode::ListNode(int number, int newColor, ListNode* ptr)
{
	PC_Number = number;
	color = newColor;
	next = ptr;
}

void ListNode::insertAfter(ListNode* newNode)
{
	newNode->next = next;
	next = newNode;
}

void ListNode::deleteAfter()
{
	ListNode* temp = next;

	if (next == nullptr)
	{
		return;
	}
	else
	{
		next = temp->next;
		delete temp;
	}
}