#include <iostream>
#include "Functions.h"

using namespace std;

void Task1111() 
{
	Breakpoints();
}

void Task1112() 
{
	Breakpoints2();
}

void Task1121()
{
	const int arraySize = 10;

	int arrayInt[arraySize] = { 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };

	cout << "Source array is: " << endl;

	for (int i = 0; i < arraySize; i++)
	{
		cout << arrayInt[i] << ' ';
	}
	cout << endl;

	cout << "Sorted array is:" << endl;

	Sort(arrayInt, arraySize);
}

void Task1122()
{
	const int arraySize = 12;

	double arrayDouble[arraySize] =
		{ 12.0, 21.5, 119.2, -80.7, 300.0, 75.5, 81.2, 8.1, 47.3, 31.2, 85.3, 100.1 };

	double searchingValue = 0;

	int count = 0;

	cout << "Source array is: " << endl;

	PrintArray(arrayDouble, arraySize);

	cout << "Enter searching value: ";
	cin >> searchingValue;

	for (int i = 0; i < arraySize; i++)
	{
		if (arrayDouble[i] >= searchingValue) 
		{
			count++;
		}
	}

	cout << "Elements of array more than " << searchingValue << " is: " << count << endl;
}

void Task1123()
{
	const int arraySize = 8;

	char arrayChar[arraySize];

	cout << "Enter array of 8 chars" << endl;

	for (int i = 0; i < arraySize; i++)
	{		
		cout << "a[" << i << "]: ";
		cin >> arrayChar[i];		
	}

	cout << endl;
	cout << "Your array is: " << endl;

	PrintArray(arrayChar, arraySize);

	cout << "All letters in your array: " << endl;

	PrintOnlyLetters(arrayChar, arraySize);
}

void Task1131()
{
	double number;
	int exponent;

	cout << "Enter the number you want to raise to a power: ";
	cin >> number;
	cout << "Enter the exponent to which the number will be increased: ";
	cin >> exponent;
	cout << number << '^' << exponent << '=' << GetPower(number, exponent) << endl;
}

void Task1132() 
{
	double number;
	int exponent;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the number you want to raise to a power: ";
		cin >> number;
		cout << "Enter the exponent to which the number will be increased: ";
		cin >> exponent;
		cout << number << '^' << exponent << '=' << GetPower(number, exponent) << endl;
	}
}

void Task1133()
{
	double number;
	int exponent;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the number you want to raise to a power: ";
		cin >> number;
		cout << "Enter the exponent to which the number will be increased: ";
		cin >> exponent;

		DemoGetPower(number, exponent);
	}
}

void Task1134()
{
	int a;

	for (int i = 0; i < 3; i++) 
	{
		cout << "Enter number: ";
		cin >> a;

		cout << "For " << a << " rounded value is ";

		RoundToTens(a);

		cout << a << endl;
	}

}

void Task1141()
{
	int a = 5;

	int b = 4;

	double c = 13.5;

	bool d = true;

	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	cout << "Address of c: " << &c << endl;
	cout << "Address of d: " << &d << endl;
}

void Task1142() 
{
	int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };

	cout << "Size of int type: " << sizeof(int) << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "Address of a[" << i << "]: " << &a[i] << endl;
	}

	cout << endl;
	cout << "Size of double type: " << sizeof(double) << endl;

	double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2};

	for (int i = 0; i < 10; i++)
	{
		cout << "Address of b[" << i << "]: " << &b[i] << endl;
	}
}

void Task1143()
{
	int a = 5;
	int& b = a;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	cout << endl;

	b = 7;

	cout << "Value of a: " << a << endl;
}

