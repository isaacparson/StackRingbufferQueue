#include <iostream>
#include <locale.h>
#include "Stack.h"
#include "StackFunctions.h"
#include "RingBuffer.h"
#include "RingBufferFunctions.h"
#include "QueueOR.h"
#include "QueueORFunctions.h"
#include "QueueStackFunctions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int stackVariant;
    int menuVariant;
    while (true)
    {
        cout << "\nВыберите структуру данных:\n";
        cout << "1 - Стек\n";
        cout << "2 - Кольцевой буфер\n";
        cout << "3 - Очередь на базе кольцевого буфера\n";
        cout << "4 - Очередь на базе двух стеков\n";
        cin >> menuVariant;

        switch (menuVariant)
        {
        case 1:
        {
            stackVariant = 1;
            while (stackVariant != 0)
            {
                StackMenu();
                cin >> stackVariant;

                switch (stackVariant)
                {
                case 1:
                {
                    Init();
                    Tabulation();
                    break;
                }
                case 2:
                {
                    Show();
                    Tabulation();
                    break;
                }
                case 3:
                {
                    int valueToPush;
                    cout << "Введите значение которое хотите добавить: ";
                    cin >> valueToPush;
                    Push(valueToPush);
                    Tabulation();
                    break;
                }
                case 4:
                {
                    cout << Pop();
                    Tabulation();
                    break;
                }
                case 5:
                {
                    Delete();
                    Tabulation();
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            int ringVariant = 1;
            while (ringVariant != 0)
            {
                RingMenu();
                cin >> ringVariant;

                switch (ringVariant)
                {
                case 1:
                {
                    RingInit(10);
                    Tabulation();
                    break;
                }
                case 2:
                {
                    RingAdd();
                    Tabulation();
                    break;
                }
                case 3:
                {
                    RingShow();
                    Tabulation();
                    break;
                }
                case 4:
                {
                    RingPop();
                    Tabulation();
                    break;
                }
                case 5:
                {
                    cout << "Свободного места: " << FreeSpace();
                    Tabulation();
                    break;
                }
                case 6:
                {
                    cout << "Занятого места: " << OccupiedSpace();
                    Tabulation();
                    break;
                }
                }

            }

            break;
        }
        case 3:
        {
            int QueueORVariant = 1;
            while (QueueORVariant != 0)
            {
                QueueORMenu();
                cin >> QueueORVariant;

                switch (QueueORVariant)
                {
                case 1:
                {
                    QueueORInit(10);
                    Tabulation();
                    break;
                }
                case 2:
                {
                    QueueORShow();
                    Tabulation();
                    break;
                }
                case 3:
                {
                    EnqueueOR();
                    Tabulation();
                    break;
                }
                case 4:
                {
                    DequeueOR();
                    Tabulation();
                    break;
                }
                case 5:
                {
                    DeletQueueOR();
                    Tabulation();
                    break;
                }
                }
            }
            break;
        }
        case 4:
        {
            int QueueStackVariant = 1;
            while (QueueStackVariant != 0)
            {
                QueueStackMenu();
                cin >> QueueStackVariant;

                switch (QueueStackVariant)
                {
                case 1:
                {
                    QueueStackInit();
                    Tabulation();
                    break;
                }
                case 2:
                {
                    QueueStackShow();
                    Tabulation();
                    break;
                }
                case 3:
                {
                    QueueStackDequeue();
                    Tabulation();
                    break;
                }
                case 4:
                {
                    QueueStackEnqueue();
                    Tabulation();
                    break;
                }
                case 5:
                {
                    QueueStackDelete();
                    Tabulation();
                    break;
                }
                }
            }
            break;
        }
        }
    }
}