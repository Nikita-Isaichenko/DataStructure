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
RingBuffer* InitRingBuffer(int sizeBuffer);

/**
 * ������ �������� � ��������� �����.
 */
void PushRingBuffer(RingBuffer* buffer, int data);

/**
 * ������� �������� �� ��������� ������.
 */
int PopRingBuffer(RingBuffer* buffer);

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
void ResizeRingBuffer(RingBuffer* buffer);



