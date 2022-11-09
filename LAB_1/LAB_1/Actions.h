#pragma once
/*****************************************************************//**
 * \file   Actions.h
 * \brief  
 * 
 * \author nikit
 * \date   November 2022
 *********************************************************************/
#include "DynamicArray.h"
/**
 * Создает динамический массив.
 */
void CreatDynamicArray(DynamicArray* dynamicArray);

/**
 * Добавляет элемент в конец динамического массива.
 */
void AddElement(DynamicArray* dynamicArray);

/**
 * Удаляет элемент из динамического массива по индексу.
 */
void RemoveElement(DynamicArray* dynamicArray);

/**
 * Вставляет в динамический массив элемент по указанному индексу.
 */
void InsertElement(DynamicArray* dynamicArray);

/**
 * Сортирует динамический массив.
 */
void SortArray(DynamicArray* dynamicArray);

/**
 * Осуществляет линейный поиск элемента по динамическому массиву.
 */
void LinearSearchElement(DynamicArray* dynamicArray);

/**
 * Осуществляет бинарный поиск элемента по динамическому массиву.
 */
void BinarySearchElement(DynamicArray* dynamicArray);

/**
 * Пересоздает динамический массив.
 */
void RecreatDynamicArray(DynamicArray* dynamicArray);

/**
 * Выводит динамический массив.
 */
void ShowArray(DynamicArray* dynamicArray);



