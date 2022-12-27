#pragma once
#include "HashTable.h"
#include <string>

using namespace std;

/**
 * Хранит данные о словаре.
 */
struct Dictionary
{
	/**
	 * Хеш-таблица.
	 */
	HashTable* Table = new HashTable;
};

/**
 * Добавляет элемент в словарь.
 */
bool AddItem(Dictionary* dict, string value, string key);

/**
 * Удаляет элемент из словаря.
 */
int RemoveItem(Dictionary* dict, string key);

/**
 * Поиск элемента в словаре.
 */
string FindItem(Dictionary* dict, string key);