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
		cout << "1. ������ �� ������." << endl;
		cout << endl;

		int key = CheckingForDigit("������� ����� ��������: ");

		switch (key)
		{
		case 1:
			system("cls");
			MenuStack();
			break;
		default:
			cout << "������������ �����." << endl;
			break;
		}
	}
}

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

		int key = CheckingForDigit("������� ����� ��������: ");

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
			cout << "������������ �����." << endl;
			break;
		}

		cout << "                                           |" << endl;
		cout << "--------------------------------------------\n" << endl;
	}
}
