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

QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer);

void EnqueueRingBuffer(QueueRingBuffer* queue, int data);

int DequeueRingBuffer(QueueRingBuffer* queue);

void DeleteQueueRingBuffer(QueueRingBuffer* queue);

/**
 * Возвращает кол-во элементов в очереди.
 */
int LenghtQueueRingBuffer(QueueRingBuffer* queue);




