#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;


void Add(List* list, int value) 
{
	Node* node = new Node();

	node->Value = value;
	node->Previos = list->Tail;

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

void Show(List* list)
{
	int count = 0;
	Node* node = list->Head;

	while (node != nullptr)
	{
		cout << "Значение под индексом: " << count << " равно: " << node->Value << endl;
		count++;
		node = node->Next;
	}
}