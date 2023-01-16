#include "QueueORFunctions.h"
#include <iostream>

using namespace std;

QueueOnRingList* QueueOR = new QueueOnRingList;


void QueueORMenu()
{
	cout << "Введите номер функции:\n";
	cout << "1 - Инициализация\n";
	cout << "2 - Вывод\n";
	cout << "3 - Добавить в очередь\n";
	cout << "4 - Извлечь из очереди\n";
	cout << "5 - Удаление очереди\n";
}

void QueueORInit(int length)
{
	QueueOnRing* buffer = new QueueOnRing;
	buffer->value = NULL;
	QueueOR->Head = buffer;
	QueueOR->Oldest = buffer;

	for (int i = 0; i < 10; i++)
	{
		QueueOnRing* buffer = new QueueOnRing;
		buffer->value = NULL;
		QueueOR->Head->Next = buffer;
		QueueOR->Head = buffer;
	}
}

void QueueORShow()
{
	if (QueueOR->Oldest != nullptr)
	{
		QueueOnRing* temp = QueueOR->Oldest;
		while (temp->Next != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->Next;
		}
		cout << temp->value << " ";
	}
}

void EnqueueOR()
{
	int valueToAdd;
	bool isAdd = 0;
	cin >> valueToAdd;
	QueueOnRing* temp = QueueOR->Oldest;

	while (temp->Next != nullptr)
	{
		if (QueueOR->Newest != nullptr && QueueOR->Newest->Next != nullptr)
		{
			if (QueueOR->Newest->Next->value == NULL)
			{
				QueueOR->Newest->Next->value = valueToAdd;
				QueueOR->Newest = QueueOR->Newest->Next;
				isAdd = 1;
				break;
			}
		}
		if (temp->value == NULL)
		{
			temp->value = valueToAdd;
			QueueOR->Newest = temp;
			isAdd = 1;
			break;
		}
		temp = temp->Next;
	}
	if (isAdd == 0 && QueueOR->Newest != nullptr)
	{
		QueueOnRing* newTemp = new QueueOnRing;
		newTemp->value = valueToAdd;
		QueueOR->Newest->Next = newTemp;
		QueueOR->Newest = newTemp;
		cout << QueueOR->Newest->value;
	}

}

void DequeueOR()
{
	if (QueueOR->Oldest != nullptr)
	{
		cout << QueueOR->Oldest->value;
		QueueOR->Oldest->value = NULL;
		QueueOR->Oldest = QueueOR->Oldest->Next;
	}
}

void DeletQueueOR()
{
	QueueOnRing* temp = new QueueOnRing;
	for (int i = 0; i < 9; i++)
	{
		temp = QueueOR->Oldest;
		QueueOR->Oldest = temp->Next;
		temp = nullptr;
	}
	QueueOR->Head = nullptr;
	QueueOR->Oldest = nullptr;
	QueueOR->Newest = nullptr;
}