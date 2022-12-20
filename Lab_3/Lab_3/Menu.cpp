#include <iostream>
#include "Menu.h"
#include "Validation.h"
#include "Stack.h"
#include "IOStack.h"
#include "RingBuffer.h"
#include "QueueRingBuffer.h"


using namespace std;

void PrintRingBuffer(RingBuffer* buffer);
void PrintQueueRingBuffer(QueueRingBuffer* queue);

void Menu()
{
	while (true) 
	{		
		cout << "1. Работа со стеком." << endl;
		cout << "2. Работа с кольцевым буффером." << endl;
		cout << "3. Работа с очередью на основе кольцевого буфера." << endl;
		cout << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		switch (key)
		{
		case 1:
			system("cls");
			MenuStack();
			break;
		case 2:
			system("cls");
			MenuRingBuffer();
			break;
		case 3:
			system("cls");
			MenuQueueRingBuffer();
			break;
		default:
			cout << "Некорректный номер." << endl;
			break;
		}
	}
}

void MenuStack()
{
	Stack* stack = nullptr;

	cout << "Стек" << endl;

	while (true)
	{
		cout << "0. Очистить консоль." << endl;
		cout << "1. Создать стек." << endl;
		cout << "2. Добавить элемент в стек." << endl;
		cout << "3. Получить элемент из стека." << endl;
		cout << "4. Удалить стек." << endl;
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
			stack = CreateStack(stack);
			break;
		case 2:
			PushStack(stack);
			break;
		case 3:
			PopStack(stack);
			break;
		case 4:
			DeleteStack(stack);
			stack = nullptr;
			break;
		case 5:
			DeleteStack(stack);
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

void MenuRingBuffer()
{
	RingBuffer* buffer = new RingBuffer();
	
	cout << "Кольцевой буфер" << endl;

	int size = CheckingForDigit("Введите размер кольцевого буфера: ");
	buffer = InitRingBuffer(size);

	while (true)
	{
		cout << "0. Очистить консоль." << endl;
		cout << "1. Вывести свободное место." << endl;
		cout << "2. Вывести занятое место." << endl;
		cout << "3. Добавить элемент в буфер." << endl;
		cout << "4. Достать элемент из буфера." << endl;
		cout << "5. Увеличить размер кольцевого буфера." << endl;
		cout << "6. Вернуться назад." << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (key)
		{
		case 0:
			system("cls");
			break;
		case 1:
			cout << "Свободное место в буфере: " << FreeMemoryInfo(buffer) << endl;
			break;
		case 2:
			cout << "Занятое место в буфере: " << UsedMemoryInfo(buffer) << endl;
			break;
		case 3:
		{
			int value = CheckingForDigit("Введите добавляемое значение: ");
			PushRingBuffer(buffer, value);
			PrintRingBuffer(buffer);
			break;
		}
		case 4:
			if (UsedMemoryInfo(buffer) > 0) 
			{
				cout << "Значение из буфера: " << PopRingBuffer(buffer) << endl;
				PrintRingBuffer(buffer);
			}
			else 
			{
				cout << "Буфер пуст." << endl;
			}

			break;
		case 5:
			ResizeRingBuffer(buffer);
			cout << "Новый размер буфера = " << buffer->Size << endl;
			break;
		case 6:
			delete[] buffer->Buffer;
			delete buffer;
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
				}	
				PrintQueueRingBuffer(queue);
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

void PrintRingBuffer(RingBuffer* buffer)
{
	int index = buffer->IndexOutput;

	for (int i = 0; i < buffer->UsedMemory; i++)
	{
		cout << buffer->Buffer[index++] << " -> ";

		if (index > buffer->Size - 1)
		{
			index = 0;
		}
	}

	cout << endl;
	cout << "Размер буфера: " << buffer->Size << endl;
}

void PrintQueueRingBuffer(QueueRingBuffer* queue) 
{
	PrintRingBuffer(queue->Buffer);
}
