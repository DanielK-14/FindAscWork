#ifndef UTILITIES_H
#define UTILITIES_H

#include "List.h"

class Utilities
{
public:
	static void SetAllWhite(int* array, int size)
	{
		for (int i = 0; i < size; i++)
			array[i] = WHITE;
	}

	static void SetAllNetStructureEmpty(List*& list, int size)
	{
		for (int i = 0; i < size; i++)
			list[i].MakeEmpty();
	}

	static void DeleteArrayOfLists(List*& array, int size)
	{
		for (int i = 0; i < size; i++)
			array[i].DeleteList();
		delete[] array;
	}

	static void BuildNetStructre(List*& NetStructre, int NumOfPCs, int NumOfConnections)
	{
		SetAllNetStructureEmpty(NetStructre, NumOfPCs);

		for (int i = 0; i < NumOfConnections; i++)
		{
			int fromPC;
			int toPC;
			cin >> fromPC;
			cin >> toPC;
			if (!isInputCorrect(fromPC, toPC, NumOfPCs))
				throw (new exception("Wrong values of pc connections were inputed."));
			ListNode* addNode = new ListNode(toPC, WHITE, nullptr);
			NetStructre[fromPC - 1].InsertAtTheEnd(addNode);
		}
	}

	static bool isInputCorrect(int fromPC, int toPC, int NumOfPCs)
	{
		if (fromPC > NumOfPCs || fromPC < 0 || toPC > NumOfPCs || toPC < 0)
			return false;
		return true;
	}

	static void CleanAllMess(List*& NetStructre, int NumberOfPCs, List& list1, List& list2, int*& ColorsArray)
	{
		DeleteArrayOfLists(NetStructre, NumberOfPCs);
		list1.DeleteList();
		list2.DeleteList();
		delete[] ColorsArray;
	}
};

#endif