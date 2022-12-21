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
 * ������ ������ � ������� �� ������ ���� ������.
 */
struct QueueTwoStacks
{
	// ����, �������� �������� ������.
	Stack* InputStack;

	// ����, �������� ��������� ������.
	Stack* OutputStack;
};

/**
 * �������������� ������� �� ������ ���� ������.
 */
QueueTwoStacks* InitQueueTwoStacks(int size);

/**
 * ��������� �������� � �������.
 */
void Enqueue(QueueTwoStacks* queue, int data);

/**
 * ������� �������� �� �������.
 */
int Dequeue(QueueTwoStacks* queue);

/**
 * ���������� ������ �������.
 */
int LengthQueueTwoStacks(QueueTwoStacks* queue);

/**
 * ������� �������.
 */
void DeleteQueueTwoStacks(QueueTwoStacks* queue);




