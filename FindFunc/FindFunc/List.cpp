#include "List.h"



List::List() :size(0)
{
	MakeEmpty();
}

void List::MakeEmpty()
{
	if (size > 0)
	{
		DeleteList();
	}
	first = nullptr;
	last = nullptr;
	size = 0;
}

bool List::IsEmpty()
{
	return (size == 0);
}

ListNode* List::First()
{
	return first;;
}

ListNode* List::Last()
{
	return last;
}

int List::Size()
{
	return size;
}

void List::InsertAtTheEnd(ListNode* new_node)
{
	if (size == 0)
	{
		last = new_node;
		first = new_node;
	}
	else
	{
		last->next = new_node;
		last = new_node;
	}
	size++;
}

void List::Print()
{
	ListNode* current = first;
	while (current != nullptr)
	{
		cout << current->PC_Number << " ";
		current = current->next;
	}
}

void List::DeleteList()
{
	ListNode* current = First();
	ListNode* privous = nullptr;
	while (current != nullptr)
	{
		privous = current;
		current = current->next;
		delete privous;
	}
}