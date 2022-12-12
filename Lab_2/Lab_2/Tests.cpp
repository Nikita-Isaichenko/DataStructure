#include "Tests.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <chrono>

using namespace std;

void TestOperations()
{
	DoubleLinkedList* list = new DoubleLinkedList();

	for (int step = 10000; step <= 1000000; step += 10000)
	{
		RemoveList(list);
		int testValue = 10;
		RandomValues(list, step);
		auto start = chrono::steady_clock::now();
		InsertBefore(list, list->Length / 2, testValue);
		//InsertInBegin(list, testValue);
		//Remove(list, list->Length / 2);
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<std::chrono::microseconds>(end - start).count()
			<< ", " << step << endl;
	}
}
