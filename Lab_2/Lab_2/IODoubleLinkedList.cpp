#include <iostream>
#include "IODoubleLinkedList.h"
#include "DoubleLinkedList.h"
#include "Validation.h"
#include <chrono>

using namespace std;


//TODO: IODoubleLinkedList (done)
void AddElement(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(DoubleLinkedList* linkedList)
{
	int index = CheckingForDigit("Введите индекс элемента для удаления: ");

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");
	int index = CheckingForDigit("Введите индекс, после которого надо добавить элемент: ");

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}

void InsertElementBefore(DoubleLinkedList* linkedList) 
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");
	int index = CheckingForDigit("Введите индекс, перед которым надо добавить элемент: ");

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

	cout << "Двусвязный список: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		node = node->Next;
	}

	cout << endl << "Length: " << list->Length << endl;

}

void LinearSearchElement(DoubleLinkedList* list)
{
	int value = CheckingForDigit("Введите значение искомого элемента: ");

	int desiredIndex = LinearSearch(list, value);
	if (desiredIndex != -1)
	{
		cout << "Искомый элемент находится под индексом: "
			<< desiredIndex << endl;
	}
	else 
	{
		cout << "Искомого элемента в списке нет" << endl;
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