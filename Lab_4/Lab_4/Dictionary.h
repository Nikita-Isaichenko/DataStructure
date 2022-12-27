#pragma once
#include "HashTable.h"
#include <string>

using namespace std;

/**
 * ������ ������ � �������.
 */
struct Dictionary
{
	/**
	 * ���-�������.
	 */
	HashTable* Table = new HashTable;
};

/**
 * ��������� ������� � �������.
 */
bool AddItem(Dictionary* dict, string value, string key);

/**
 * ������� ������� �� �������.
 */
int RemoveItem(Dictionary* dict, string key);

/**
 * ����� �������� � �������.
 */
string FindItem(Dictionary* dict, string key);