#pragma once
/*****************************************************************//**
 * \file   DynamicArray.h
 * \brief  
 * 
 * \author nikit
 * \date   November 2022
 *********************************************************************/

/**
 * Структура динамического массива.
 */
struct DynamicArray
{
	const double Growth = 1.5;
	bool IsSorted;
	int* Array;
	int Size;
	int Capacity;
};

/**
 * Инициализирует структуру динамический массив.
 */
void InitDynamicArray(DynamicArray* array);

/**
 * Увеличивает или уменьшает размер буфера для массива.
 */
void ResizeDynamicArray(DynamicArray* array);

/**
 * Проверяет надо ли изменить размер массива.
 */
void CheckResizeDynamicArray(DynamicArray* array);

/**
 * Добавляет элемент в конец динамического массива.
 */
void Add(DynamicArray* array, int element);

/**
 * Удаляет элемент из динамического массива по индексу.
 */
void RemoveAt(DynamicArray* array, int index);

/**
 * Вставляет в динамический массив элемент по указанному индексу.
 */
int Insert(DynamicArray* array, int  element, int index);

/**
 * Сортирует динамический массив.
 */
void Sort(DynamicArray* array);

/**
 * Инициализирует динамический массив заданным кол-вом случайных элементов.
 */
void InitRandomElements(DynamicArray* array, int size);

/**
 * Проверяет, входил ли указанный индекс в динамический массив.
 */
bool CheckIndexOutRange(DynamicArray* array, int index);

/**
 * Осуществляет линейный поиск элемента по динамическому массиву.
 */
int LinearSearch(DynamicArray* array, int element);

/**
 * Осуществляет бинарный поиск элемента по динамическому массиву.
 */
int BinarySearch(DynamicArray* array, int element);

/**
 * Удаляет динамический массив.
 */
void DeleteArray(DynamicArray* array);




