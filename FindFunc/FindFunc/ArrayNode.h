#ifndef ARRAYNODE_H
#define ARRAYNODE_H

#include <iostream>
using namespace std;

#define WHITE 0
#define BLACK 1

class ArrayNode
{
public:
	int PC_Number;
	int next;

	ArrayNode();
	ArrayNode(int number, int next);
	void insertAfter(ArrayNode newNode, int head);
	void deleteAfter();
};

#endif 