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
		cout << "1. ������ �� ������." << endl;
		cout << "2. ������ � ��������� ��������." << endl;
		cout << "3. ������ � �������� �� ������ ���������� ������." << endl;
		cout << endl;

		int key = CheckingForDigit("������� ����� ��������: ");

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
			cout << "������������ �����." << endl;
			break;
		}
	}
}

void MenuStack()
{
	Stack* stack = nullptr;

	cout << "����" << endl;

	while (true)
	{
		cout << "0. �������� �������." << endl;
		cout << "1. ������� ����." << endl;
		cout << "2. �������� ������� � ����." << endl;
		cout << "3. �������� ������� �� �����." << endl;
		cout << "4. ������� ����." << endl;
		cout << "5. ��������� �����." << endl;

		int key = CheckingForDigit("������� ����� ��������: ");

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
			cout << "������������ �����." << endl;
			break;
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	}
}

void MenuRingBuffer()
{
	RingBuffer* buffer = new RingBuffer();
	
	cout << "��������� �����" << endl;

	int size = CheckingForDigit("������� ������ ���������� ������: ");
	buffer = InitRingBuffer(size);

	while (true)
	{
		cout << "0. �������� �������." << endl;
		cout << "1. ������� ��������� �����." << endl;
		cout << "2. ������� ������� �����." << endl;
		cout << "3. �������� ������� � �����." << endl;
		cout << "4. ������� ������� �� ������." << endl;
		cout << "5. ��������� ������ ���������� ������." << endl;
		cout << "6. ��������� �����." << endl;

		int key = CheckingForDigit("������� ����� ��������: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (key)
		{
		case 0:
			system("cls");
			break;
		case 1:
			cout << "��������� ����� � ������: " << FreeMemoryInfo(buffer) << endl;
			break;
		case 2:
			cout << "������� ����� � ������: " << UsedMemoryInfo(buffer) << endl;
			break;
		case 3:
		{
			int value = CheckingForDigit("������� ����������� ��������: ");
			PushRingBuffer(buffer, value);
			PrintRingBuffer(buffer);
			break;
		}
		case 4:
			if (UsedMemoryInfo(buffer) > 0) 
			{
				cout << "�������� �� ������: " << PopRingBuffer(buffer) << endl;
				PrintRingBuffer(buffer);
			}
			else 
			{
				cout << "����� ����." << endl;
			}

			break;
		case 5:
			ResizeRingBuffer(buffer);
			cout << "����� ������ ������ = " << buffer->Size << endl;
			break;
		case 6:
			delete[] buffer->Buffer;
			delete buffer;
			system("cls");
			return;
		default:
			cout << "������������ �����." << endl;
			break;
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	
	}
}

void MenuQueueRingBuffer()
{
	QueueRingBuffer* queue = nullptr;

	cout << "������� �� ������ ���������� ������." << endl;

	while (true)
	{
		cout << "0. �������� �������." << endl;
		cout << "1. �������� �������." << endl;
		cout << "2. �������� ������� � �������." << endl;
		cout << "3. ������� ������� �� �������." << endl;
		cout << "4. ������� �������." << endl;
		cout << "5. ��������� �����." << endl;

		int key = CheckingForDigit("������� ����� ��������: ");

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
				cout << "������� ��� �������." << endl;
			}
			else
			{
				int size = CheckingForDigit("������� ������ �������: ");
				queue = InitQueueRingBuffer(size);
				cout << "������� �������" << endl;
			}

			break;
		case 2:
			if (queue != nullptr) 
			{
				int value = CheckingForDigit("������� ��������: ");
				EnqueueRingBuffer(queue, value);
				PrintQueueRingBuffer(queue);
			}
			else 
			{
				cout << "�������� �������!" << endl;
			}

			break;
		case 3:
			if (queue != nullptr)
			{
				if (LenghtQueueRingBuffer(queue) > 0)
				{
					cout << "��������: " << DequeueRingBuffer(queue) << endl;
				}	
				PrintQueueRingBuffer(queue);
			}
			else
			{
				cout << "�������� �������!" << endl;
			}

			break;
		case 4:
			if (queue != nullptr) 
			{
				DeleteQueueRingBuffer(queue);
				delete queue;
				queue = nullptr;
				cout << "������ �������." << endl;
			}
			
			break;
		case 5:
			system("cls");
			return;
		default:
			cout << "������������ �����." << endl;
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
	cout << "������ ������: " << buffer->Size << endl;
}

void PrintQueueRingBuffer(QueueRingBuffer* queue) 
{
	PrintRingBuffer(queue->Buffer);
}
