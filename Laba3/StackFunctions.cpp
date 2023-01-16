#include "Stack.h"
#include <iostream>
using namespace std;

Stack* stack = new Stack;

void Init()
{
    for (int i = 0; i < 10; i++)
    {
        Node* temp = new Node;
        temp->value = rand() % 100 - 1;

        if (stack->Head == nullptr)
        {
            stack->Head = temp;
            stack->Tail = temp;
        }
        else
        {
            temp->Next = stack->Head;
            stack->Head->Prev = temp;
            stack->Head = temp;
        }
    }
}

void Show()
{
    Node* temp = stack->Head;

    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->Next;
    }
}

void Push(int valueToPush)
{
    if (stack->Head != nullptr)
    {
        Node* temp = new Node;
        temp->value = valueToPush;

        temp->Next = stack->Head;
        stack->Head->Prev = temp;
        stack->Head = temp;
    }
    else
    {
        Node* temp = new Node;
        temp->value = valueToPush;
        stack->Head = temp;
    }
}

int Pop()
{
    int valueToReturn = NULL;
    if (stack->Head != nullptr)
    {
        valueToReturn = stack->Head->value;
        if (stack->Head->Next == nullptr)
        {
            stack->Head = stack->Tail = nullptr;
        }
        else
        {
            stack->Head->Next->Prev = nullptr;
            stack->Head = stack->Head->Next;
        }
    }
    return valueToReturn;
}

void Delete()
{
    Node* temp = stack->Head->Next;
    while (temp != nullptr)
    {
        delete temp->Prev;
        temp = temp->Next;
    }
    stack->Head = stack->Tail = nullptr;
}

void StackMenu()
{
    cout << "\n�������� �������:\n";
    cout << "1 - ������������� �����\n";
    cout << "2 - ������� �������� �����\n";
    cout << "3 - ��������� � ����\n";
    cout << "4 - ������� �� �����\n";
    cout << "5 - �������� �����\n";
    cout << "0 - ����� �� �����\n";
}

void Tabulation()
{
    cout << endl << endl << endl;
}