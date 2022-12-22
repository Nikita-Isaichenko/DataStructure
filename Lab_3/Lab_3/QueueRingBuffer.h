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
 * ������ ������ � ��������� ������� �� ������ ���������� ������.
 */
struct QueueRingBuffer
{
	/**
	 * ��������� �����.
	 */
	RingBuffer* Buffer;
};

/**
 * ������������ ��������� �����.
 */
QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer);

/**
 * ��������� ������� � ��������� �����.
 */
void EnqueueRingBuffer(QueueRingBuffer* queue, int data);

/**
 * ������� ������� �� ���������� ������.
 */
int DequeueRingBuffer(QueueRingBuffer* queue);

/**
 * ������� ��������� �����.
 */
void DeleteQueueRingBuffer(QueueRingBuffer* queue);

/**
 * ���������� ���-�� ��������� � �������.
 */
int LenghtQueueRingBuffer(QueueRingBuffer* queue);




