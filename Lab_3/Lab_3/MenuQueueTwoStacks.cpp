#include "MenuQueueTwoStacks.h"
#include "Validation.h"
#include <iostream>
#include "QueueTwoStacks.h"
#include "IOStack.h"

using namespace std;


void MenuQueueTwoStacks()
{
	QueueTwoStacks* queue = nullptr;

	cout << "������� �� ������ ���� ������." << endl;

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
		{
			int size = CheckingForDigit("������� ������ �������: ");

			queue = new QueueTwoStacks();

			if (size < 4)
			{
				cout << "��������� ������ ������ ������������ (4)"
					"������� ������ �������� � ������������." << endl;
				size = 4;
			}

			queue = InitQueueTwoStacks(size);
		}
			break;
		case 2:
		{
			int data = CheckingForDigit("������� ��������: ");
			Enqueue(queue, data);
			PrintQueueTwoStacks(queue);
		}
			break;
		case 3:
			if (queue)
			{
				if (LengthQueueTwoStacks(queue) > 0)
				{
					cout << "���������� �������: " << Dequeue(queue) << endl;
					PrintQueueTwoStacks(queue);
				}
				else
				{
					cout << "������� �����." << endl;
				}
			}
			else
			{
				cout << "������� �� �������. �������� �������." << endl;
			}

			break;
		case 4:
			if (queue)
			{
				DeleteQueueTwoStacks(queue);
				delete queue;
				queue = nullptr;
				
				cout << "������� �������." << endl;
			}
			else
			{
				cout << "������� �� �������. �������� �������." << endl;
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
			cout << "������������ �����." << endl;
			break;
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;

	}
}

void PrintQueueTwoStacks(QueueTwoStacks* queue)
{
	cout << "���� ��� ������� ������." << endl;

	PrintStack(queue->InputStack);

	cout << endl;
	cout << "���� ��� �������� ������." << endl;

	PrintStack(queue->OutputStack);

	cout << endl;
}
