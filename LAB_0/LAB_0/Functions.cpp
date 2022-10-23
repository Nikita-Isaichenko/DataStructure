#include <iostream>
#include "Functions.h"
#include <random>

using namespace std;


void Sort(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = i + 1; j < arraySize; j++)
		{
			if (array[j] < array[i])
			{
				swap(array[j], array[i]);
			}
		}
	}

	PrintArray(array, arraySize);
}

void Sort(double array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = i + 1; j < arraySize; j++)
		{
			if (array[j] < array[i])
			{
				swap(array[j], array[i]);
			}
		}
	}

	PrintArray(array, arraySize);
}

void PrintArray(double* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << ' ';
	}

	cout << endl;
}

void PrintArray(int* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << ' ';
	}

	cout << endl;
}

void PrintArray(char* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << ' ';
	}

	cout << endl;
}

void PrintArray(bool* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << ' ';
	}

	cout << endl;
}

double GetPower(double base, int exponent)
{
	return pow(base, exponent);
}

void DemoGetPower(double base, int exponent)
{
	cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

void RoundToTens(int& value)
{
	int remainder = value % 10;

	if (remainder < 5)
	{
		value = (value / 10) * 10;
	}
	else
	{
		value += 10 - remainder;
	}
}

void Foo(double a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;

	a = 15.0;

	cout << "New value of a in Foo(): " << a << endl;
}

void FooWithLink(double& a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;

	a = 15.0;

	cout << "New value of a in Foo(): " << a << endl;
}

void FooWithPointer(double* a)
{
	cout << "Address in pointer: " << a << endl;
	cout << "Address of pointer: " << &a << endl;
	cout << "Value in pointer address: " << *a << endl;

	*a = 15.0;

	cout << "New value in pointer address: " << *a << endl;
}

int ValueIndexInArray(int* array, int arraySize, int value)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] == value) return i;
	}

	return -1;
}

void PrintOnlyLetters(char* array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if ((array[i] > 'a' && array[i] < 'z') 
			|| (array[i] > 'A' && array[i] < 'Z'))
		{
			cout << array[i] << ' ';
		}
	}

	cout << endl;
}

int* MakeRandomArray(int arraySize)
{
	srand(time(nullptr));

	int* array = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % 101;
	}

	return array;
}

int* ReadArray(int count)
{
	int* values = new int[count];

	for (int i = 0; i < count; i++)
	{
		cin >> values[i];
	}

	return values;
}

int CountPositiveValues(int* values, int count)
{
	int result = 0;

	for (int i = 0; i < count; i++)
	{
		if (values[i] > 0)
		{
			result++;
		}
	}

	return result;
}

void Breakpoints()
{
	double add = 1.0;
	double sum = 0.0;

	for (int i = 0; i < 10; i++) // 0; 1,1; 3.52; 7.513, 13.37; 21,42....
	{
		sum += add * i;
		add *= 1.1;
	}

	cout << "Total sum is " << sum << endl;
}

void Breakpoints2()
{
	double add = 1.0;
	double sum = 0.0;

	for (int i = 0; i < 1000; i++)
	{
		sum += add * i; // sum == 3.2624579394327844	

		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
	}

	cout << "Total sum is " << sum << endl;
}
