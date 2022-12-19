#pragma once
/*****************************************************************//**
 * \file   RingBuffer.h
 * \brief  
 * 
 * \author nikit
 * \date   December 2022
 *********************************************************************/

/**
 * ������ ���������� � ������.
 */
struct RingBuffer 
{
	/**
	 * ��������� ����� � ������.
	 */
	int FreeMemory;

	/**
	 * ������� ����� � ������.
	 */
	int UsedMemory;

	/**
	 * �����.
	 */

	int* Buffer;

	/**
	 * ������ ������.
	 */
	int Size;
	
	/**
	 * ������ � ������� ������������ ������.
	 */
	int IndexInput;

	/**
	 * ������ �� �������� ������������ ������.
	 */
	int IndexOutput;

	const int GrowthFactor = 2;
};

/**
 * �������������� ��������� �����.
 */
void InitRingBuffer(RingBuffer* buffer);

/**
 * ������ �������� � ��������� �����.
 */
void Push(RingBuffer* buffer, int data);

/**
 * ������� �������� �� ��������� ������.
 */
int Pop(RingBuffer* buffer);

/**
 * ��������� ���������� � ��������� ����� � ��������� ������.
 */
int FreeMemoryInfo(RingBuffer* buffer);

/**
 * ���������� ���������� � ������� ����� � ��������� ������.
 */
int UsedMemoryInfo(RingBuffer* buffer);

/**
 * �������� ������ ������.
 */
void Resize(RingBuffer* buffer);

/**
 * ������� �����.
 */
void Clear(RingBuffer* buffer);




