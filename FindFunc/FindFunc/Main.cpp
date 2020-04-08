#include <iostream>
using namespace std;

#include "Utilities.h"
#include "Stack.h"
#include "ArrayNode.h"

void AccessibleList(int Moked, List*& NetStructre, int NumberOfPCs);
void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, List& AccessibleList);
void FindAccessible_NotReq(List*& NetStructre, int& Toran, int*& ColorArray, List& accessibleList);

int main()
{
    try {
        int numberOfPCs, numberOfConnections, moked;
        cin >> numberOfPCs >> numberOfConnections;
        if (cin.fail())
            throw invalid_argument("Wrong type of input.");

        List* NetStructre = new List[numberOfPCs];
        Utilities::BuildNetStructre(NetStructre, numberOfPCs, numberOfConnections);

        cin >> moked;
        if (cin.fail())
            throw invalid_argument("Wrong type of input.");
        if (!Utilities::isInputCorrect(moked, moked, numberOfPCs))
            throw (invalid_argument("Moked no exist."));

        AccessibleList(moked, NetStructre, numberOfPCs);
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}

void AccessibleList(int Moked, List*& NetStructre, int NumberOfPCs)
{
    int* ColorsArray = new int[NumberOfPCs];
    Utilities::SetAllWhite(ColorsArray, NumberOfPCs);

    List accessibleList_Req;
    List accessibleList_NotReq;

    FindAccessible(NetStructre, Moked, ColorsArray, accessibleList_Req);
    accessibleList_Req.Print();

    Utilities::SetAllWhite(ColorsArray, NumberOfPCs);
    cout << "\n- - - - - - - - - - - - - - - - -" << endl;

    FindAccessible_NotReq(NetStructre, Moked, ColorsArray, accessibleList_NotReq);
    accessibleList_NotReq.Print();

    Utilities::CleanAllMess(NetStructre, NumberOfPCs, accessibleList_Req, accessibleList_NotReq, ColorsArray);
}

void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, List& accessibleList)
{
    ColorArray[Toran - 1] = BLACK;
    ListNode* nodeToAdd = new ListNode(Toran, nullptr);
    accessibleList.InsertAtTheEnd(nodeToAdd);
    ListNode* current = NetStructre[Toran - 1].First();
    while (current != nullptr)
    {
        if (ColorArray[current->PC_Number - 1] == WHITE)
            FindAccessible(NetStructre, current->PC_Number, ColorArray, accessibleList);
        current = current->next;
    }
}

