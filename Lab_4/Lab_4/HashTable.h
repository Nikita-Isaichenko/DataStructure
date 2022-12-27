#pragma once
#include "Node.h"
#include <string>

using namespace std;


struct HashTable
{
	/**
	 * Фактор роста.
	 */
	const int GrowthFactor = 2;

	/**
	 * Кол-во элементов.
	 */
	int Count;

	/**
	 * Размер буфера.
	 */
	int Capacity;

	/**
	 * Динамический массив.
	 */
	Node** Array;
};


/**
 * Инициализация хеш-таблицы.
 */
HashTable* InitHashTable(int capacity);

/**
 * Добавление пары ключ-значение.
 */
bool AddElement(HashTable* table, string key, string value);

/**
 * Удаление элемента по ключу.
 */
int RemoveElement(HashTable* table, string key);

/**
 * Поиска элемента по ключу.
 */
string FindElement(HashTable* table, string key);

/**
 * Рехешинг таблицы.
 */
HashTable* Rehashing(HashTable* table);

/**
 * Хеш функция.
 */
int HashFunction(int capacity, string key);

/**
 * Удаление .
 */
void RemoveHashTable(HashTable* table);

/**
 * Разрешает коллизии.
 */
bool ResolveCollisions(Node* first, Node* node);