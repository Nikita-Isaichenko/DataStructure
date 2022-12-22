#pragma once
#include "RingBuffer.h"
/*****************************************************************//**
 * \file   QueueRingBuffer.h
 * \brief  
 * 
 * \author nikit
 * \date   December 2022
 *********************************************************************/

/**
 * Хранит данные о структуре очередь на основе кольцевого буфера.
 */
struct QueueRingBuffer
{
	/**
	 * Кольцевой буфер.
	 */
	RingBuffer* Buffer;
};

/**
 * Инициализует кольцевой буфер.
 */
QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer);

/**
 * Добавляет элемент в кольцевой буфер.
 */
void EnqueueRingBuffer(QueueRingBuffer* queue, int data);

/**
 * Достает элемент из кольцевого буфера.
 */
int DequeueRingBuffer(QueueRingBuffer* queue);

/**
 * Удаляет кольцевой буфер.
 */
void DeleteQueueRingBuffer(QueueRingBuffer* queue);

/**
 * Возвращает кол-во элементов в очереди.
 */
int LenghtQueueRingBuffer(QueueRingBuffer* queue);




