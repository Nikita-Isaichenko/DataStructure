#include "Dictionary.h"

bool AddItem(Dictionary* dict, string value, string key)
{
	int index = HashFunction(dict->Table->Capacity, key);
	Node* current = dict->Table->Array[index];

	if (current == nullptr)
	{
		return AddElement(dict->Table, key, value);
	}

	while (current != nullptr)
	{
		if (current->Key == key) 
		{
			return false;
		}

		current = current->Next;
	}

	return AddElement(dict->Table, key, value);
}

int RemoveItem(Dictionary* dict, string key)
{
	return RemoveElement(dict->Table, key);
}

string FindItem(Dictionary* dict, string key)
{
	return FindElement(dict->Table, key);
}

void DeleteDictionary(Dictionary* dict)
{
	for (int i = 0; i < dict->Table->Capacity; i++)
	{
		Node* current = dict->Table->Array[i];

		while (current != nullptr)
		{
			Node* temp = current;
			current = current->Next;
			delete temp;
		}
	}

	delete[] dict->Table->Array;
	delete dict->Table;
}
