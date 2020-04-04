//#include "Stack.h"
//
//Stack::Stack()
//{
//	top = NULL;
//}
//
//Stack::~Stack()
//{
//	makeEmpty();
//}
//
//void Stack::makeEmpty()
//{
//	ItemType *temp;
//	while (top != NULL)
//	{
//		temp = top;
//		top = top->next;
//		delete temp;
//	}
//}
//
//int Stack::isEmpty()
//{
//	return(top == NULL);
//}
//
//void Stack::push(ItemType item)
//{
//	top = new ItemType(item.top);
//}
//
//ItemType Stack::pop()
//{
//	if (isEmpty())
//	{
//		cout << "Error: STACK UNDERFLOW\n";
//		exit(1);
//	}
//	ItemType * temp = top;
//	Type item = top->data;
//	top = top->next;
//	delete temp;
//	return item;
//}
