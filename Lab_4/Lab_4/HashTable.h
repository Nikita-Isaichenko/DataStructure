#pragma once
#include "Node.h"
#include <string>

using namespace std;


struct HashTable
{
	/**
	 * ������ �����.
	 */
	const int GrowthFactor = 2;

	/**
	 * ���������� ����������.
	 */
	float CoefficientOccupancy = 4.0 / 3.0;

	/**
	 * ���-�� ���������.
	 */
	int Count;

	/**
	 * ������ ������.
	 */
	int Capacity;

	/**
	 * ������������ ������.
	 */
	Node** Array;
};


/**
 * ������������� ���-�������.
 */
HashTable* InitHashTable(int capacity);

/**
 * ���������� ���� ����-��������.
 */
bool AddElement(HashTable* table, string key, string value);

/**
 * �������� �������� �� �����.
 */
int RemoveElement(HashTable* table, string key);

/**
 * ������ �������� �� �����.
 */
string FindElement(HashTable* table, string key);

/**
 * �������� �������.
 */
HashTable* Rehashing(HashTable* table);

/**
 * ��� �������.
 */
int HashFunction(int capacity, string key);

/**
 * ��������� ��������.
 */
bool ResolveCollisions(Node* first, Node* node);