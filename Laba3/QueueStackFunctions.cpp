#include "QueueStackFunctions.h"
#include "Stack.h"
#include <iostream>
using namespace std;

Stack* stack1 = new Stack;
Stack* stack2 = new Stack;

void QueueStackMenu()
{
	cout << "Выберите функцию:\n";
	cout << "1 - Инициализация очереди на базе двух стеков\n";
	cout << "2 - Вывод \n";
    cout << "3 - Извлечение из очереди\n";
	cout << "4 - Добавление в очередь\n";
    cout << "5 - Удаление очереди\n";
    cout << "0 - Выйти\n";
}

void QueueStackInit()
{
    for (int i = 0; i < 10; i++)
    {
        Node* temp = new Node;
        temp->value = rand() % 100 - 1;

        if (stack1->Head == nullptr)
        {
            stack1->Head = temp;
            stack1->Tail = temp;
        }
        else
        {
            temp->Next = stack1->Head;
            stack1->Head->Prev = temp;
            stack1->Head = temp;
        }
    }
}

void QueueStackShow()
{
    Node* temp = stack1->Head;
    if (temp != nullptr)
    {
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->Next;
        }
    }

    temp = stack2->Head;
    if (temp != nullptr)
    {
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->Next;
        }
    }
}

void QueueStackDequeue()
{
    if (stack2->Head == nullptr && stack1->Head != nullptr)
    {
        if (stack1->Tail->Prev != nullptr)
        {
            Node* temp1 = stack1->Tail;
            Node* temp = new Node;
            stack2->Head = temp;
            temp->value = temp1->value;
            stack1->Tail->Prev->Next = nullptr;
            stack1->Tail = stack1->Tail->Prev;
            stack2->Tail = stack2->Head;

            while (stack1->Tail->Prev != nullptr)
            {
                Node* temp = new Node;
                temp->value = stack1->Tail->value;
                stack2->Tail->Next = temp;
                temp->Prev = stack2->Tail;
                stack2->Tail = temp;
                stack1->Tail->Prev->Next = nullptr;
                stack1->Tail = stack1->Tail->Prev;
            }
            Node* buf = new Node;
            buf->value = stack1->Tail->value;
            stack2->Tail->Next = buf;
            buf->Prev = stack2->Tail;
            stack2->Tail = buf;
            stack1->Head = nullptr;
            stack1->Tail = nullptr;

            cout << stack2->Tail->value;
            stack2->Tail = stack2->Tail->Prev;
            stack2->Tail->Next = nullptr;
        }
        else
        {
            cout << stack1->Tail->value;
            stack1->Head = nullptr;
            stack1->Tail = nullptr;
        }
    }
    else
    {
        if (stack2->Tail != nullptr) {
            if (stack2->Tail->Prev != nullptr)
            {
                cout << stack2->Tail->value;
                stack2->Tail = stack2->Tail->Prev;
                stack2->Tail->Next = nullptr;
            }
            else
            {
                cout << stack2->Tail->value;
                stack2->Head = nullptr;
                stack2->Tail = nullptr;
            }
        }
    }
}
void QueueStackEnqueue()
{
    int valueToAdd;
    cin >> valueToAdd;
    Node* temp = new Node;
    temp->value = valueToAdd;

    if (stack1->Head == nullptr)
    {
        stack1->Head = temp;
        stack1->Tail = stack1->Head;
    }
    else
    {
        stack1->Tail->Next = temp;
        temp->Prev = stack1->Tail;
        stack1->Tail = temp;
    }
}

void QueueStackDelete()
{
    if (stack1->Head != nullptr)
    {
        Node* temp = stack1->Head->Next;
        while (temp != nullptr)
        {
            delete temp->Prev;
            temp = temp->Next;
        }
        stack1->Head = stack1->Tail = nullptr;
    }
    
    if (stack2->Head != nullptr)
    {
        Node* temp = stack2->Head->Next;
        while (temp != nullptr)
        {
            delete temp->Prev;
            temp = temp->Next;
        }
        stack2->Head = stack2->Tail = nullptr;

    }
}
