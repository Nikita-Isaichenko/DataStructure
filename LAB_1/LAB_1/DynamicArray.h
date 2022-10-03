#pragma once

struct DynamicArray
{
	int* array;
	int size;
	int capacity;
};

void InitDynamicArray(DynamicArray* array);
void Add(DynamicArray* array, int element);
void RemoveAt(DynamicArray* array, int index);
void Insert(DynamicArray* array, int  element, int index);
void Sort(DynamicArray* array);
void PrintArray(DynamicArray* array);
void InitRandomElements(DynamicArray* array, int size);
bool CheckIndexOutRange(DynamicArray* array, int index);
int LinearSearch(DynamicArray* array, int element);
int BinarySearch(DynamicArray* array, int element);