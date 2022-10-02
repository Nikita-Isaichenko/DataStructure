#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
    DynamicArray* array = new DynamicArray;
    int n = 0;
    CreatDynamicArray(array);

   

    while (n != -1)
    {
        cin >> n;
        Add(array, n);
        //cout << array->array[array->size - 1] << endl;
    }

    PrintArray(array);
    delete array;

    cin >> n;

    
}
