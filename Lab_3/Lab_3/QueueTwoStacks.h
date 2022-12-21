#pragma once
#include "Stack.h"
/*****************************************************************//**
 * \file   QueueTwoStacks.h
 * \brief  
 * 
 * \author nikit
 * \date   December 2022
 *********************************************************************/

/**
 * Хранит данные о очереди на основе двух стеков.
 */
struct QueueTwoStacks
{
	// Стек, хранящий вводимые данные.
	Stack* InputStack;

	// Стек, хранящий выводимые данные.
	Stack* OutputStack;
};

/**
 * Инициализирует очередь на основе двух стеков.
 */
QueueTwoStacks* InitQueueTwoStacks(int size);

/**
 * Добавляет значение в очередь.
 */
void Enqueue(QueueTwoStacks* queue, int data);

/**
 * Достает значение из очереди.
 */
int Dequeue(QueueTwoStacks* queue);

/**
 * Возвращает размер очереди.
 */
int LengthQueueTwoStacks(QueueTwoStacks* queue);

/**
 * Удаляет очередь.
 */
void DeleteQueueTwoStacks(QueueTwoStacks* queue);




