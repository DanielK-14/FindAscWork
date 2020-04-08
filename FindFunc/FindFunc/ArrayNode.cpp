#include "ArrayNode.h"

ArrayNode::ArrayNode()
{
	data = 0;
	next = -1;
}

ArrayNode::ArrayNode(int number, int nextNode)
{
	data = number;
	next = nextNode;
}

