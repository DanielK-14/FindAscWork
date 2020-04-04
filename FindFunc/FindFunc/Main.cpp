#include <iostream>
using namespace std;

#include "Utilities.h"
//#include "Stack.h"

void AccessibleList(int Moked, List*& NetStructre, int NumberOfPCs);
void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, List& AccessibleList);

int main()
{
    try {
        int numberOfPCs, numberOfConnections, moked;
        cin >> numberOfPCs >> numberOfConnections;

        List* NetStructre = new List[numberOfPCs];
        Utilities::BuildNetStructre(NetStructre, numberOfPCs, numberOfConnections);

        cin >> moked;
        Utilities::isInputCorrect(moked, moked, numberOfPCs);

        AccessibleList(moked, NetStructre, numberOfPCs);
    }
    catch (exception ex)
    {
        cout << ex.what << endl;
        exit(1);
    }
}

void AccessibleList(int Moked, List*& NetStructre, int NumberOfPCs)
{
    int* ColorsArray = new int[NumberOfPCs];
    Utilities::SetAllWhite(ColorsArray, NumberOfPCs);

    List accessibleList_Req;
    List accessibleList1_NotReq;

    FindAccessible(NetStructre, Moked, ColorsArray, accessibleList_Req);
    accessibleList_Req.Print();

    FindAccessible_NotReq
        accessibleList_NotReq.Print();

    Utilities::CleanAllMess(NetStructre, NumberOfPCs, accessibleList_Req, accessibleList1_NotReq, ColorsArray);
}

void FindAccessible(List*& NetStructre, int& Toran, int*& ColorArray, List& accessibleList)
{
    ColorArray[Toran - 1] = BLACK;
    ListNode* nodeToAdd = new ListNode(Toran, BLACK, nullptr);
    accessibleList.InsertAtTheEnd(nodeToAdd);
    ListNode* current = NetStructre[Toran - 1].First();
    while (current != nullptr)
    {
        if (ColorArray[current->PC_Number - 1] == WHITE)
            FindAccessible(NetStructre, current->PC_Number, ColorArray, accessibleList);
        current = current->next;
    }
}