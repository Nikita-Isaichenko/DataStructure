#pragma once
/*****************************************************************//**
 * \file   RingBuffer.h
 * \brief  
 * 
 * \author nikit
 * \date   December 2022
 *********************************************************************/

/**
 * Хранит информацию о буфере.
 */
struct RingBuffer 
{
	/**
	 * Свободное место в буфере.
	 */
	int FreeMemory;

	/**
	 * Занятое место в буфере.
	 */
	int UsedMemory;

	/**
	 * Буфер.
	 */

	int* Buffer;

	/**
	 * Размер буфера.
	 */
	int Size;
	
	/**
	 * Индекс в который производится запись.
	 */
	int IndexInput;

	/**
	 * Индекс из которого производится чтение.
	 */
	int IndexOutput;

	const int GrowthFactor = 2;
};

/**
 * Инициализирует кольцевой буфер.
 */
void InitRingBuffer(RingBuffer* buffer);

/**
 * Кладем значение в кольцевой буфер.
 */
void Push(RingBuffer* buffer, int data);

/**
 * Достаем значение из кольцевой буфера.
 */
int Pop(RingBuffer* buffer);

/**
 * Вовращает информацию о свободном месте в кольцевом буфере.
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
 * Возвращает информацию о занятом месте в кольцевом буфере.
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
 * Изменяет размер буфера.
 */
void Resize(RingBuffer* buffer);

/**
 * Очищает буфер.
 */
void Clear(RingBuffer* buffer);




