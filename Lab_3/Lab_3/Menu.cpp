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
		cout << "1. ������ �� ������." << endl;
		cout << "2. ������ � ��������� ��������." << endl;
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
			delete stack;
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
	InitRingBuffer(buffer);
	
	cout << "��������� �����" << endl;

	while (true)
	{
		cout << "0. �������� �������." << endl;
		cout << "1. ������� ��������� �����." << endl;
		cout << "2. ������� ������� �����." << endl;
		cout << "3. �������� ������� � �����." << endl;
		cout << "4. ������� ������� �� ������." << endl;
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
			cout << "��������� ����� � ������: " << FreeMemoryInfo(buffer) << endl;
			break;
		case 2:
			cout << "������� ����� � ������: " << UsedMemoryInfo(buffer) << endl;
			break;
		case 3:
		{
			int value = CheckingForDigit("������� ����������� ��������: ");
			Push(buffer, value);
			PrintRingBuffer(buffer);
			break;
		}
		case 4:
			if (UsedMemoryInfo(buffer) > 0) 
			{
				cout << "�������� �� ������: " << Pop(buffer) << endl;
				PrintRingBuffer(buffer);
			}
			else 
			{
				cout << "����� ����." << endl;
			}

			break;
		case 5:
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
	cout << "������ ������: " << buffer->Size;
}