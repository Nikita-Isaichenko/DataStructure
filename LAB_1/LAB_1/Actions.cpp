#include <iostream>
#include "Actions.h"
using namespace std;

bool isSort;

void CreatDynamicArray(DynamicArray* dynamicArray)
{
	InitDynamicArray(dynamicArray);

	cout << "Создание массива: " << endl;
	char mode = 'n';
	int size = 4;
	cout << "Заполнить массив автоматические рандомными числами? (y/n): ";
	cin >> mode;

	if (mode == 'y')
	{
		cout << "Укажите размер массива: ";
		cin >> size;

		InitRandomElements(dynamicArray, size);
		cout << "Динамический массив создан" << endl;
	}

	isSort = false;
}

void AddElement(DynamicArray* dynamicArray)
{
	int element = 0;

	cout << "Введите числовое значение элемента для добавления в массив: ";
	cin >> element;

	Add(dynamicArray, element);
	PrintArray(dynamicArray);
}

void RemoveElement(DynamicArray* dynamicArray)
{
	int index;

	cout << "Введите индекс удаляемого элемента: ";
	cin >> index;

	RemoveAt(dynamicArray, index);
	PrintArray(dynamicArray);
}

void InsertElement(DynamicArray* dynamicArray)
{
	int element;
	int index;

	cout << "Введите числовое значение, которое необходимо вставить: ";
	cin >> element;
	cout << "Введите индекс для вставляемого элемента: ";
	cin >> index;

	Insert(dynamicArray, element, index);
	PrintArray(dynamicArray);
}

void SortArray(DynamicArray* dynamicArray)
{
	cout << "Отсортированный массив: ";
	Sort(dynamicArray);
	PrintArray(dynamicArray);

	isSort = true;
}

void LinearSearchElement(DynamicArray* dynamicArray)
{
	int element;
	int indexOfFoundElement;

	cout << "Введите искомое значение: ";
	cin >> element;

	indexOfFoundElement = LinearSearch(dynamicArray, element);

	cout << "Искомое значение: " << element <<
		" находится под индексом: " << indexOfFoundElement << endl;
}

void BinarySearchElement(DynamicArray* dynamicArray)
{
	if (!isSort)
	{
		cout << "Для бинарного поиска необходимо отсортировать массив" << endl;
		return;
	}

	int element;
	int indexOfFoundElement;

	cout << "Введите искомый элемент: ";
	cin >> element;

	indexOfFoundElement = BinarySearch(dynamicArray, element);

	cout << "Искомое значение: " << element <<
		" находится под индексом:  " << indexOfFoundElement << endl;
}

void RecreatDynamicArray(DynamicArray* dynamicArray)
{
	delete[] dynamicArray->array;

	CreatDynamicArray(dynamicArray);
}
