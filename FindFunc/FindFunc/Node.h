#ifndef NODE_H
#define NODE_H

#include "List.h"

class Node 
{
private:
	List* data;
	Node* next;

public:
	Node(List* _data, Node* _next);
};

#endif 