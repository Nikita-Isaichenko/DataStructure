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

void InsertElementBefore(List* linkedList) 
{
	int value;
	int index;

	cout << "������� �������� ������������ ��������: ";
	cin >> value;

	cout << "������� ������, ����� ������� ���� �������� �������: ";
	cin >> index;

	InsertBefore(linkedList, index, value);
	Show(linkedList);
}

void SortList(List* list)
{
	InsertionSort(list);
	Show(list);
}

void Show(List* list)
{
	Node* node = list->Head;

	cout << "���������� ������: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		node = node->Next;
	}

	cout << endl;
}