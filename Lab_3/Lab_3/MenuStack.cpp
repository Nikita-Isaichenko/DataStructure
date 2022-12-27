#include "MenuStack.h"
#include "Stack.h"
#include <iostream>
#include "Validation.h"
#include "IOStack.h"

using namespace std;


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
		cout << "5. Вернуться назад." << endl;

		int key = CheckingForDigit("Введите номер действия: ");

		cout << "\n--------------------------------------------" << endl;
		cout << "                                           |" << endl;

		switch (key)
		{
			//TODO: done
			case 0:
			{
				system("cls");
				break;
			}
			case 1:
			{
				if (stack == nullptr)
				{
					int size = CheckingForDigit("Введите размер для стека: ");
					stack = CreateStack(stack, size);
					if (size < stack->MinCapacity) 
					{
						cout << "Размер стека меньше минимального, поэтому"
							"поэтому он автоматически определен до минимального (" <<
							stack->MinCapacity << ")." << endl;
					}
				}
				else
				{
					cout << "Стек уже создан." << endl;
				}
			
				break;
			}
			case 2:
			{
				PushStack(stack);
				break;
			}
			case 3:
			{
				PopStack(stack);
				break;
			}
			case 4:
			{
				DeleteStack(stack);
				stack = nullptr;
				break;
			}
			case 5:
			{
				DeleteStack(stack);
				stack = nullptr;
				system("cls");
				return;
			}
			default:
			{
				cout << "Некорректный номер." << endl;
				break;
			}
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	}
}

