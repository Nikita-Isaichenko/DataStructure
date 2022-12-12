#include <iostream>
#include "IODoubleLinkedList.h"
#include "DoubleLinkedList.h"
#include "Validation.h"
#include <chrono>

using namespace std;


//TODO: IODoubleLinkedList (done)
void AddElement(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(DoubleLinkedList* linkedList)
{
	int index = CheckingForDigit("������� ������ �������� ��� ��������: ");

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");
	int index = CheckingForDigit("������� ������, ����� �������� ���� �������� �������: ");

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}

void InsertElementBefore(DoubleLinkedList* linkedList) 
{
	int value = CheckingForDigit("������� �������� ������������ ��������: ");
	int index = CheckingForDigit("������� ������, ����� ������� ���� �������� �������: ");

	InsertBefore(linkedList, index, value);
	Show(linkedList);
}

void SortList(DoubleLinkedList* list)
{
	InsertionSort(list);
	Show(list);
}

void Show(DoubleLinkedList* list)
{
	Node* node = list->Head;

	cout << "���������� ������: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		node = node->Next;
	}

	cout << endl << "Length: " << list->Length << endl;

}

void LinearSearchElement(DoubleLinkedList* list)
{
	int value = CheckingForDigit("������� �������� �������� ��������: ");

	int desiredIndex = LinearSearch(list, value);
	if (desiredIndex != -1)
	{
		cout << "������� ������� ��������� ��� ��������: "
			<< desiredIndex << endl;
	}
	else 
	{
		cout << "�������� �������� � ������ ���" << endl;
	}
}

void RemoveList(DoubleLinkedList* list)
{
	if (list->Head == nullptr)
	{
		return;
	}

	int index = 0;
	Node* temp = list->Head->Next;

	while (temp != nullptr)
	{
		delete temp->Previos;
		list->Length--;
		temp = temp->Next;
	}

	delete temp;
	list->Length--;
	list->Head = nullptr;
	list->Tail = nullptr;
}

void RandomValues(DoubleLinkedList* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		Add(list, rand() % 100);
	}
}