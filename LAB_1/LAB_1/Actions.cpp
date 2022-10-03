#include <iostream>
#include "Actions.h"
using namespace std;

bool isSort;

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

	isSort = false;
}

void AddElement(DynamicArray* dynamicArray)
{
	int element = 0;

	cout << "������� �������� �������� �������� ��� ���������� � ������: ";
	cin >> element;

	Add(dynamicArray, element);
	PrintArray(dynamicArray);
}

void RemoveElement(DynamicArray* dynamicArray)
{
	int index;

	cout << "������� ������ ���������� ��������: ";
	cin >> index;

	RemoveAt(dynamicArray, index);
	PrintArray(dynamicArray);
}

void InsertElement(DynamicArray* dynamicArray)
{
	int element;
	int index;

	cout << "������� �������� ��������, ������� ���������� ��������: ";
	cin >> element;
	cout << "������� ������ ��� ������������ ��������: ";
	cin >> index;

	Insert(dynamicArray, element, index);
	PrintArray(dynamicArray);
}

void SortArray(DynamicArray* dynamicArray)
{
	cout << "��������������� ������: ";
	Sort(dynamicArray);
	PrintArray(dynamicArray);

	isSort = true;
}

void LinearSearchElement(DynamicArray* dynamicArray)
{
	int element;
	int indexOfFoundElement;

	cout << "������� ������� ��������: ";
	cin >> element;

	indexOfFoundElement = LinearSearch(dynamicArray, element);

	cout << "������� ��������: " << element <<
		" ��������� ��� ��������: " << indexOfFoundElement << endl;
}

void BinarySearchElement(DynamicArray* dynamicArray)
{
	if (!isSort)
	{
		cout << "��� ��������� ������ ���������� ������������� ������" << endl;
		return;
	}

	int element;
	int indexOfFoundElement;

	cout << "������� ������� �������: ";
	cin >> element;

	indexOfFoundElement = BinarySearch(dynamicArray, element);

	cout << "������� ��������: " << element <<
		" ��������� ��� ��������:  " << indexOfFoundElement << endl;
}

void RecreatDynamicArray(DynamicArray* dynamicArray)
{
	delete[] dynamicArray->array;

	CreatDynamicArray(dynamicArray);
}
