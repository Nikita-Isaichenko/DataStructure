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

	Node* node = GetElement(list, index);

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
	Node* indexNode = GetElement(list, index);

	node->Value = value;

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

void InsertBefore(List* list, int index, int value)
{
	if (list->Head == nullptr || list->Length - 1 < index)
	{
		return;
	}

	Node* node = new Node();
	Node* indexNode = GetElement(list, index);

	node->Value = value;

	node->Next = indexNode;
	node->Previos = indexNode->Previos;

	if (indexNode->Previos != nullptr)
	{
		indexNode->Previos->Next = node;
	}

	indexNode->Previos = node;

	if (index == 0)
	{
		list->Head = node;
	}

	list->Length++;
}

void SwapElements(List* list, Node* first, Node* second)
{
	if (first == list->Head)
	{
		list->Head = second;
	}
	else
	{
		first->Previos->Next = second;
	}

	if (second == list->Tail)
	{
		list->Tail = first;
	}
	else
	{
		second->Next->Previos = first;
	}

	first->Next = second->Next;
	second->Previos = first->Previos;
	first->Previos = second;
	second->Next = first;
}

void InsertionSort(List* list)
{

	for (Node* iNode = list->Head->Next; iNode != nullptr; iNode = iNode->Next) 
	{
		Node* jNode = iNode->Previos;		
		
		while (jNode != nullptr && jNode->Value > jNode->Next->Value)
		{
			SwapElements(list, jNode, jNode->Next);
			jNode = jNode->Previos->Previos;
		}	
	}
}

int LinearSearch(List* list, int element) 
{
	int index = 0;

	for (Node* iNode = list->Head; iNode != nullptr; iNode = iNode->Next, index++) 
	{
		if (iNode->Value == element) 
		{
			return index;
		}
	}

	return -1;
}

Node* GetElement(List* list, int index) 
{

	Node* node;

	if (index < list->Length / 2)
	{
		node = list->Head;

		for (int i = 0; i < index; ++i)
		{
			node = node->Next;
		}

		return node;
	}
	else
	{
		node = list->Tail;

		for (int i = list->Length - 1; i > index; i--)
		{
			node = node->Previos;
		}

		return node;
	}
}

