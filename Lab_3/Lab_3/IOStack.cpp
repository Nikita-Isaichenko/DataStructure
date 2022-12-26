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
	else
	{
		cout << "Стек не создан. Создайте стек!" << endl;
	}
	
}

void PopStack(Stack* stack)
{
	if (IsCreated(stack)) 
	{
		if (IsEmptyStack(stack))
		{
			cout << "Стек пуст." << endl;
			return;
		}

		cout << "Получаемое значение: " << Pop(stack) << endl;

		PrintStack(stack);
	}
	else
	{
		cout << "Стек не создан. Создайте стек!" << endl;
	}
}

void PrintStack(Stack* stack)
{
	cout << "Размер стека: " << stack->Capacity << endl;

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
		cout << "Стек уже создан!" << endl;
		return stack;
	}

	cout << "Стек успешно создан." << endl;

	if (size < stack->MinCapacity)
	{
		cout << "Введенный размер меньше минимального (" <<
			stack->MinCapacity << ") поэтому размер приведен к минимальному." << endl;
	}

	return InitStack(size);
	
}

void DeleteStack(Stack* stack)
{
	if (IsCreated(stack)) 
	{
		Delete(stack);
		cout << "Стек успешно удален." << endl;
	}
	else
	{
		cout << "Стек не создан. Создайте стек!" << endl;
	}
}
