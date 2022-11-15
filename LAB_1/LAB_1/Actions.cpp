#include <iostream>
#include "Actions.h"

using namespace std;

int CheckingForDigit(const char* text)
{
	char* arrChar = new char[256] {};
	int element;

	while (true)
	{
		cout << text;
		cin >> arrChar;

		if (arrChar == "0")
		{
			return 0;
		}

		element = std::atoi(arrChar);

		if (element != 0)
		{
			return element;
		}
		else
		{
			cout << "������������ ����! ������� �����." << endl;
		}
	}
}

void CreatDynamicArray(DynamicArray* dynamicArray)
{
	InitDynamicArray(dynamicArray);

	cout << "�������� �������: " << endl;

	char mode = 'n';
	int size = 4;

	while (true) 
	{
		cout << "��������� ������ �������������� ���������� �������? (y/n): ";
		cin >> mode;

		if (mode == 'y' || mode == 'n')
		{
			if (mode == 'y')
			{
				size = CheckingForDigit("������� ������ �������: ");

				InitRandomElements(dynamicArray, size);
				cout << "������������ ������ ������" << endl;				
			}

			break;
		}
		else
		{
			cout << "������������ �����!" << endl;
		}
	}
}

void AddElement(DynamicArray* dynamicArray)
{
	int element = CheckingForDigit(
		"������� �������� �������� �������� ��� ���������� � ������: ");		

	Add(dynamicArray, element);
	ShowArray(dynamicArray);
}

void RemoveElement(DynamicArray* dynamicArray)
{
	int index = CheckingForDigit("������� ������ ���������� ��������: ");

	RemoveAt(dynamicArray, index);
	ShowArray(dynamicArray);
}

void InsertElement(DynamicArray* dynamicArray)
{
	int element
		= CheckingForDigit("������� �������� ��������, ������� ���������� ��������: ");

	int index = CheckingForDigit("������� ������ ��� ������������ ��������: ");

	if (Insert(dynamicArray, element, index) == -1)
	{
		cout << "������ ������� �� ������� �������." << endl;
	}

	ShowArray(dynamicArray);
}

void SortArray(DynamicArray* dynamicArray)
{
	cout << "��������������� ������: ";
	Sort(dynamicArray);
	ShowArray(dynamicArray);
}

void LinearSearchElement(DynamicArray* dynamicArray)
{
	int element = CheckingForDigit("������� ������� ��������: ");
	int indexOfFoundElement;

	indexOfFoundElement = LinearSearch(dynamicArray, element);

	if (indexOfFoundElement == -1)
	{
		cout << "� ������� �� ������ �������: " << element;
		return;
	}

	cout << "������� ��������: " << element <<
		" ��������� ��� ��������: " << indexOfFoundElement << endl;
}

void BinarySearchElement(DynamicArray* dynamicArray)
{
	if (!dynamicArray->IsSorted)
	{
		cout << "��� ��������� ������ ���������� ������������� ������" << endl;
		return;
	}

	int element = CheckingForDigit("������� ������� �������: ");
	int indexOfFoundElement;

	indexOfFoundElement = BinarySearch(dynamicArray, element);

	if (indexOfFoundElement == -1)
	{
		cout << "� ������� �� ������ �������: " << element;
		return;
	}

	cout << "������� ��������: " << element <<
		" ��������� ��� ��������:  " << indexOfFoundElement << endl;
}

void RecreatDynamicArray(DynamicArray* dynamicArray)
{
	delete[] dynamicArray->Array;

	CreatDynamicArray(dynamicArray);
}

void ShowArray(DynamicArray* dynamicArray)
{
	cout << "������: ";
	PrintArray(dynamicArray);
}
