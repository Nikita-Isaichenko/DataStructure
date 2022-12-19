#include <iostream>
#include "IOStack.h"
#include "Validation.h"
#include "Stack.h"

using namespace std;


void PushStack(Stack* stack)
{
	if (IsCreated(stack))
	{
		int value = CheckingForDigit("Введите добавляемое значение: ");

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
			cout << "Стек пуст." << endl;
			return;
		}

		cout << "Получаемое значение: " << Pop(stack) << endl;

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
		cout << "Стек не создан. Создайте стек!" << endl;
		return false;
	}

	return true;
}

Stack* CreateStack(Stack* stack)
{
	if (IsCreated(stack))
	{
		cout << "Стек уже создан!" << endl;
		return stack;
	}

	cout << "Стек успешно создан." << endl;
	return InitStack(stack);
	
}

void DeleteStack(Stack* stack)
{
	if (IsCreated(stack)) 
	{
		Delete(stack);
		cout << "Стек успешно удален." << endl;
	}
}