void Task1144()
{
	double a = 5.0;

	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;

	Foo(a);

	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void Task1145()
{
	double a = 5.0;

	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;

	FooWithLink(a);

	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void Task1146()
{
	int a = 5;
	int* pointer = &a;

	cout << "Address of a: " << &a << endl;
	cout << "Address in pointer: " << pointer << endl;
	cout << "Address of pointer: " << &pointer << endl;
	cout << endl;

	*pointer = 7;

	cout << "Value in a: " << a << endl;
	cout << "Value by pointer address: " << *pointer << endl;
}

void Task1147() 
{
	cout << "Если переменная создается и знак \'*\' стоит после типа переменной, "
		"то это операция объявление указателя, если \'*\' стоит перед переменной "
		"и переменная уже иницилизирована, то это операция разыименования, если \'*\' "
		"стоит перед знаком \'=\', то есть \'*=\' или между двумя переменными или числами, "
		"то это операция умножения." << endl;
}

void Task1148() 
{
	double value = 5.0;
	double* pointer = &value;

	cout << "Address of value in main(): " << &value << endl;
	cout << "Address in pointer in main(): " << pointer << endl;
	cout << "Address of pointer in main(): " << &pointer << endl;
	cout << "Value of a in main(): " << value << endl;
	cout << endl;

	FooWithPointer(pointer);

	cout << endl;
	cout << "Value of a in main(): " << value << endl;
}

void Task1151()
{
	const int arraySize = 8;

	double* arrayDouble = 
		new double[arraySize] { 1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5};

	cout << "Array of double: " << endl;

	PrintArray(arrayDouble, arraySize);

	cout << endl;

	delete[] arrayDouble;
}

void Task1152()
{
	const int arraySize = 8;

	bool* arrayBool = 
		new bool[arraySize] {true, false, false, true, false, true, true, true};

	PrintArray(arrayBool, arraySize);

	cout << endl;

	delete[] arrayBool;
}

void Task1153()
{
	int arraySize;

	cout << "Enter the length of the array: ";
	cin >> arraySize;


	char* arrayChar = new char[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		cout << "Enter a[" << i << "]: ";
		cin >> arrayChar[i];
	}

	cout << "Your char array is: " << endl;

	PrintArray(arrayChar, arraySize);

	cout << endl;

	delete[] arrayChar;
}

void Task1154()
{
	const int arraySize = 10;

	double* doubleArray =
		new double[arraySize] {1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5, 16.7, 4.5};

	cout << "Array of double: " << endl;

	PrintArray(doubleArray, arraySize);

	cout << "Sorted array of double: " << endl;

	Sort(doubleArray, arraySize);

	delete[] doubleArray;
}

void Task1155()
{
	const int arraySize = 10;

	int value;

	int* intArray = new int[arraySize] {1, 15, -8, -3, 12, 38, 0, 4, 16, 4};

	cout << "Int array: \n" << endl;
	
	PrintArray(intArray, arraySize);

	cout << "Enter searching value: ";
	cin >> value;
	cout << "Index of searching value" << value << "is: "
		<< ValueIndexInArray(intArray, arraySize, value) << endl;
	
	delete[] intArray;

}

void Task1156()
{
	const int arraySize = 15;

	char* charArray = new char[arraySize] 
	{'f', 'g', '%', '*', 'd', '@', '9', '%', ')', 'C', '<', 'd', 't', '4', '!'};

	cout << "Char array is: " << endl;

	PrintArray(charArray, arraySize);

	cout << "Letters in array:" << endl;

	PrintOnlyLetters(charArray, arraySize);

	delete[] charArray;
}

void Task1157() 
{
	int numbersArray[] = { 5, 8, 11 };

	cout << "Random array of 5: " << endl;
	PrintArray(MakeRandomArray(numbersArray[0]), numbersArray[0]);

	cout << "Random array of 8: " << endl;
	PrintArray(MakeRandomArray(numbersArray[1]), numbersArray[1]);

	cout << "Random array of 11: " << endl;
	PrintArray(MakeRandomArray(numbersArray[2]), numbersArray[2]);
}

void Task1158()
{
	int count = 15;
	int* values = ReadArray(count);

	cout << "Count is: " << CountPositiveValues(values, count) << endl;

	// Здесь была утечка.
	delete[] values;
	delete values;

	count = 20;
	values = ReadArray(count);

	cout << "Count is: " << CountPositiveValues(values, count) << endl;

	delete[] values;
	delete values;
}