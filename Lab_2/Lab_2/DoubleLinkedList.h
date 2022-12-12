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

//TODO: naming
/**
 * Хранит информацию о двусвязном списке.
 */
struct DoubleLinkedList
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
void InitList(DoubleLinkedList* list);

/**
 * Добавляет элемент в конец списка.
 * @param list список.
 * @param value добавляемое значение.
 */
void Add(DoubleLinkedList* list, int value);

/**
 * Удаляет элемент из списка по индексу.
 * @param index индекс удаляемого элемента.
 */
void Remove(DoubleLinkedList* list, int index);

/**
 * Вставка элемента в начало.
 * @param list список.
 * @param value значение элемента.
 */
void InsertInBegin(DoubleLinkedList* list, int value);

/**
 * Вставка элемента после указанного индекса.
 * @param list список.
 * @param index индекс.
 * @param value значение элемента.
 */
void InsertAfter(DoubleLinkedList* list, int index, int value);

/**
 * Вставка после указанного индекса.
 * @param list список.
 * @param index индекс.
 * @param value значение элемента.
 */
void InsertBefore(DoubleLinkedList* list, int index, int value);

/**
 * Сортировка вставками.
 * @param list список.
 */
void InsertionSort(DoubleLinkedList* list);

/**
 * Перестановка двух узлов.
 * @param list список.
 * @param first первый узел.
 * @param second второй узел.
 */
void SwapElements(DoubleLinkedList* list, Node* first, Node* second);

/**
 * Линейный поиск элемента.
 * @param list список.
 * @param element искомый элемент.
 */
int LinearSearch(DoubleLinkedList* list, int element);

/**
 * Получение элемента. Если индекс больше половины, перебор списка идет с конца,
 * если индекс меньше половины, перебор списка идет с начало.
 * @param list список.
 * @param index индекс элемента.
 */
Node* GetElement(DoubleLinkedList* list, int index);