void FindAccessible_NotReq(List*& NetStructre, int& Toran, int*& ColorArray, List& accessibleList)
{
    ColorArray[Toran - 1] = BLACK;
    ListNode* nodeToAdd = new ListNode(Toran, nullptr);
    accessibleList.InsertAtTheEnd(nodeToAdd);

    Stack stack;
    stack.push(NetStructre[Toran - 1]);
    ItemType* currentList;
    ListNode* currentListNode;

    while (!(stack.isEmpty()))
    {
        currentList = &stack.pop();
        currentListNode = currentList->First();

        while (currentListNode != nullptr && NetStructre[currentListNode->PC_Number - 1].IsEmpty())
        {
            ListNode* nodeToAdd = new ListNode(currentListNode->PC_Number, nullptr);
            accessibleList.InsertAtTheEnd(nodeToAdd);
            ColorArray[currentListNode->PC_Number - 1] = BLACK;
            currentListNode = currentListNode->next;
            if (currentListNode == nullptr)
                break;
        }
        if (currentListNode != nullptr && ColorArray[currentListNode->PC_Number - 1] == WHITE)
        {
            ListNode* nodeToAdd = new ListNode(currentListNode->PC_Number, nullptr);
            accessibleList.InsertAtTheEnd(nodeToAdd);
            stack.push(*currentList);
            stack.push(NetStructre[currentListNode->PC_Number - 1]);
            ColorArray[currentListNode->PC_Number - 1] = BLACK;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void AccessibleList(int Moked, List*& NetStructre, int NumberOfPCs);
void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, List& AccessibleList);
void FindAccessible_NotReq(List*& NetStructre, int& Toran, int*& ColorArray, List& accessibleList);
void printAccessibleList(ArrayNode** array, int moked);
void addNodeToArray(ArrayNode*& array, ArrayNode newNode, int moked);


int main()
{
    try {
        int numberOfPCs, numberOfConnections, moked;
        cin >> numberOfPCs >> numberOfConnections;
        if (cin.fail())
            throw invalid_argument("Wrong type of input.");

        List* NetStructre = new List[numberOfPCs];
        Utilities::BuildNetStructre(NetStructre, numberOfPCs, numberOfConnections);

        cin >> moked;
        if (cin.fail())
            throw invalid_argument("Wrong type of input.");
        if (!Utilities::isInputCorrect(moked, moked, numberOfPCs))
            throw (invalid_argument("Moked no exist."));

        AccessibleList(moked, NetStructre, numberOfPCs);
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}

void AccessibleList(int Moked, List*& NetStructre, int NumberOfPCs)
{
    int* ColorsArray = new int[NumberOfPCs];
    Utilities::SetAllWhite(ColorsArray, NumberOfPCs);

    ArrayNode* accessibleList_Req = new ArrayNode[NumberOfPCs];
    ArrayNode* accessibleList_NotReq = new ARrayNode[NumberOfPCs];

    FindAccessible(NetStructre, Moked, ColorsArray, accessibleList_Req);
    accessibleList_Req.Print();

    Utilities::SetAllWhite(ColorsArray, NumberOfPCs);
    cout << "\n- - - - - - - - - - - - - - - - -" << endl;

    FindAccessible_NotReq(NetStructre, Moked, ColorsArray, accessibleList_NotReq);
    accessibleList_NotReq.Print();

    Utilities::CleanAllMess(NetStructre, NumberOfPCs, accessibleList_Req, accessibleList_NotReq, ColorsArray);
}

void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, ArrayNode*& accessibleList)
{
    ColorArray[Toran - 1] = BLACK;
    ArrayNode nodeToAdd = ArrayNode(Toran, -1);
    //accessibleList.InsertAtTheEnd(nodeToAdd);
    addNodeToArray(accessibleList, nodeToAdd, Toran);

    ListNode* current = NetStructre[Toran - 1].First();
    while (current != nullptr)
    {
        if (ColorArray[current->PC_Number - 1] == WHITE)
            FindAccessible(NetStructre, current->PC_Number, ColorArray, accessibleList);
        current = current->next;
    }
}

void FindAccessible_NotReq(List*& NetStructre, int& Toran, int*& ColorArray, ArrayNode*& accessibleList)
{
    ColorArray[Toran - 1] = BLACK;
    ArrayNode nodeToAdd = ArrayNode(Toran, -1);
    accessibleList.InsertAtTheEnd(nodeToAdd, Toran);
    //addNodeToArray(accessibleList, nodeToAdd, Toran);

    Stack stack;
    stack.push(NetStructre[Toran - 1]);
    ItemType* currentList;
    ListNode* currentListNode;

    while (!(stack.isEmpty()))
    {
        currentList = &stack.pop();
        currentListNode = currentList->First();

        while (currentListNode != nullptr && NetStructre[currentListNode->PC_Number - 1].IsEmpty())
        {
            //ListNode* nodeToAdd = new ListNode(currentListNode->PC_Number, nullptr);
            ArrayNode nodeToAdd = ArrayNode(currentListNode->PC_Number, -1);
            accessibleList.InsertAtTheEnd(nodeToAdd, currentListNode->PC_Number);
            //addNodeToArray(accessibleList, nodeToAdd, Toran);
            ColorArray[currentListNode->PC_Number - 1] = BLACK;
            currentListNode = currentListNode->next;
            if (currentListNode == nullptr)
                break;
        }
        if (currentListNode != nullptr && ColorArray[currentListNode->PC_Number - 1] == WHITE)
        {
            //ListNode* nodeToAdd = new ListNode(currentListNode->PC_Number, nullptr);
            ArrayNode nodeToAdd = ArrayNode(currentListNode->PC_Number, -1);
            accessibleList.InsertAtTheEnd(nodeToAdd, currentListNode->PC_Number);
            //addNodeToArray(accessibleList, nodeToAdd, Toran);
            stack.push(*currentList);
            stack.push(NetStructre[currentListNode->PC_Number - 1]);
            ColorArray[currentListNode->PC_Number - 1] = BLACK;
        }
    }
}

void printAccessibleList(ArrayNode** array, int moked)
{
    ArrayNode* current_pc = array[moked - 1];
    while (current_pc->next != -1)
    {
        cout << current_pc->PC_Number << " ";
        current_pc = array[current_pc->next - 1];
    }
    cout << current_pc->PC_Number << " ";
}

void addNodeToArray(ArrayNode*& array, ArrayNode newNode, int moked)
{
    ArrayNode* current_pc = array[moked - 1];
    while (current_pc->next != -1)
    {
        current_pc = array[current_pc->next - 1];
    }
    current_pc->next = newNode.PC_Number;
    array[newNode.PC_Number - 1].next = -1;
}