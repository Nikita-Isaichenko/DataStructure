#include "DynamicArray.h"
#include <iostream>
#include <time.h>

using namespace std;

const int capacity = 8;

void InitDynamicArray(DynamicArray* array)
{	
	array->Capacity = capacity;
	array->Size = 0;
	array->Array = new int[array->Capacity];
	array->IsSorted = false;
}

void ResizeUpDynamicArray(DynamicArray* array)
{	
	array->Capacity = array->Capacity * array->Growth;

	int* tempArray = new int[array->Capacity];

	for (int i = 0; i < array->Size; i++) 
	{
		tempArray[i] = array->Array[i];
	}

	delete[] array->Array;

	array->Array = tempArray;
}

void ResizeDownDynamicArray(DynamicArray* array)
{
	array->Capacity = array->Capacity / array->Growth;

	int* tempArray = new int[array->Capacity];

	for (int i = 0; i < array->Size; i++)
	{
		tempArray[i] = array->Array[i];
	}

	delete[] array->Array;

	array->Array = tempArray;
	cout << "test";
}

void Add(DynamicArray* array, int element) 
{
	if (array->Size >= array->Capacity) 
	{		
		ResizeUpDynamicArray(array);
	}

	array->Size++;
	array->Array[array->Size - 1] = element;
	array->IsSorted = false;
}

void RemoveAt(DynamicArray* array, int index) 
{
	if (CheckIndexOutRange(array, index)) return;	

	for (int i = index; i < array->Size - 1; i++)
	{
		array->Array[i] = array->Array[i + 1];
	}

	array->Size--;
	array->IsSorted = false;

	if (array->Size == array->Capacity / 2 && array->Capacity > capacity) 
	{
		ResizeDownDynamicArray(array);
	}
}

int Insert(DynamicArray* array, int element, int index) 
{	
	if (CheckIndexOutRange(array, index))
	{
		return -1;
	}

	if (array->Size >= array->Capacity) 
	{
		ResizeUpDynamicArray(array);
	}

	for (int i = 0; i < array->Size - index; i++)
	{
		array->Array[array->Size - i] = array->Array[array->Size - i - 1];
	}

	array->Array[index] = element;
	array->Size++;
	array->IsSorted = false;
	return 0;
}

void Sort(DynamicArray* array)
{
	for (int i = 0; i < array->Size - 1; i++)
	{
		for (int j = i + 1; j < array->Size; j++)
		{
			if (array->Array[j] < array->Array[i])
			{
				swap(array->Array[j], array->Array[i]);
			}
		}
	}

	array->IsSorted = true;
}

int LinearSearch(DynamicArray* array, int element)
{
	for (int i = 0; i < array->Size; i++)
	{
		if (element == array->Array[i]) 
		{			
			return i;
		}
	}

	return -1;
}

int BinarySearch(DynamicArray* array, int element)
{
	int first = 0;
	int last = array->Size-1;
	int middle;
	int searchIndex = -1;

	while (first < last)
	{
		middle = (first + last) / 2;

		if (element < array->Array[middle]) 
		{
			last = middle;
		}
		if (element > array->Array[middle])
		{
			first = middle + 1;
		}
		if (element == array->Array[middle])
		{
			searchIndex = middle;
			break;
		}
	}

	return searchIndex;
}

void PrintArray(DynamicArray* array)
{
	for (int i = 0; i < array->Size; i++)
	{
		cout << array->Array[i] << " ";
	}

	cout << endl;
}

void InitRandomElements(DynamicArray* array, int size)
{
	srand(time(nullptr));

	int value;

	for (int i = 0; i < size; i++)
	{
		value = rand() % 100;
		Add(array, value);
	}
}

bool CheckIndexOutRange(DynamicArray* array, int index)
{
	return (index < 0 || index > array->Size - 1);
}

void DeleteArray(DynamicArray* array) 
{
	delete[] array->Array;
	delete array;
}