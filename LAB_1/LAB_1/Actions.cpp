#include <iostream>
#include "Actions.h"

using namespace std;


void CreatDynamicArray(DynamicArray* dynamicArray)
{
	InitDynamicArray(dynamicArray);

	cout << "�������� �������: " << endl;

	char mode = 'n';
	int size = 4;

	cout << "��������� ������ �������������� ���������� �������? (y/n): ";
	cin >> mode;

	if (mode == 'y')
	{
		cout << "������� ������ �������: ";
		cin >> size;

		InitRandomElements(dynamicArray, size);
		cout << "������������ ������ ������" << endl;
	}
}

void AddElement(DynamicArray* dynamicArray)
{
	int element = 0;

	cout << "������� �������� �������� �������� ��� ���������� � ������: ";
	cin >> element;

	Add(dynamicArray, element);
	ShowArray(dynamicArray);
}

void RemoveElement(DynamicArray* dynamicArray)
{
	int index;

	cout << "������� ������ ���������� ��������: ";
	cin >> index;

	RemoveAt(dynamicArray, index);
	ShowArray(dynamicArray);
}

void InsertElement(DynamicArray* dynamicArray)
{
	int element;
	int index;

	cout << "������� �������� ��������, ������� ���������� ��������: ";
	cin >> element;
	cout << "������� ������ ��� ������������ ��������: ";
	cin >> index;

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
	int element;
	int indexOfFoundElement;

	cout << "������� ������� ��������: ";
	cin >> element;

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

	int element;
	int indexOfFoundElement;

	cout << "������� ������� �������: ";
	cin >> element;

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
