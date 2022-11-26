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
		cout << "Некорректный ввод!" << endl;
	}
}

void AddElement(List* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(List* linkedList)
{
	int index = CheckingForDigit("Введите индекс элемента для удаления: ");

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(List* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(List* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");
	int index = CheckingForDigit("Введите индекс, после которого надо добавить элемент: ");

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}

void InsertElementBefore(List* linkedList) 
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");
	int index = CheckingForDigit("Введите индекс, перед которым надо добавить элемент: ");

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

	cout << "Двусвязный список: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		node = node->Next;
	}

	cout << endl;
}

void LinearSearchElement(List* list)
{
	int value = CheckingForDigit("Введите значение искомого элемента: ");

	if (value != -1)
	{
		cout << "Искомый элемент находится под индексом: "
			<< LinearSearch(list, value) << endl;
	}
	else 
	{
		cout << "Искомого элемента в списке нет" << endl;
	}
}