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
void AddElement(DoubleLinkedList* linkedList);

/**
 * ������� �������.
 */
void RemoveElement(DoubleLinkedList* linkedList);

/**
 * ��������� ������� � ������.
 */
void InsertElementInBegin(DoubleLinkedList* linkedList);

/**
 * ��������� ������� �����.
 */
void InsertElementAfter(DoubleLinkedList* linkedList);

/**
 * ��������� ������� ��.
 */
void InsertElementBefore(DoubleLinkedList* linkedList);

/**
 * ������� ������ � �������.
 */
void Show(DoubleLinkedList* linkedList);

/**
 * ��������� ������.
 */
void SortList(DoubleLinkedList* linkedList);

/**
 * ���� ������� ��� ������ ��������� ������.
 */
void LinearSearchElement(DoubleLinkedList* list);

/**
 * ������� ������.
 */
void RemoveList(DoubleLinkedList* list);

/**
 * ������� ������ � ���������� ����������.
 * @param list ������.
 * @param count ���-�� ���������.
 */
void RandomValues(DoubleLinkedList* list, int count);

/**
* �������� ����� ���  �������� ������� ����� �������, ������� � ������, ��������, ������� � �����.
*/
void TestOperations();




