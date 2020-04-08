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

void ArrayNode::insertAfter(ArrayNode newNode, int head)
{
    ArrayNode* current_pc = array[head - 1];
    while (current_pc->next != -1)
    {
        current_pc = array[current_pc->next - 1];
    }
    current_pc->next = newNode.PC_Number;
    array[newNode.PC_Number - 1].next = -1;
}

void ArrayNode::deleteAfter()
{

}

