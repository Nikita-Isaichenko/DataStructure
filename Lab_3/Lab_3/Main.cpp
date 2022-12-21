#include <iostream>
#include "Validation.h"
#include "MenuQueueRingBuffer.h"
#include "MenuRingBuffer.h"
#include "MenuStack.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    
	while (true)
	{
		cout << "1. Работа со стеком." << endl;
		cout << "2. Работа с кольцевым буффером." << endl;
		cout << "3. Работа с очередью на основе кольцевого буфера." << endl;
		cout << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		switch (key)
		{
		case 1:
			system("cls");
			MenuStack();
			break;
		case 2:
			system("cls");
			MenuRingBuffer();
			break;
		case 3:
			system("cls");
			MenuQueueRingBuffer();
			break;
		default:
			cout << "Некорректный номер." << endl;
			break;
		}
	}
}


