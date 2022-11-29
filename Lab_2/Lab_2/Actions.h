/*****************************************************************//**
 * \file   Actions.h
 * \brief  
 * 
 * \author nikit
 * \date   November 2022
 *********************************************************************/
#pragma once
#include "DoubleLinkedList.h"

/**
 * ��������� �������.
 */
void AddElement(List* linkedList);

/**
 * ������� �������.
 */
void RemoveElement(List* linkedList);

/**
 * ��������� ������� � ������.
 */
void InsertElementInBegin(List* linkedList);

/**
 * ��������� ������� �����.
 */
void InsertElementAfter(List* linkedList);

/**
 * ��������� ������� ��.
 */
void InsertElementBefore(List* linkedList);

/**
 * ������� ������ � �������.
 */
void Show(List* linkedList);

/**
 * ��������� ������.
 */
void SortList(List* linkedList);

/**
 * ���� ������� ��� ������ ��������� ������.
 */
void LinearSearchElement(List* list);

/**
 * ���������, �������� �������� ������ ������.
 * @param text �������� ��� �����.
 */
int CheckingForDigit(const char* text);

/**
 * ������� ������.
 */
void RemoveList(List* list);

/**
 * ������� ������ � ���������� ����������.
 * @param list ������.
 * @param count ���-�� ���������.
 */
void RandomValues(List* list, int count);

/**
* �������� ����� ���  �������� ������� ����� �������, ������� � ������, ��������, ������� � �����.
*/
void TestOperations();




