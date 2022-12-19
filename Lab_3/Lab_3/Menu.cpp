#include <iostream>
#include "Menu.h"
#include "Validation.h"
#include "Stack.h"
#include "IOStack.h"
#include "RingBuffer.h"

using namespace std;

void PrintRingBuffer(RingBuffer* buffer);

void Menu()
{
	while (true) 
	{		
		cout << "1. Работа со стеком." << endl;
		cout << "2. Работа с кольцевым буффером." << endl;
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
			delete stack;
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
	InitRingBuffer(buffer);
	
	cout << "Кольцевой буфер" << endl;

	while (true)
	{
		cout << "0. Очистить консоль." << endl;
		cout << "1. Вывести свободное место." << endl;
		cout << "2. Вывести занятое место." << endl;
		cout << "3. Добавить элемент в буфер." << endl;
		cout << "4. Достать элемент из буфера." << endl;
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
			cout << "Свободное место в буфере: " << FreeMemoryInfo(buffer) << endl;
			break;
		case 2:
			cout << "Занятое место в буфере: " << UsedMemoryInfo(buffer) << endl;
			break;
		case 3:
		{
			int value = CheckingForDigit("Введите добавляемое значение: ");
			Push(buffer, value);
			PrintRingBuffer(buffer);
			break;
		}
		case 4:
			if (UsedMemoryInfo(buffer) > 0) 
			{
				cout << "Значение из буфера: " << Pop(buffer) << endl;
				PrintRingBuffer(buffer);
			}
			else 
			{
				cout << "Буфер пуст." << endl;
			}

			break;
		case 5:
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
	cout << "Размер буфера: " << buffer->Size;
}