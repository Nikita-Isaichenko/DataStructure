#pragma once

struct Node
{
	int Value;
	Node* Next;
	Node* Previos;
};

struct List
{
	int Length;
	Node* Head;
	Node* Tail;
};

void InitList(List* list);
void Add(List* list, int value);
void Show(List* list);
void Remove(List* list, int index);
void InsertInBegin(List* list, int value);
void InsertAfter(List* list, int index, int value);
void InsertBefore(List* list, int index, int value);
void InsertionSort(List* list);
void SwapElements(List* list, Node* first, Node* second);
int LinearSearch(List* list, int element);


