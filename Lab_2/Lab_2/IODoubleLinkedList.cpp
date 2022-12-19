#include <iostream>
#include "IODoubleLinkedList.h"
#include "DoubleLinkedList.h"
#include "Validation.h"
#include <chrono>

using namespace std;

void AddElement(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("¬ведите значение добавл€емого элемента: ");

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(DoubleLinkedList* linkedList)
{
	int index = CheckingForDigit("¬ведите индекс элемента дл€ удалени€: ");

	if (Remove(linkedList, index) == -1) 
	{
		cout << "¬веденный индекс выходит за пределы списка." << endl;
	}

	Show(linkedList);
}

void InsertElementInBegin(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("¬ведите значение добавл€емого элемента: ");

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(DoubleLinkedList* linkedList)
{
	int value = CheckingForDigit("¬ведите значение добавл€емого элемента: ");
	int index = CheckingForDigit("¬ведите индекс, после которого надо добавить элемент: ");

	if (InsertAfter(linkedList, index, value) == -1)
	{
		cout << "¬веденный индекс выходит за пределы списка." << endl;
	}

	Show(linkedList);
}

void InsertElementBefore(DoubleLinkedList* linkedList) 
{
	int value = CheckingForDigit("¬ведите значение добавл€емого элемента: ");
	int index = CheckingForDigit("¬ведите индекс, перед которым надо добавить элемент: ");

	if (InsertBefore(linkedList, index, value) == -1)
	{
		cout << "¬веденный индекс выходит за пределы списка." << endl;
	}

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

	cout << "ƒвусв€зный список: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		node = node->Next;
	}

	cout << endl << "Length: " << list->Length << endl;

}

void LinearSearchElement(DoubleLinkedList* list)
{
	int value = CheckingForDigit("¬ведите значение искомого элемента: ");

	int desiredIndex = LinearSearch(list, value);
	if (desiredIndex != -1)
	{
		cout << "»скомый элемент находитс€ под индексом: "
			<< desiredIndex << endl;
	}
	else 
	{
		cout << "»скомого элемента в списке нет" << endl;
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