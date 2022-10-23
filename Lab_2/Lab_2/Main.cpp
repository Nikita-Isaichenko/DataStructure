#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	List* list = new List();

	InitList(list);

	Add(list, 2);
	
	Remove(list, 0);

	Show(list);

	Add(list, 5);

	Show(list);
}