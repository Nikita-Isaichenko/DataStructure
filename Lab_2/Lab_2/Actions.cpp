#include <iostream>
#include "Actions.h"
#include "DoubleLinkedList.h"

using namespace std;

void AddElement(List* linkedList)
{
	int value;

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(List* linkedList)
{
	int index;
	
	cout << "Введите индекс элемента для удаления: ";
	cin >> index;

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(List* linkedList)
{
	int value;

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(List* linkedList)
{
	int value;
	int index;

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	cout << "Введите индекс, после которого надо добавить элемент: ";
	cin >> index;

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}