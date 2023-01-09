#include <iostream>
#include "Validation.h"
#include "Dictionary.h"

using namespace std;

string IsEmptyString(const char* text)
{
	while (true)
	{
		cout << text;
		string value;
		cin >> value;

		if (value != "") 
		{
			return value;
		}
	}
}

void PrintDictionary(Dictionary* dict)
{
	Node* current;
	for (int i = 0; i < dict->Table->Capacity; i++)
	{
		current = dict->Table->Array[i];

		if (current == nullptr)
		{
			cout << "";
			continue;
		}

		while (current != nullptr)
		{
			cout << "Key: " << current->Key << "\t Value: " << current->Value;
			current = current->Next;
			cout << endl;
		}
	}
}

void PrintHashTable(HashTable* table)
{
	cout << table->Count << endl;
	Node* current;
	for (int i = 0; i < table->Capacity; i++)
	{
		current = table->Array[i];
		if (current == nullptr)
		{
			cout << "NULL\n";
			continue;
		}
		if (current->Next == nullptr)
		{
			cout << "Key: " << current->Key << "\t Value: " << current->Value << endl;
			continue;
		}
		while (current != nullptr)
		{
			cout << "Key: " << current->Key << "\t Value: " << current->Value << " -> ";
			current = current->Next;
		}
		cout << endl;
	}
}

void PrintInfo(Dictionary* dictionary, HashTable* table) 
{
	cout << endl;
	cout << "HashTable" << endl;
	cout << "______________________________________________________" << endl;
	PrintHashTable(table);
	cout << "______________________________________________________" << endl;
	cout << endl;
	cout << "Dictionary" << endl;
	cout << "______________________________________________________" << endl;
	PrintDictionary(dictionary);
	cout << "______________________________________________________" << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");

	Dictionary* dictionary = new Dictionary;
	HashTable* hashTable = new HashTable;
	hashTable = InitHashTable(4);
	dictionary->Table = InitHashTable(4);

	while (true)
	{
		cout << "1. Добавить." << endl;
		cout << "2. Удалить." << endl;
		cout << "3. Вывести информацию." << endl;
		cout << "4. Найти." << endl;
		cout << "5. Выйти." << endl;

		int number = CheckingForDigit("Выберите действие: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (number)
		{
			case 1: 
			{
				string key = IsEmptyString("Введите ключ: ");
				string value = IsEmptyString("Введите значение: ");
				AddItem(dictionary, value, key);
				AddElement(hashTable, key, value);
				
				float maxOccupancyDictionary =
					dictionary->Table->Capacity * dictionary->Table->CoefficientOccupancy;

				if (dictionary->Table->Count >= maxOccupancyDictionary)
				{
					dictionary->Table = Rehashing(dictionary->Table);
					
				}

				float maxOccupancyTable =
					hashTable->Capacity * hashTable->CoefficientOccupancy;

				if (hashTable->Count >= maxOccupancyTable)
				{
					hashTable = Rehashing(hashTable);
				}

				PrintInfo(dictionary, hashTable);

				break;
			}
			case 2:
			{
				string key = IsEmptyString("Введите ключ: ");
				
				if (RemoveItem(dictionary, key) == -1)		
				{
					cout << "Ошибка, такого ключа нет в словаре." << endl;
				}
				if (RemoveElement(hashTable, key) == -1)
				{
					cout << "Ошибка, такого ключа нет в хеш-таблице." << endl;
				}

				PrintInfo(dictionary, hashTable);

				break;
			}
			case 3:
			{
				PrintInfo(dictionary, hashTable);
				break;
			}
			case 4:
			{
				string key = IsEmptyString("Введите ключ: ");

				string searchValueDictionary = FindItem(dictionary, key);

				string searchValueTable = FindElement(hashTable, key);

				if (searchValueDictionary == "")
				{
					cout << "Значение не найдено для словаря." << endl;
				}
				else
				{
					cout << "Найденное значение в словаре: " << searchValueDictionary << endl;
				}

				if (searchValueTable == "")
				{
					cout << "Значение не найдено для хеш-таблицы." << endl;
				}
				else 
				{
					cout << "Найденное значение в хеш-таблице: " << searchValueTable << endl;
				}
				break;
			}
			case 5:
			{
				DeleteDictionary(dictionary);
				delete dictionary;
				return 0;
			}
			default:
			{
				cout << "Неверный номер задание." << endl;
				break;
			}
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	}
}

