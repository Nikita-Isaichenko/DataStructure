#include "DynamicArray.h"
#include <iostream>
using namespace std;


void CreatDynamicArray(DynamicArray* array)
{
	int capacity = 8;
	array->capacity = capacity;
	array->size = 0;
	array->array = new int[array->capacity];
}

void ResizeDynamicArray(DynamicArray* array)
{
	int capacity = 8;

	array->capacity += capacity;

	int* tempArray = new int[array->capacity];

	for (int i = 0; i < array->size-1; i++) 
	{
		tempArray[i] = array->array[i];
	}

	delete[] array->array;

	array->array = tempArray;
}

void Add(DynamicArray* array, int element) 
{
	array->size++;

	if (array->size >= array->capacity) 
	{
		cout << "flag" << endl;
		ResizeDynamicArray(array);
	}

	array->array[array->size - 1] = element;
}

void PrintArray(DynamicArray* array)
{
	for (int i = 0; i < array->size; i++)
	{
		cout << array->array[i] << " ";
	}

	cout << endl;
}