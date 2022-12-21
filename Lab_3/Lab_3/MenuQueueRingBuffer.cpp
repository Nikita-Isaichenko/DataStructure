#include "MenuQueueRingBuffer.h"
#include <iostream>
#include "Validation.h"
#include "MenuRingBuffer.h"

using namespace std;


void MenuQueueRingBuffer()
{
	QueueRingBuffer* queue = nullptr;

	cout << "Очередь на основе кольцевого буфера." << endl;

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
			if (queue != nullptr)
			{
				cout << "Очередь уже создана." << endl;
			}
			else
			{
				int size = CheckingForDigit("Введите размер очереди: ");
				queue = InitQueueRingBuffer(size);
				cout << "Очередь создана" << endl;
			}

			break;
		case 2:
			if (queue != nullptr)
			{
				int value = CheckingForDigit("Введите значение: ");
				EnqueueRingBuffer(queue, value);
				PrintQueueRingBuffer(queue);
			}
			else
			{
				cout << "Создайте очередь!" << endl;
			}

			break;
		case 3:
			if (queue != nullptr)
			{
				if (LenghtQueueRingBuffer(queue) > 0)
				{
					cout << "Значение: " << DequeueRingBuffer(queue) << endl;
					PrintQueueRingBuffer(queue);
				}
				else 
				{
					cout << "Очередь пуста." << endl;
				}
			}
			else
			{
				cout << "Создайте очередь!" << endl;
			}

			break;
		case 4:
			if (queue != nullptr)
			{
				DeleteQueueRingBuffer(queue);
				delete queue;
				queue = nullptr;
				cout << "Очеред удалена." << endl;
			}

			break;
		case 5:
			system("cls");
			return;
		default:
			cout << "Некорректный номер." << endl;
			break;
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;

	}
}

void PrintQueueRingBuffer(QueueRingBuffer* queue)
{
	PrintRingBuffer(queue->Buffer);
}

