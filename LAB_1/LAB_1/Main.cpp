#include <iostream>
#include "DynamicArray.h"
#include "Actions.h"

void PrintText();

using namespace std;

int main()
{    
    setlocale(LC_ALL, "ru");

    DynamicArray* array = new DynamicArray;
    int number;

    CreatDynamicArray(array);
    PrintText();

    while (true)
    {    
        cout << "\n--------------------------------------------" << endl;
        cout << "                                           |" << endl;
        cout << "Введите номер действия: ";
        cin >> number;

        switch (number)
        {
        case 0:
            delete[] array->array;
            delete array;
            return -1;
            break;
        case 1:
            system("cls");
            PrintText();
            break;
        case 2:
            AddElement(array);
            break;
        case 3:
            RemoveElement(array);           
            break;
        case 4:
            InsertElement(array);          
            break;
        case 5:
            SortArray(array);
            break;
        case 6:
            LinearSearchElement(array);
            break;
        case 7:
            BinarySearchElement(array);
            break;
        case 8:
            RecreatDynamicArray(array);
            break;
        case 9:
            PrintArray(array);
            break;
        default:
            cout << "Некорректный номер действия!";
        }
        cout << "                                           |" << endl;
        cout << "--------------------------------------------\n" << endl;
    }
}

void PrintText()
{
    cout << "0. Завершить программу.\n1. Очистить консоль.\n"
        "2. Добавить значение в массив.\n3. Удалить значение из массива.\n"
        "4. Вставить элемент по индексу в массив.\n5. Сортировать массив.\n"
        "6. Линейный поиск элемента.\n7.Бинарный поиск элемента.\n"
        "8. Пересоздать массив.\n9. Вывести массив\n" << endl;
    cout << endl;
}