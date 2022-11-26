#include <iostream>
#include "Actions.h"
#include "DoubleLinkedList.h"

using namespace std;

int CheckingForDigit(const char* text)
{
	int element;

	while (true)
	{
		cout << text;
		cin >> element;

		if (!cin.fail()) return element;

		cin.clear();
		cin.ignore(32767, '\n');
		cout << "������������ ����!" << endl;
	}
}

void AddElement(List* linkedList)
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(List* linkedList)
{
	int index = CheckingForDigit("������� ������ �������� ��� ��������: ");

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(List* linkedList)
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(List* linkedList)
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");
	int index = CheckingForDigit("������� ������, ����� �������� ���� �������� �������: ");

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}

void InsertElementBefore(List* linkedList) 
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");
	int index = CheckingForDigit("������� ������, ����� ������� ���� �������� �������: ");

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

void LinearSearchElement(List* list)
{
	int value = CheckingForDigit("������� �������� �������� ��������: ");

	if (value != -1)
	{
		cout << "������� ������� ��������� ��� ��������: "
			<< LinearSearch(list, value) << endl;
	}
	else 
	{
		cout << "�������� �������� � ������ ���" << endl;
	}
}