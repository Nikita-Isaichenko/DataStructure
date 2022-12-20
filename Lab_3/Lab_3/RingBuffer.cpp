#include "RingBuffer.h"


RingBuffer* InitRingBuffer(int sizeBuffer)
{
	RingBuffer* buffer = new RingBuffer();

	buffer->Size = sizeBuffer;
	buffer->FreeMemory = sizeBuffer;
	buffer->UsedMemory = 0;
	buffer->Buffer = new int[sizeBuffer];
	buffer->IndexInput = 0;
	buffer->IndexOutput = 0;

	return buffer;
}

void PushRingBuffer(RingBuffer* buffer, int data)
{
	if (buffer->IndexInput > buffer->Size - 1)
	{
		buffer->IndexInput = 0;
	}

	if (buffer->IndexInput == buffer->IndexOutput && 
		UsedMemoryInfo(buffer) > 0) 
	{
		buffer->IndexOutput++;

		if (buffer->IndexOutput > buffer->Size - 1)
		{
			buffer->IndexOutput = 0;
		}
	}

	buffer->Buffer[buffer->IndexInput++] = data;

	if (FreeMemoryInfo(buffer) > 0)
	{
		buffer->FreeMemory--;
		buffer->UsedMemory++;
	}
}

void ResizeRingBuffer(RingBuffer* buffer)
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

int PopRingBuffer(RingBuffer* buffer) 
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
