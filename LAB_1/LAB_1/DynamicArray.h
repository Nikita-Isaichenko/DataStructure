#pragma once
/*****************************************************************//**
 * \file   DynamicArray.h
 * \brief  
 * 
 * \author nikit
 * \date   November 2022
 *********************************************************************/

/**
 * ��������� ������������� �������.
 */
struct DynamicArray
{
	const double Growth = 1.5;
	bool IsSorted;
	int* Array;
	int Size;
	int Capacity;
};

/**
 * �������������� ��������� ������������ ������.
 */
void InitDynamicArray(DynamicArray* array);

/**
 * ����������� ��� ��������� ������ ������ ��� �������.
 */
void ResizeDynamicArray(DynamicArray* array);

/**
 * ��������� ���� �� �������� ������ �������.
 */
void CheckResizeDynamicArray(DynamicArray* array);

/**
 * ��������� ������� � ����� ������������� �������.
 */
void Add(DynamicArray* array, int element);

/**
 * ������� ������� �� ������������� ������� �� �������.
 */
void RemoveAt(DynamicArray* array, int index);

/**
 * ��������� � ������������ ������ ������� �� ���������� �������.
 */
int Insert(DynamicArray* array, int  element, int index);

/**
 * ��������� ������������ ������.
 */
void Sort(DynamicArray* array);

/**
 * �������������� ������������ ������ �������� ���-��� ��������� ���������.
 */
void InitRandomElements(DynamicArray* array, int size);

/**
 * ���������, ������ �� ��������� ������ � ������������ ������.
 */
bool CheckIndexOutRange(DynamicArray* array, int index);

/**
 * ������������ �������� ����� �������� �� ������������� �������.
 */
int LinearSearch(DynamicArray* array, int element);

/**
 * ������������ �������� ����� �������� �� ������������� �������.
 */
int BinarySearch(DynamicArray* array, int element);

/**
 * ������� ������������ ������.
 */
void DeleteArray(DynamicArray* array);




