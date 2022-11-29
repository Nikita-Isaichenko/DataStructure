/*****************************************************************//**
 * \file   DoubleLinkedList.h
 * \brief  
 *
 * 
 * \author nikit
 * \date   November 2022
 *********************************************************************/
#pragma once

/**
 * ������ ���������� � ���� ����������� ������.
 */
struct Node
{
	/**
	 * ������� � ���������� ������.
	 */
	int Value;

	/**
	 * ��������� �� ��������� ���� ������.
	 */
	Node* Next;

	/**
	 * ��������� �� ���������� ���� ������.
	 */
	Node* Previos;
};

/**
 * ������ ���������� � ���������� ������.
 */
struct List
{
	/**
	 * ����� ������.
	 */
	int Length;

	/**
	 * ��������� �� ������ ������.
	 */
	Node* Head;

	/**
	 * ��������� �� ����� ������.
	 */
	Node* Tail;
};

/**
 * �������������� ������.
 * @param list ������.
 */
void InitList(List* list);

/**
 * ��������� ������� � ����� ������.
 * @param list ������.
 * @param value ����������� ��������.
 */
void Add(List* list, int value);

/**
 * ������� ������� �� ������ �� �������.
 * @param index ������ ���������� ��������.
 */
void Remove(List* list, int index);

/**
 * ������� �������� � ������.
 * @param list ������.
 * @param value �������� ��������.
 */
void InsertInBegin(List* list, int value);

/**
 * ������� �������� ����� ���������� �������.
 * @param list ������.
 * @param index ������.
 * @param value �������� ��������.
 */
void InsertAfter(List* list, int index, int value);

/**
 * ������� ����� ���������� �������.
 * @param list ������.
 * @param index ������.
 * @param value �������� ��������.
 */
void InsertBefore(List* list, int index, int value);

/**
 * ���������� ���������.
 * @param list ������.
 */
void InsertionSort(List* list);

/**
 * ������������ ���� �����.
 * @param list ������.
 * @param first ������ ����.
 * @param second ������ ����.
 */
void SwapElements(List* list, Node* first, Node* second);

/**
 * �������� ����� ��������.
 * @param list ������.
 * @param element ������� �������.
 */
int LinearSearch(List* list, int element);

/**
 * ��������� ��������. ���� ������ ������ ��������, ������� ������ ���� � �����,
 * ���� ������ ������ ��������, ������� ������ ���� � ������.
 * @param list ������.
 * @param index ������ ��������.
 */
Node* GetElement(List* list, int index);




