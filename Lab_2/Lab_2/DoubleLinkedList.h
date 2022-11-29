/*****************************************************************//**
 * \file   DoubleLinkedList.h
 * \brief  
 *
 * 
 * \author nikit
 * \date   November 2022
 *********************************************************************/
#pragma once

/**
 * Хранит информацию о узле двусвязного списка.
 */
struct Node
{
	/**
	 * Элемент в двусвязном списке.
	 */
	int Value;

	/**
	 * Указатель на следующий узел списка.
	 */
	Node* Next;

	/**
	 * Указатель на предыдущий узел списка.
	 */
	Node* Previos;
};

/**
 * Хранит информацию о двусвязном списке.
 */
struct List
{
	/**
	 * Длина списка.
	 */
	int Length;

	/**
	 * Указатель на начало списка.
	 */
	Node* Head;

	/**
	 * Указатель на конец списка.
	 */
	Node* Tail;
};

/**
 * Инициализирует список.
 * @param list список.
 */
void InitList(List* list);

/**
 * Добавляет элемент в конец списка.
 * @param list список.
 * @param value добавляемое значение.
 */
void Add(List* list, int value);

/**
 * Удаляет элемент из списка по индексу.
 * @param index индекс удаляемого элемента.
 */
void Remove(List* list, int index);

/**
 * Вставка элемента в начало.
 * @param list список.
 * @param value значение элемента.
 */
void InsertInBegin(List* list, int value);

/**
 * Вставка элемента после указанного индекса.
 * @param list список.
 * @param index индекс.
 * @param value значение элемента.
 */
void InsertAfter(List* list, int index, int value);

/**
 * Вставка после указанного индекса.
 * @param list список.
 * @param index индекс.
 * @param value значение элемента.
 */
void InsertBefore(List* list, int index, int value);

/**
 * Сортировка вставками.
 * @param list список.
 */
void InsertionSort(List* list);

/**
 * Перестановка двух узлов.
 * @param list список.
 * @param first первый узел.
 * @param second второй узел.
 */
void SwapElements(List* list, Node* first, Node* second);

/**
 * Линейный поиск элемента.
 * @param list список.
 * @param element искомый элемент.
 */
int LinearSearch(List* list, int element);

/**
 * Получение элемента. Если индекс больше половины, перебор списка идет с конца,
 * если индекс меньше половины, перебор списка идет с начало.
 * @param list список.
 * @param index индекс элемента.
 */
Node* GetElement(List* list, int index);




