#include "Dictionary.h"

bool AddItem(Dictionary* dict, string value, string key)
{
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
