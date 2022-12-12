/*****************************************************************//**
 * \file   Actions.h
 * \brief  
 * 
 * \author nikit
 * \date   November 2022
 *********************************************************************/
#pragma once
#include "DoubleLinkedList.h"

/**
 * Добавляет элемент.
 */
void AddElement(DoubleLinkedList* linkedList);

/**
 * Удаляет элемент.
 */
void RemoveElement(DoubleLinkedList* linkedList);

/**
 * Вставляет элемент в начало.
 */
void InsertElementInBegin(DoubleLinkedList* linkedList);

/**
 * Вставляет элемент после.
 */
void InsertElementAfter(DoubleLinkedList* linkedList);

/**
 * Вставляет элемент до.
 */
void InsertElementBefore(DoubleLinkedList* linkedList);

/**
 * Выводит список в консоль.
 */
void Show(DoubleLinkedList* linkedList);

/**
 * Сортирует список.
 */
void SortList(DoubleLinkedList* linkedList);

/**
 * Ищет элемент при помощи линейного поиска.
 */
void LinearSearchElement(DoubleLinkedList* list);

/**
 * Удаляет список.
 */
void RemoveList(DoubleLinkedList* list);

/**
 * Создает список с рандомными значениями.
 * @param list список.
 * @param count кол-во элементов.
 */
void RandomValues(DoubleLinkedList* list, int count);

/**
* Измеряет время для  операций вставки после индекса, вставки в начало, удаления, вставки в конец.
*/
void TestOperations();




