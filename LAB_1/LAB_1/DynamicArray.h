#pragma once

struct DynamicArray 
{
	int* array;
	int size;
	int capacity;
};

void CreatDynamicArray(DynamicArray*);
void Add(DynamicArray*, int);
void PrintArray(DynamicArray*);