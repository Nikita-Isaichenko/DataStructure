#include <iostream>
#include "Actions.h"
#include "DoubleLinkedList.h"

using namespace std;

void AddElement(List* linkedList)
{
	int value;

	cout << "¬ведите значение добавл€емого элемента: ";
	cin >> value;

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(List* linkedList)
{
	int index;
	
	cout << "¬ведите индекс элемента дл€ удалени€: ";
	cin >> index;

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(List* linkedList)
{
	int value;

	cout << "¬ведите значение добавл€емого элемента: ";
	cin >> value;

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(List* linkedList)
{
	int value;
	int index;

	cout << "¬ведите значение добавл€емого элемента: ";
	cin >> value;

	cout << "¬ведите индекс, после которого надо добавить элемент: ";
	cin >> index;

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}

void InsertElementBefore(List* linkedList) 
{
	int value;
	int index;

	cout << "¬ведите значение добавл€емого элемента: ";
	cin >> value;

	cout << "¬ведите индекс, перед которым надо добавить элемент: ";
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

	cout << "ƒвусв€зный список: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		node = node->Next;
	}

	cout << endl;
}