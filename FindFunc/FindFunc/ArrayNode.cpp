#include "ArrayNode.h"

ArrayNode::ArrayNode()
{
	PC_Number = 0;
	next = -1;
}

ArrayNode::ArrayNode(int number, int nextNode)
{
	PC_Number = number;
	next = nextNode;
}

void ArrayNode::insertAfter(ArrayNode newNode)
{

}

void ArrayNode::deleteAfter()
{

}

