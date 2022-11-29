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
void AddElement(List* linkedList);

/**
 * Удаляет элемент.
 */
void RemoveElement(List* linkedList);

/**
 * Вставляет элемент в начало.
 */
void InsertElementInBegin(List* linkedList);

/**
 * Вставляет элемент после.
 */
void InsertElementAfter(List* linkedList);

/**
 * Вставляет элемент до.
 */
void InsertElementBefore(List* linkedList);

/**
 * Выводит список в консоль.
 */
void Show(List* linkedList);

/**
 * Сортирует список.
 */
void SortList(List* linkedList);

/**
 * Ищет элемент при помощи линейного поиска.
 */
void LinearSearchElement(List* list);

/**
 * Проверяет, является вводимая строка числом.
 * @param text описания для ввода.
 */
int CheckingForDigit(const char* text);

/**
 * Удаляет список.
 */
void RemoveList(List* list);

/**
 * Создает список с рандомными значениями.
 * @param list список.
 * @param count кол-во элементов.
 */
void RandomValues(List* list, int count);

/**
* Измеряет время для  операций вставки после индекса, вставки в начало, удаления, вставки в конец.
*/
void TestOperations();




