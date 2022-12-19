#include <iostream>
#include "Menu.h"
#include "Validation.h"
#include "Stack.h"
#include "IOStack.h"

using namespace std;

void Menu()
{
	while (true) 
	{		
		cout << "1. Работа со стеком." << endl;
		cout << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		switch (key)
		{
		case 1:
			system("cls");
			MenuStack();
			break;
		default:
			cout << "Некорректный номер." << endl;
			break;
		}
	}
}

void MenuStack()
{
	Stack* stack = nullptr;

	cout << "Стек" << endl;

	while (true)
	{
		cout << "0. Очистить консоль." << endl;
		cout << "1. Создать стек." << endl;
		cout << "2. Добавить элемент в стек." << endl;
		cout << "3. Получить элемент из стека." << endl;
		cout << "4. Удалить стек." << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (key)
		{
		case 0:
			system("cls");
			break;
		case 1:
			stack = CreateStack(stack);
			break;
		case 2:
			PushStack(stack);
			break;
		case 3:
			PopStack(stack);
			break;
		case 4:
			DeleteStack(stack);
			stack = nullptr;
			break;
		default:
			cout << "Некорректный номер." << endl;
			break;
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	}
}
