#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	List* list = new List();

	Add(list, 2);
	Add(list, 3);
	Add(list, 4);
	Add(list, 2);
	Add(list, 7);
	Add(list, 9);

	Show(list);
}