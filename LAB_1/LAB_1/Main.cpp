#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{    
    setlocale(LC_ALL, "ru");

    DynamicArray* array = new DynamicArray;
    int n = 0;
     
    CreatDynamicArray(array);    
    
    //while (n != -1)
    //{
    //    cin >> n;
    //    Add(array, n);
    //    
    //    //cout << array->array[array->size - 1] << endl;
    //}
    InitRandomValues(array, 7);

    PrintArray(array);    
    RemoveAt(array, -1);
    PrintArray(array);
    Insert(array, 11, 0);
    PrintArray(array);
    Insert(array, 11, 3);
    PrintArray(array);
    Insert(array, 11, 5);
    PrintArray(array);
    Sort(array);
    PrintArray(array);
    cout << BinarySearch(array, 1) << endl;
    cout << LinearSearch(array, 1) << endl;

    delete[] array->array;
    delete array;

    cin >> n;   
}
