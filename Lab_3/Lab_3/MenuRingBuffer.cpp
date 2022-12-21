#include "MenuRingBuffer.h"
#include "RingBuffer.h"
#include <iostream>
#include "Validation.h"

using namespace std;

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