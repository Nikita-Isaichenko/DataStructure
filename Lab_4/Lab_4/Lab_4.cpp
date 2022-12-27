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

void PrintInfo(Dictionary* dictionary) 
{
	cout << "HashTable" << endl;
	cout << "______________________________________________________" << endl;
	PrintHashTable(dictionary->Table);
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
	dictionary->Table = InitHashTable(2);

	while (true)
	{
		cout << "1. Добавить." << endl;
		cout << "2. Удалить." << endl;
		cout << "3. Вывести информацию." << endl;
		cout << "4. Найти." << endl;

		int number = CheckingForDigit("Выберите действие: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (number)
		{
			case 1: 
			{
				string key = IsEmptyString("Введите ключ: ");
				string value = IsEmptyString("Введите значение: ");

				if (!AddItem(dictionary, value, key)) 
				{
					cout << "Ошибка, повторение ключа и значения" << endl;
				}
				else
				{
					PrintInfo(dictionary);
				}

				int maxOccupancy = dictionary->Table->Capacity * 4 / 3;

				if (dictionary->Table->Count == maxOccupancy)
				{
					dictionary->Table = Rehashing(dictionary->Table);
				}

				break;
			}
			case 2:
			{
				string key = IsEmptyString("Введите ключ: ");
				
				if (RemoveItem(dictionary, key) == -1)
				{
					cout << "Ошибка, такого ключа нет." << endl;
				}
				else
				{
					cout << "Элемент удален." << endl;
					PrintInfo(dictionary);
				}

				break;
			}
			case 3:
			{
				PrintInfo(dictionary);
				break;
			}
			case 4:
			{
				string key = IsEmptyString("Введите ключ: ");

				string searchValue = FindItem(dictionary, key);
				if (searchValue == "")
				{
					cout << "Значение не найдено." << endl;
				}
				else 
				{
					cout << "Найденное значение: " << searchValue << endl;
				}
				break;
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

