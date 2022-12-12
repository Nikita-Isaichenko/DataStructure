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

//TODO: naming
/**
 * ������ ���������� � ���������� ������.
 */
struct DoubleLinkedList
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
void InitList(DoubleLinkedList* list);

/**
 * ��������� ������� � ����� ������.
 * @param list ������.
 * @param value ����������� ��������.
 */
void Add(DoubleLinkedList* list, int value);

/**
 * ������� ������� �� ������ �� �������.
 * @param index ������ ���������� ��������.
 */
void Remove(DoubleLinkedList* list, int index);

/**
 * ������� �������� � ������.
 * @param list ������.
 * @param value �������� ��������.
 */
void InsertInBegin(DoubleLinkedList* list, int value);

/**
 * ������� �������� ����� ���������� �������.
 * @param list ������.
 * @param index ������.
 * @param value �������� ��������.
 */
void InsertAfter(DoubleLinkedList* list, int index, int value);

/**
 * ������� ����� ���������� �������.
 * @param list ������.
 * @param index ������.
 * @param value �������� ��������.
 */
void InsertBefore(DoubleLinkedList* list, int index, int value);

/**
 * ���������� ���������.
 * @param list ������.
 */
void InsertionSort(DoubleLinkedList* list);

/**
 * ������������ ���� �����.
 * @param list ������.
 * @param first ������ ����.
 * @param second ������ ����.
 */
void SwapElements(DoubleLinkedList* list, Node* first, Node* second);

/**
 * �������� ����� ��������.
 * @param list ������.
 * @param element ������� �������.
 */
int LinearSearch(DoubleLinkedList* list, int element);

/**
 * ��������� ��������. ���� ������ ������ ��������, ������� ������ ���� � �����,
 * ���� ������ ������ ��������, ������� ������ ���� � ������.
 * @param list ������.
 * @param index ������ ��������.
 */
Node* GetElement(DoubleLinkedList* list, int index);




