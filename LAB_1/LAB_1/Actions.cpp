#include <iostream>
#include "Actions.h"

using namespace std;

int CheckingForDigit(const char* text)
{
	char* arrChar = new char[256] {};
	int element;

	while (true)
	{
		cout << text;
		cin >> arrChar;

		if (arrChar == "0")
		{
			return 0;
		}

		element = std::atoi(arrChar);

		if (element != 0)
		{
			return element;
		}
		else
		{
			cout << "Некорректный ввод! Введите число." << endl;
		}
	}
}

void CreatDynamicArray(DynamicArray* dynamicArray)
{
	InitDynamicArray(dynamicArray);

	cout << "Создание массива: " << endl;

	char mode = 'n';
	int size = 4;

	while (true) 
	{
		cout << "Заполнить массив автоматические рандомными числами? (y/n): ";
		cin >> mode;

		if (mode == 'y' || mode == 'n')
		{
			if (mode == 'y')
			{
				size = CheckingForDigit("Введите размер массива: ");

				InitRandomElements(dynamicArray, size);
				cout << "Динамический массив создан" << endl;				
			}

			break;
		}
		else
		{
			cout << "Некорректный ответ!" << endl;
		}
	}
}

void AddElement(DynamicArray* dynamicArray)
{
	int element = CheckingForDigit(
		"Введите числовое значение элемента для добавления в массив: ");		

	Add(dynamicArray, element);
	ShowArray(dynamicArray);
}

void RemoveElement(DynamicArray* dynamicArray)
{
	int index = CheckingForDigit("Введите индекс удаляемого элемента: ");

	RemoveAt(dynamicArray, index);
	ShowArray(dynamicArray);
}

void InsertElement(DynamicArray* dynamicArray)
{
	int element
		= CheckingForDigit("Введите числовое значение, которое необходимо вставить: ");

	int index = CheckingForDigit("Введите индекс для вставляемого элемента: ");

	if (Insert(dynamicArray, element, index) == -1)
	{
		cout << "Индекс выходит за границы массива." << endl;
	}

	ShowArray(dynamicArray);
}

void SortArray(DynamicArray* dynamicArray)
{
	cout << "Отсортированный массив: ";
	Sort(dynamicArray);
	ShowArray(dynamicArray);
}

void LinearSearchElement(DynamicArray* dynamicArray)
{
	int element = CheckingForDigit("Введите искомое значение: ");
	int indexOfFoundElement;

	indexOfFoundElement = LinearSearch(dynamicArray, element);

	if (indexOfFoundElement == -1)
	{
		cout << "В массиве не найден элемент: " << element;
		return;
	}

	cout << "Искомое значение: " << element <<
		" находится под индексом: " << indexOfFoundElement << endl;
}

void BinarySearchElement(DynamicArray* dynamicArray)
{
	if (!dynamicArray->IsSorted)
	{
		cout << "Для бинарного поиска необходимо отсортировать массив" << endl;
		return;
	}

	int element = CheckingForDigit("Введите искомый элемент: ");
	int indexOfFoundElement;

	indexOfFoundElement = BinarySearch(dynamicArray, element);

	if (indexOfFoundElement == -1)
	{
		cout << "В массиве не найден элемент: " << element;
		return;
	}

	cout << "Искомое значение: " << element <<
		" находится под индексом:  " << indexOfFoundElement << endl;
}

void RecreatDynamicArray(DynamicArray* dynamicArray)
{
	delete[] dynamicArray->Array;

	CreatDynamicArray(dynamicArray);
}

void ShowArray(DynamicArray* dynamicArray)
{
	cout << "Массив: ";
	PrintArray(dynamicArray);
}
