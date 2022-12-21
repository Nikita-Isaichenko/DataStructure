#include "MenuRingBuffer.h"
#include "RingBuffer.h"
#include <iostream>
#include "Validation.h"

using namespace std;

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