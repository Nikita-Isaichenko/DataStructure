#include <iostream>
#include "Actions.h"
#include "DoubleLinkedList.h"

using namespace std;

void AddElement(List* linkedList)
{
	int value;

	cout << "������� �������� ������������ ��������: ";
	cin >> value;

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(List* linkedList)
{
	int index;
	
	cout << "������� ������ �������� ��� ��������: ";
	cin >> index;

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(List* linkedList)
{
	int value;

	cout << "������� �������� ������������ ��������: ";
	cin >> value;

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(List* linkedList)
{
	int value;
	int index;

	cout << "������� �������� ������������ ��������: ";
	cin >> value;

	cout << "������� ������, ����� �������� ���� �������� �������: ";
	cin >> index;

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}