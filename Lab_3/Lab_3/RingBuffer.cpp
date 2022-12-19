#include "RingBuffer.h"

const int Capacity = 4;


void InitRingBuffer(RingBuffer* buffer)
{
	buffer->Size = Capacity;
	buffer->FreeMemory = Capacity;
	buffer->UsedMemory = 0;
	buffer->Buffer = new int[buffer->Size];
	buffer->IndexInput = 0;
	buffer->IndexOutput = 0;
}

void Push(RingBuffer* buffer, int data)
{
	if (buffer->IndexInput > buffer->Size - 1)
	{
		buffer->IndexInput = 0;
	}

	if (FreeMemoryInfo(buffer) == 0)
	{
		Resize(buffer);
	}

	
	buffer->Buffer[buffer->IndexInput++] = data;
	buffer->FreeMemory--;
	buffer->UsedMemory++;
	
}

void Resize(RingBuffer* buffer)
{
	int oldSize = buffer->Size;

	int* tempArray = new int[buffer->Size *= buffer->GrowthFactor];

	for (int i = 0; i < oldSize; i++)
	{
		tempArray[i] = buffer->Buffer[buffer->IndexOutput++];

		if (buffer->IndexOutput > oldSize - 1)
		{
			buffer->IndexOutput = 0;
		}
	}

	buffer->IndexOutput = 0;
	buffer->IndexInput = oldSize;
	buffer->FreeMemory = buffer->Size - oldSize;
}

int Pop(RingBuffer* buffer) 
{
	if (UsedMemoryInfo(buffer) > 0) 
	{
		buffer->FreeMemory++;
		buffer->UsedMemory--;
		return buffer->Buffer[buffer->IndexOutput++];	
	}
}

int FreeMemoryInfo(RingBuffer* buffer)
{
	return buffer->FreeMemory;
}

int UsedMemoryInfo(RingBuffer* buffer)
{
	return buffer->UsedMemory;
}

void Clear(RingBuffer* buffer)
{
	buffer->FreeMemory = buffer->Size;
	buffer->UsedMemory = 0;
	buffer->IndexInput = buffer->IndexOutput;

}
