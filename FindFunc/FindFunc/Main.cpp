#include <iostream>
using namespace std;

/// Hello
#include "Utilities.h"
#include "Stack.h"

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