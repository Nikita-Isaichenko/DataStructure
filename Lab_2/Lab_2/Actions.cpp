#include <iostream>
#include "Actions.h"
#include "DoubleLinkedList.h"
#include <chrono>

using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text << endl;
	}

	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		break;
	}

	return value;
	
}

void AddElement(List* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");

	Add(linkedList, value);
	Show(linkedList);
}

void RemoveElement(List* linkedList)
{
	int index = CheckingForDigit("Введите индекс элемента для удаления: ");

	Remove(linkedList, index);
	Show(linkedList);
}

void InsertElementInBegin(List* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");

	InsertInBegin(linkedList, value);
	Show(linkedList);
}

void InsertElementAfter(List* linkedList)
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");
	int index = CheckingForDigit("Введите индекс, после которого надо добавить элемент: ");

	InsertAfter(linkedList, index, value);
	Show(linkedList);
}

void InsertElementBefore(List* linkedList) 
{
	int value = CheckingForDigit("Введите значение добавляемого элемента: ");
	int index = CheckingForDigit("Введите индекс, перед которым надо добавить элемент: ");

	InsertBefore(linkedList, index, value);
	Show(linkedList);
}

void SortList(List* list)
{
	InsertionSort(list);
	Show(list);
}

void Show(List* list)
{
	Node* node = list->Head;

	cout << "Двусвязный список: " << endl;

	while (node != nullptr)
	{
		cout << node->Value << " ";

		node = node->Next;
	}

	cout << endl << "Length: " << list->Length << endl;

}

void LinearSearchElement(List* list)
{
	int value = CheckingForDigit("Введите значение искомого элемента: ");

	int desiredIndex = LinearSearch(list, value);
	if (desiredIndex != -1)
	{
		cout << "Искомый элемент находится под индексом: "
			<< desiredIndex << endl;
	}
	else 
	{
		cout << "Искомого элемента в списке нет" << endl;
	}
}

void RemoveList(List* list)
{
	if (list->Head == nullptr)
	{
		return;
	}

	int index = 0;
	Node* temp = list->Head->Next;

	while (temp != nullptr)
	{
		delete temp->Previos;
		list->Length--;
		temp = temp->Next;
	}

	delete temp;
	list->Length--;
	list->Head = nullptr;
	list->Tail = nullptr;
}

void RandomValues(List* list, int count)
{
	srand(time(nullptr));

	for (int i = 0; i < count; i++)
	{
		Add(list, rand() % 100);
	}
}

void TestOperations() 
{
	List* list = new List();

	for (int step = 10000; step <= 1000000; step += 10000)
	{
		RemoveList(list);
		int testValue = 10;
		RandomValues(list, step);
		auto start = chrono::steady_clock::now();
		InsertBefore(list, list->Length/2, testValue);
		//InsertInBegin(list, testValue);
		//Remove(list, list->Length / 2);
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<std::chrono::microseconds>(end - start).count()
			<< ", " << step << endl;
	}
}