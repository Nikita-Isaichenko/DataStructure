#include "MenuStack.h"
#include "Stack.h"
#include <iostream>
#include "Validation.h"
#include "IOStack.h"

using namespace std;


void MenuStack()
{
	Stack* stack = nullptr;

	cout << "����" << endl;

	while (true)
	{
		cout << "0. �������� �������." << endl;
		cout << "1. ������� ����." << endl;
		cout << "2. �������� ������� � ����." << endl;
		cout << "3. �������� ������� �� �����." << endl;
		cout << "4. ������� ����." << endl;
		cout << "5. ��������� �����." << endl;

		int key = CheckingForDigit("������� ����� ��������: ");

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
					int size = CheckingForDigit("������� ������ ��� �����: ");
					stack = CreateStack(stack, size);
					if (size < stack->MinCapacity) 
					{
						cout << "������ ����� ������ ������������, �������"
							"������� �� ������������� ��������� �� ������������ (" <<
							stack->MinCapacity << ")." << endl;
					}
				}
				else
				{
					cout << "���� ��� ������." << endl;
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
				cout << "������������ �����." << endl;
				break;
			}
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	}
}

