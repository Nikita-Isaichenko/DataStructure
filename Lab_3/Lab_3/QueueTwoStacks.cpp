#include "QueueTwoStacks.h"
#include "Stack.h"

QueueTwoStacks* InitQueueTwoStacks(int size)
{
	QueueTwoStacks* queue = new QueueTwoStacks();

	queue->InputStack = InitStack(size);
	queue->OutputStack = InitStack(size);

	return queue;
}

void Enqueue(QueueTwoStacks* queue, int data)
{
	Push(queue->InputStack, data);
}

int Dequeue(QueueTwoStacks* queue)
{
	if (IsEmptyStack(queue->OutputStack))
	{
		while (!IsEmptyStack(queue->InputStack))
		{
			int data = Pop(queue->InputStack);
			Push(queue->OutputStack, data);
		}
	}

	return Pop(queue->OutputStack);
}

int LengthQueueTwoStacks(QueueTwoStacks* queue)
{
	return (queue->InputStack->Top + 1) + (queue->OutputStack->Top + 1);
}

void DeleteQueueTwoStacks(QueueTwoStacks* queue)
{
	Delete(queue->InputStack);
	Delete(queue->OutputStack);
	delete queue->InputStack;
	delete queue->OutputStack;
}

