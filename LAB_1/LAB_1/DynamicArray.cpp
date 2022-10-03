#include "DynamicArray.h"
#include <iostream>
#include <time.h>

using namespace std;


void InitDynamicArray(DynamicArray* array)
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

	for (int i = 0; i < array->size; i++) 
	{
		tempArray[i] = array->array[i];
	}

	delete[] array->array;

	array->array = tempArray;
}

void Add(DynamicArray* array, int element) 
{
	if (array->size >= array->capacity) 
	{		
		ResizeDynamicArray(array);
	}

	array->size++;
	array->array[array->size - 1] = element;
}

void RemoveAt(DynamicArray* array, int index) 
{
	if (CheckIndexOutRange(array, index)) return;		

	for (int i = index; i < array->size - 1; i++)
	{
		array->array[i] = array->array[i + 1];
	}

	array->size--;
}

void Insert(DynamicArray* array, int element, int index) 
{	
	if (CheckIndexOutRange(array, index)) return;

	if (array->size >= array->capacity) 
	{
		ResizeDynamicArray(array);
	}

	for (int i = 0; i < array->size - index; i++)
	{
		array->array[array->size - i] = array->array[array->size - i - 1];
	}

	array->array[index] = element;
	array->size++;
}

void Sort(DynamicArray* array)
{
	for (int i = 0; i < array->size - 1; i++)
	{
		for (int j = i + 1; j < array->size; j++)
		{
			if (array->array[j] < array->array[i])
			{
				swap(array->array[j], array->array[i]);
			}
		}
	}
}

int LinearSearch(DynamicArray* array, int element)
{
	for (int i = 0; i < array->size; i++)
	{
		if (element == array->array[i]) 
		{			
			return i;
		}
	}

	return -1;
}

int BinarySearch(DynamicArray* array, int element)
{
	int first = 0;
	int last = array->size-1;
	int middle;

	while (first < last)
	{
		middle = (first + last) / 2;

		if (element <= array->array[middle]) 
		{
			last = middle;
		}
		else
		{
			first = middle + 1;
		}
	}

	return (first == array->size ||
			array->array[first] != element) ? -1 : first;
}

void PrintArray(DynamicArray* array)
{
	cout << "Массив: ";

	for (int i = 0; i < array->size; i++)
	{
		cout << array->array[i] << " ";
	}

	cout << endl;
}

void InitRandomElements(DynamicArray* array, int size)
{
	srand(time(0));

	int value;

	for (int i = 0; i < size; i++)
	{
		value = rand() % 100;
		Add(array, value);
	}
}

bool CheckIndexOutRange(DynamicArray* array, int index)
{
	if (index < 0 || index > array->size - 1)
	{
		cout << "индекс является отрицательным числом, либо выходит за границы массива" << endl;
		return true;
	}
	else 
	{
		return false;
	}
}