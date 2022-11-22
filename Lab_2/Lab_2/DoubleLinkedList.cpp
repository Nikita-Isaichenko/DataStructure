#include "DoubleLinkedList.h"
#include <iostream>

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
	list->Length++;
	node->Previos = list->Tail;
	node->Next = nullptr;

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

	list->Length--;
	delete node;
}

void InsertInBegin(List* list, int value)
{
	Node* node = new Node();

	node->Value = value;
	node->Previos = nullptr;
	node->Next = list->Head;

	if (list->Head != nullptr)
	{
		list->Head->Previos = node;
	}

	if (list->Tail == nullptr)
	{
		list->Tail = node;
	}

	list->Length++;
	list->Head = node;
}

void InsertAfter(List* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{		
		return;
	}

	Node* node = new Node();
	Node* indexNode = list->Head;

	node->Value = value;

	for (int i = 0; i != index; i++)
	{
		indexNode = indexNode->Next;
	}

	node->Next = indexNode->Next;
	node->Previos = indexNode;

	if (list->Length - 1 != index)
	{
		indexNode->Next->Previos = node;
	}
	
	indexNode->Next = node;

	if (list->Length - 1 == index)
	{
		list->Tail = node;
	}

	list->Length++;
}
