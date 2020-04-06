#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#include "ListNode.h"
#include "List.h"
#include "Node.h"

typedef List ItemType;
class Stack 
{
	private:
		Node *top; // Points to top of stack.
	public:
		Stack();
		~Stack();
		void makeEmpty();
		int isEmpty();
		void push(ItemType& item);
		ItemType& pop();
};

#endif