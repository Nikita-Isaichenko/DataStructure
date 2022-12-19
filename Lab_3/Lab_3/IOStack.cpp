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
	
}

void PopStack(Stack* stack)
{
	if (IsCreated(stack)) 
	{
		if (IsEmpty(stack))
		{
			cout << "���� ����." << endl;
			return;
		}

		cout << "���������� ��������: " << Pop(stack) << endl;

		PrintStack(stack);
	}
}

void PrintStack(Stack* stack)
{
	for (int i = stack->Top; i >= 0; i--)
	{
		cout << "|____" << stack->Buffer[i] << "____|" << endl;
	}

}

bool IsCreated(Stack* stack)
{
	if (stack == nullptr) 
	{
		cout << "���� �� ������. �������� ����!" << endl;
		return false;
	}

	return true;
}

Stack* CreateStack(Stack* stack)
{
	if (IsCreated(stack))
	{
		cout << "���� ��� ������!" << endl;
		return stack;
	}

	cout << "���� ������� ������." << endl;
	return InitStack(stack);
	
}

void DeleteStack(Stack* stack)
{
	if (IsCreated(stack)) 
	{
		Delete(stack);
		cout << "���� ������� ������." << endl;
	}
}
