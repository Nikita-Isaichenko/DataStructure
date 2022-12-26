#include <iostream>
#include "IOStack.h"
#include "Validation.h"
#include "Stack.h"

using namespace std;


void PushStack(Stack* stack)
{
	if (IsCreated(stack))
	{
		int value = CheckingForDigit("������� ����������� ��������: ");

		Push(stack, value);
		PrintStack(stack);
	}
	else
	{
		cout << "���� �� ������. �������� ����!" << endl;
	}
	
}

void PopStack(Stack* stack)
{
	if (IsCreated(stack)) 
	{
		if (IsEmptyStack(stack))
		{
			cout << "���� ����." << endl;
			return;
		}

		cout << "���������� ��������: " << Pop(stack) << endl;

		PrintStack(stack);
	}
	else
	{
		cout << "���� �� ������. �������� ����!" << endl;
	}
}

void PrintStack(Stack* stack)
{
	cout << "������ �����: " << stack->Capacity << endl;

	for (int i = stack->Top; i >= 0; i--)
	{
		cout << "|____" << stack->Buffer[i] << "____|" << endl;
	}

}

bool IsCreated(Stack* stack)
{
	return stack != nullptr;
}

Stack* CreateStack(Stack* stack, int size)
{
	if (IsCreated(stack))
	{
		cout << "���� ��� ������!" << endl;
		return stack;
	}

	cout << "���� ������� ������." << endl;

	if (size < stack->MinCapacity)
	{
		cout << "��������� ������ ������ ������������ (" <<
			stack->MinCapacity << ") ������� ������ �������� � ������������." << endl;
	}

	return InitStack(size);
	
}

void DeleteStack(Stack* stack)
{
	if (IsCreated(stack)) 
	{
		Delete(stack);
		cout << "���� ������� ������." << endl;
	}
	else
	{
		cout << "���� �� ������. �������� ����!" << endl;
	}
}
