#include "Actions.h"
#include "DynamicArray.h"
#include <iostream>

using namespace std;


void CreatDynamicArray() 
{	
	//InitDynamicArray(dynamicArray);

	char mode = 'n';
	int size = 4;
	cout << "���������������� �������� ������� ���������� ����������?(y/n)";
	cin >> mode;

	if (mode == 'y')
	{
		cout << "������� ������ �������: ";
		cin >> size;

		//InitRandomElements(dynamicArray, size);
		
	}
	/*if (mode == 'n')
	{
		return;
	}
	if (mode != 'n' && mode != 'y') 
	{
		cout << "������������ ����!";
		return;
	}*/	
}

void AddElement(DynamicArray* dynamicArray)
{
	int element = 0;

	cout << "������� �������� �������� �������� ��� ����������: ";
	cin >> element;

	Add(dynamicArray, element);
}

void RemoveElement(DynamicArray* dynamicArray)
{
	int index;

	cout << "������� ������ ���������� ��������";
	cin >> index;

	RemoveAt(dynamicArray, index);
}

void InsertElement(DynamicArray* dynamicArray)
{
	int element;
	int index;

	cout << "������� �������� ������������ ��������: ";
	cin >> element;
	cout << "������� ������ �� �������� ���������� �������� �������: ";
	cin >> index;

	Insert(dynamicArray, element, index);
}

void SortArray(DynamicArray* dynamicArray)
{
	Sort(dynamicArray);
}

void LinearSearchElement(DynamicArray* dynamicArray)
{
	int element;
	cout << "������� �������� �������� ��������: ";
	cin >> element;

	LinearSearch(dynamicArray, element);
}

void BinarySearchElement(DynamicArray* dynamicArray)
{
	int element;
	cout << "������� �������� �������� ��������: ";
	cin >> element;

	BinarySearch(dynamicArray, element);
}

void RecreatDynamicArray(DynamicArray* dynamicArray)
{
	//delete[] dynamicArray->array;
	
	
}

void PrintDynamicArray(DynamicArray* dynamicArray)
{
	cout << "����� ������������� �������: " << endl;
	//PrintArray(dynamicArray);
}

