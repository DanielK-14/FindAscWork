#ifndef ARRAYNODE_H
#define ARRAYNODE_H

#include <iostream>
using namespace std;

class ArrayNode
{
public:
	int data;
	int next;

	ArrayNode();
	ArrayNode(int number, int next);
};

#endif 