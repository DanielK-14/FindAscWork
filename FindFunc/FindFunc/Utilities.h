#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdexcept>
#include <string>
#include "List.h"
#include "AccessibleArray.h"

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
			{
				throw (invalid_argument("Wrong values of pc connections were inputed."));
			}
			ListNode* addNode = new ListNode(toPC, nullptr);
			NetStructre[fromPC - 1].InsertAtTheEnd(addNode);
		}
	}

	static bool isInputCorrect(int fromPC, int toPC, int NumOfPCs)
	{
		if (fromPC > NumOfPCs || fromPC < 0)
			throw invalid_argument("no such computer " + to_string(fromPC));
		if (toPC > NumOfPCs || toPC < 0)
			throw invalid_argument("no such computer " + to_string(toPC));
		return true;
	}

	static void CleanAllMess(List*& NetStructre, int NumberOfPCs, int*& ColorsArray)
	{
		DeleteArrayOfLists(NetStructre, NumberOfPCs);
		delete[] ColorsArray;
	}
};

#endif