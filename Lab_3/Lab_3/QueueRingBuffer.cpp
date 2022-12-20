#include "QueueRingBuffer.h"


QueueRingBuffer* InitQueueRingBuffer(int sizeBuffer)
{
	QueueRingBuffer* queue = new QueueRingBuffer();

	queue->Buffer = InitRingBuffer(sizeBuffer);

	return queue;
}

void EnqueueRingBuffer(QueueRingBuffer* queue, int data)
{
	if (queue->Buffer->FreeMemory == 0)
	{
		ResizeRingBuffer(queue->Buffer);
	}

	PushRingBuffer(queue->Buffer, data);
}

int DequeueRingBuffer(QueueRingBuffer* queue)
{
	if (queue->Buffer->UsedMemory > 0)
	{
		return PopRingBuffer(queue->Buffer);
	}
}

void DeleteQueueRingBuffer(QueueRingBuffer* queue)
{
	delete[] queue->Buffer->Buffer;
	delete queue->Buffer;
}

int LenghtQueueRingBuffer(QueueRingBuffer* queue)
{
	return queue->Buffer->UsedMemory;
}
