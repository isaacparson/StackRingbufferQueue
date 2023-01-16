#include "RingBufferFunctions.h"
#include <iostream>
using namespace std;

RingBufferList* RingList = new RingBufferList;

void RingMenu()
{
	cout << "Выберите функцию:\n";
	cout << "1 - Инициализация\n";
	cout << "2 - Заполнение\n";
	cout << "3 - Вывод\n";
	cout << "4 - Достать элемент\n";
	cout << "5 - Свободное место\n";
	cout << "6 - Занятое место\n";
	cout << "0 - Выйти из Кольцевого буфера\n";
}

void RingInit(int length)
{
	RingBuffer* buffer = new RingBuffer;
	buffer->value = NULL;
	RingList->Head = buffer;
	RingBuffer* temp = buffer;
	
	for (int i = 0; i < length; i++)
	{
		RingBuffer* buffer = new RingBuffer;
		buffer->value = NULL;
		RingList->Head->Next = buffer;
		RingList->Head = buffer;
	}
	RingList->Head->Next = temp;
	RingList->Oldest = RingList->Head;
}

void RingAdd()
{
	int isOccupied = 0;
	int valueToAdd;
	RingBuffer* temp = RingList->Head;
	for (int i = 0; i < 10; i++)
	{

		if (RingList->Newest != nullptr)
		{
			if (RingList->Newest->Next->value == NULL)
			{
				cin >> valueToAdd;
				RingList->Newest->Next->value = valueToAdd;
				RingList->Newest = RingList->Newest->Next;
				break;
			}
		}
		
		if (temp->value == NULL)
		{
			cin >> valueToAdd;
			temp->value = valueToAdd;
			RingList->Newest = temp;
			break;
		}
		else
		{
			isOccupied++;
		}

		temp = temp->Next;
	}
	if (isOccupied == 10)
	{
		cin >> valueToAdd;
		RingList->Oldest->value = valueToAdd;
		RingList->Oldest = RingList->Oldest->Next;
	}
}

void RingShow()
{
	RingBuffer* temp = RingList->Head;
	for (int i = 0; i < 10; i++)
	{
		cout << temp->value << " ";
		temp = temp->Next;
	}
}

int FreeSpace()
{
	int countFree = 0;
	RingBuffer* temp = RingList->Head;
	for (int i = 0; i < 10; i++)
	{
		if (temp->value == NULL)
		{
			countFree++;
		}
		temp = temp->Next;
	}
	return countFree;
}

int OccupiedSpace()
{
	return 10 - FreeSpace();
}

void RingPop()
{
	cout << RingList->Oldest->value;
	RingList->Oldest->value = NULL;
	RingList->Oldest = RingList->Oldest->Next;

}
