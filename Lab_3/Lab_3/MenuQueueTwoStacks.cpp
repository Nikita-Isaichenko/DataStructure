#include "MenuQueueTwoStacks.h"
#include "Validation.h"
#include <iostream>
#include "QueueTwoStacks.h"
#include "IOStack.h"

using namespace std;


void MenuQueueTwoStacks()
{
	QueueTwoStacks* queue = nullptr;

	cout << "Очередь на основе двух стеков." << endl;

	while (true)
	{
		cout << "0. Очистить консоль." << endl;
		cout << "1. Создание очереди." << endl;
		cout << "2. Добавить элемент в очередь." << endl;
		cout << "3. Достать элемент из очереди." << endl;
		cout << "4. Удалить очередь." << endl;
		cout << "5. Вернуться назад." << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (key)
		{
		case 0:
			system("cls");
			break;
		case 1:
		{
			int size = CheckingForDigit("Введите размер очереди: ");

			queue = new QueueTwoStacks();

			if (size < 4)
			{
				cout << "Введенный размер меньше минимального (4)"
					"поэтому размер приведен к минимальному." << endl;
				size = 4;
			}

			queue = InitQueueTwoStacks(size);
		}
			break;
		case 2:
		{
			int data = CheckingForDigit("Введите значение: ");
			Enqueue(queue, data);
			PrintQueueTwoStacks(queue);
		}
			break;
		case 3:
			if (queue)
			{
				if (LengthQueueTwoStacks(queue) > 0)
				{
					cout << "Полученный элемент: " << Dequeue(queue) << endl;
					PrintQueueTwoStacks(queue);
				}
				else
				{
					cout << "Очередь пуста." << endl;
				}
			}
			else
			{
				cout << "Очередь не создана. Создайте очередь." << endl;
			}

			break;
		case 4:
			if (queue)
			{
				DeleteQueueTwoStacks(queue);
				delete queue;
				queue = nullptr;
				
				cout << "Очередь удалена." << endl;
			}
			else
			{
				cout << "Очередь не создана. Создайте очередь." << endl;
			}

			break;
		case 5:
			system("cls");
			if (queue != nullptr)
			{
				DeleteQueueTwoStacks(queue);
				delete queue;
			}
			
			return;
		default:
			cout << "Некорректный номер." << endl;
			break;
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;

	}
}

void PrintQueueTwoStacks(QueueTwoStacks* queue)
{
	cout << "Стек для входных данных." << endl;

	PrintStack(queue->InputStack);

	cout << endl;
	cout << "Стек для выходных данных." << endl;

	PrintStack(queue->OutputStack);

	cout << endl;
}
