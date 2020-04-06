#include "ListNode.h"

ListNode::ListNode()
{
	PC_Number = 0;
	next = NULL;
}

ListNode::ListNode(int number, ListNode* ptr)
{
	PC_Number = number;
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