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
 * ������� ������������ ������.
 */
void CreatDynamicArray(DynamicArray* dynamicArray);

/**
 * ��������� ������� � ����� ������������� �������.
 */
void AddElement(DynamicArray* dynamicArray);

/**
 * ������� ������� �� ������������� ������� �� �������.
 */
void RemoveElement(DynamicArray* dynamicArray);

/**
 * ��������� � ������������ ������ ������� �� ���������� �������.
 */
void InsertElement(DynamicArray* dynamicArray);

/**
 * ��������� ������������ ������.
 */
void SortArray(DynamicArray* dynamicArray);

/**
 * ������������ �������� ����� �������� �� ������������� �������.
 */
void LinearSearchElement(DynamicArray* dynamicArray);

/**
 * ������������ �������� ����� �������� �� ������������� �������.
 */
void BinarySearchElement(DynamicArray* dynamicArray);

/**
 * ����������� ������������ ������.
 */
void RecreatDynamicArray(DynamicArray* dynamicArray);

/**
 * ������� ������������ ������.
 */
void ShowArray(DynamicArray* dynamicArray);



