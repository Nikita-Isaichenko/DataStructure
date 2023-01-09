#include "HashTable.h"


HashTable* InitHashTable(int capacity)
{
	HashTable* table = new HashTable;

	table->Count = 0;
	table->Capacity = capacity;
	table->Array = new Node* [table->Capacity];

	for (int i = 0; i < table->Capacity; i++)
	{
		table->Array[i] = nullptr;
	}

	return table;
}

bool AddElement(HashTable* table, string key, string value)
{
	int index = HashFunction(table->Capacity, key);

	Node* node = new Node;

	if (table->Array[index] == nullptr)
	{
		node->Key = key;
		node->Value = value;

		table->Array[index] = node;
		table->Count++;

		return true;
	}

	node->Key = key;
	node->Value = value;

	if (ResolveCollisions(table->Array[index], node))
	{
		table->Count++;

		return true;
	}

	return false;
}

int RemoveElement(HashTable* table, string key)
{
	int index = HashFunction(table->Capacity, key);

	Node* current = table->Array[index];
	Node* previous = nullptr;

	if (current == nullptr) 
	{
		return -1;
	}

	if (current->Next == nullptr && current->Key == key)
	{
		delete current;
		table->Array[index] = nullptr;
		table->Count--;
		return 0;
	}

	while (current->Key != key)
	{
		previous = current;
		current = current->Next;

		if (current == nullptr)
		{
			return -1;
		}
	}

	if (previous != nullptr)
	{
		previous->Next = current->Next;
		delete current;
		table->Count--;
	}
	else 
	{
		Node* nextNode = current->Next;
		delete current;
		table->Count--;
		table->Array[index] = nextNode;
	}

	return 0;
}

string FindElement(HashTable* table, string key)
{
	Node* current = table->Array[HashFunction(table->Capacity, key)];

	if (current == nullptr)
	{
		return "";
	}

	if (current->Next == nullptr)
	{
		return current->Value;
	}

	while (current->Key != key)
	{
		current = current->Next;
	}
	return current->Value;
}

int HashFunction(int capacity, string key)
{
	int size = key.length();
	int hash = 0;

	for (int i = 0; i < size; i++)
	{
		hash = (hash * (capacity - 1) + key[i]) % capacity;
	}

	return abs(hash);
}

HashTable* Rehashing(HashTable* table)
{
	HashTable* newTable = InitHashTable(table->Capacity * table->GrowthFactor);

	Node* current;

	for (int i = 0; i < table->Capacity; i++)
	{
		current = table->Array[i];

		if (current != nullptr)
		{
			while (current != nullptr)
			{
				AddElement(newTable, current->Key, current->Value);
				current = current->Next;
			}
		}	
	}

	delete[] table->Array;
	delete table;

	return newTable;
}

bool ResolveCollisions(Node* first, Node* node)
{
	while (first != nullptr)
	{
		if (first->Key == node->Key && first->Value == node->Value)
		{
			return false;
		}

		if (first->Next == nullptr)
		{
			first->Next = node;
			return true;
		}

		first = first->Next;
	}
}
