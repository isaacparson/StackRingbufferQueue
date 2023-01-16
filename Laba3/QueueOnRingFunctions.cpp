#include "QueueOnRingFunctions.h"
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

void QueueORInit()
{
	QueueOnRing* buffer = new QueueOnRing;
	buffer->value = NULL;
	QueueOR->Head = buffer;

	for (int i = 0; i < 10; i++)
	{
		QueueOnRing* buffer = new QueueOnRing;
		buffer->value = NULL;
		QueueOR->Head->Next = buffer;
		QueueOR->Head = buffer;
	}
	QueueOR->Oldest = QueueOR->Head;
}

void QueueORShow()
{
	QueueOnRing* temp = QueueOR->Head;
	while (temp->Next != nullptr)
	{
		cout << temp->value << " ";
	}
}


