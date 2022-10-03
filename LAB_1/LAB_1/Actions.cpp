#include "Actions.h"
#include "DynamicArray.h"
#include <iostream>

using namespace std;


void CreatDynamicArray() 
{	
	//InitDynamicArray(dynamicArray);

	char mode = 'n';
	int size = 4;
	cout << "Инициализировать значения массива рандомными значениями?(y/n)";
	cin >> mode;

	if (mode == 'y')
	{
		cout << "Введите размер массива: ";
		cin >> size;

		//InitRandomElements(dynamicArray, size);
		
	}
	/*if (mode == 'n')
	{
		return;
	}
	if (mode != 'n' && mode != 'y') 
	{
		cout << "Некорректный ввод!";
		return;
	}*/	
}

void AddElement(DynamicArray* dynamicArray)
{
	int element = 0;

	cout << "Введите числовое значение элемента для добавления: ";
	cin >> element;

	Add(dynamicArray, element);
}

void RemoveElement(DynamicArray* dynamicArray)
{
	int index;

	cout << "Введите индекс удаляемого элемента";
	cin >> index;

	RemoveAt(dynamicArray, index);
}

void InsertElement(DynamicArray* dynamicArray)
{
	int element;
	int index;

	cout << "Введите значение вставляемого элемента: ";
	cin >> element;
	cout << "Введите индекс по которому необходимо вставить элемент: ";
	cin >> index;

	Insert(dynamicArray, element, index);
}

void SortArray(DynamicArray* dynamicArray)
{
	Sort(dynamicArray);
}

void LinearSearchElement(DynamicArray* dynamicArray)
{
	int element;
	cout << "Введите значение искомого элемента: ";
	cin >> element;

	LinearSearch(dynamicArray, element);
}

void BinarySearchElement(DynamicArray* dynamicArray)
{
	int element;
	cout << "Введите значение искомого элемента: ";
	cin >> element;

	BinarySearch(dynamicArray, element);
}

void RecreatDynamicArray(DynamicArray* dynamicArray)
{
	//delete[] dynamicArray->array;
	
	
}

void PrintDynamicArray(DynamicArray* dynamicArray)
{
	cout << "Вывод динамического массива: " << endl;
	//PrintArray(dynamicArray);
}

