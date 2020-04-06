#include "Stack.h"
#include "Node.h"

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	makeEmpty();
}

void Stack::makeEmpty()
{
	ItemType *temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

int Stack::isEmpty()
{
	return(top == nullptr);
}

void Stack::push(ItemType* item)
{
	top = new Node(item,top);
}

ItemType* Stack::pop()
{
	if (isEmpty())
	{
		cout << "Error: STACK UNDERFLOW\n";
		exit(1);
	}
	ItemType* temp = top;
	ItemType* item = top->data;
	top = top->next;
	delete temp;
	return item;
}
