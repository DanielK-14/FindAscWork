#include <iostream>
using namespace std;

#include "Utilities.h"
#include "Stack.h"
#include "AccessibleArray.h"

void AccessibleList(int Moked, List*& NetStructre, int NumberOfPCs);
void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, AccessibleArray& accessibleArray);
void FindAccessible_NotReq(List*& NetStructre, int& Toran, int*& ColorArray, AccessibleArray& accessibleArray);

int main()
{
    try {
        int numberOfPCs, numberOfConnections, moked;
        cin >> numberOfPCs >> numberOfConnections;
        if (cin.fail() || numberOfPCs < 1)
            throw invalid_argument("Wrong type of input.");

        List* NetStructre = new List[numberOfPCs];
        Utilities::BuildNetStructre(NetStructre, numberOfPCs, numberOfConnections);

        cin >> moked;
        if (cin.fail())
            throw invalid_argument("Wrong type of input.");
        if (!Utilities::isInputCorrect(moked, moked, numberOfPCs))
            throw invalid_argument("Moked no exist.");

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

    AccessibleArray accessibleList_Req(NumberOfPCs);
    AccessibleArray accessibleList_NotReq(NumberOfPCs);

    FindAccessible(NetStructre, Moked, ColorsArray, accessibleList_Req);
    accessibleList_Req.print();

    Utilities::SetAllWhite(ColorsArray, NumberOfPCs);
    cout << "\n- - - - - - - - - - - - - - - - -" << endl;

    FindAccessible_NotReq(NetStructre, Moked, ColorsArray, accessibleList_NotReq);
    accessibleList_NotReq.print();

    Utilities::CleanAllMess(NetStructre, NumberOfPCs, ColorsArray);
}

void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, AccessibleArray& accessibleArray)
{
    ColorArray[Toran - 1] = BLACK;
    accessibleArray.InsertAtTheEnd(Toran);

    ListNode* current = NetStructre[Toran - 1].First();
    while (current != nullptr)
    {
        if (ColorArray[current->PC_Number - 1] == WHITE)
            FindAccessible(NetStructre, current->PC_Number, ColorArray, accessibleArray);
        current = current->next;
    }
}

void FindAccessible_NotReq(List*& NetStructre, int& Toran, int*& ColorArray, AccessibleArray& accessibleArray)
{
    ColorArray[Toran - 1] = BLACK;
    accessibleArray.InsertAtTheEnd(Toran);
    int counter = 0;

    Stack stack;
    stack.push(NetStructre[Toran - 1]);
    ItemType* currentList;
    ListNode* currentListNode;

    while (!(stack.isEmpty()))
    {
        currentList = &stack.pop();
        currentListNode = currentList->First();

        while (currentListNode != nullptr)
        {
            if (NetStructre[currentListNode->PC_Number - 1].IsEmpty() && ColorArray[currentListNode->PC_Number - 1] == WHITE)
            {
                accessibleArray.InsertAtTheEnd(currentListNode->PC_Number);
                ColorArray[currentListNode->PC_Number - 1] = BLACK;
                currentListNode = currentListNode->next;
            }
            else if (ColorArray[currentListNode->PC_Number - 1] == WHITE)
            {
                accessibleArray.InsertAtTheEnd(currentListNode->PC_Number);
                stack.push(*currentList);
                stack.push(NetStructre[currentListNode->PC_Number - 1]);
                ColorArray[currentListNode->PC_Number - 1] = BLACK;
                break;
            }
            else
                currentListNode = currentListNode->next;
        }
    }
}