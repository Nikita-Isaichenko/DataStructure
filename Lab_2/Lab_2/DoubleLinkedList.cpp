#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;


void InitList(List* list) 
{
	list->Length = 0;
	list->Head = nullptr;
	list->Tail = nullptr;
}

void Add(List* list, int value) 
{
	Node* node = new Node();

	node->Value = value;
	list->Length += 1;
	node->Previos = list->Tail;
	node->Next = nullptr; // можно ли сразу инициализировать в структуре?

	if (list->Tail != nullptr) 
	{
		list->Tail->Next = node;
	}

	if (list->Head == nullptr) 
	{
		list->Head = node;
	}

	list->Tail = node;
}

void Remove(List* list, int index) 
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return;
	}

	Node* node = list->Head;

	for (int i = 0; i != index; i++)
	{
		node = node->Next;
	}

	if (node == list->Head)
	{
		list->Head = node->Next;
	}
	else 
	{
		node->Previos->Next = node->Next;
	}

	if (node == list->Tail)
	{
		list->Tail = node->Previos;
	}
	else
	{
		node->Next->Previos = node->Previos;
	}

	

	delete node;
}

void Show(List* list)
{
	int count = 0;
	Node* node = list->Head;

	cout << "Двусвязный список: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		count++;
		node = node->Next;
	}

	cout << endl;
}