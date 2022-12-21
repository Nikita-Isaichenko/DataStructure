#include "MenuQueueRingBuffer.h"
#include <iostream>
#include "Validation.h"
#include "MenuRingBuffer.h"

using namespace std;


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
					PrintQueueRingBuffer(queue);
				}
				else 
				{
					cout << "������� �����." << endl;
				}
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

void PrintQueueRingBuffer(QueueRingBuffer* queue)
{
	PrintRingBuffer(queue->Buffer);
}

