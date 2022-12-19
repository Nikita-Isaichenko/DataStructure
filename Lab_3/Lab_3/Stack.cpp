#include "Stack.h"
#include <iostream>

const int Capacity = 3;

Stack* InitStack(Stack* stack)
{
	stack = new Stack();

	stack->Capacity = Capacity;
	stack->Buffer = new int[stack->Capacity];
	stack->Top = -1;

	return stack;
}

void Push(Stack* stack, int data)
{
	stack->Top++;

	CheckResize(stack);

	
	stack->Buffer[stack->Top] = data;

}

int Pop(Stack* stack) 
{
	if (!IsEmpty(stack))
	{
		int value = stack->Buffer[stack->Top];
		stack->Top--;

		CheckResize(stack);

		return value;
	}
}

void Resize(Stack* stack)
{
	int* tempArray = new int[stack->Capacity];

	for (int i = 0; i <= stack->Top; i++)
	{
		tempArray[i] = stack->Buffer[i];
	}

	delete[] stack->Buffer;

	stack->Buffer = tempArray;
}

void CheckResize(Stack* stack)
{
	if (stack->Top >= stack->Capacity - 1)
	{
		stack->Capacity = stack->Capacity * stack->GrowthFactor;
		Resize(stack);
		return;
	}

	if (stack->Top <= (stack->Capacity / stack->GrowthFactor) - 1
		&& stack->Capacity > Capacity)
	{
		stack->Capacity = stack->Capacity / stack->GrowthFactor;
		Resize(stack);
		return;
	}
}

bool IsEmpty(Stack* stack)
{
	return stack->Top == -1;
}

void Delete(Stack* stack)
{
	delete[] stack->Buffer;
	delete stack;
}
