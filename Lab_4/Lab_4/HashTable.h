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
 * �������� .
 */
void RemoveHashTable(HashTable* table);

/**
 * ��������� ��������.
 */
bool ResolveCollisions(Node* first, Node* node);