#include <iostream>
#include "DynamicArray.h"
#include "Actions.h"

using namespace std;

int main()
{    
    setlocale(LC_ALL, "ru");

    DynamicArray* dynamicArray = new DynamicArray();
    int number;
    
    cout << "Выберите номер действия: ";
    cin >> number;

    while (true)
    {
        cout << "0. Завершить программу.\n1. Создать динамический массив.\n"
                "2. Добававить значение в массив.\n3. Удалить значение из массива.\n" 
                "4. Вставить элемент по индексу в массив.\n5. Сортировать массив.\n"
                "6. Линейный поиск элемента.\n7.Бинарный поиск элемента.\n"
                "8. Пересоздать массив.\n9. Вывести массив\n10. Очистить консоль."<< endl;

        cout << "Введите номер действия: ";
        cin >> number;

        switch (number)
        {
        case 0:
            return -1;
            break;
        case 1:
            //CreatDynamicArray(dynamicArray);
            break;
        /*case 2:
            AddElement(dynamicArray);
            break;
        case 3:
            RemoveElement(dynamicArray);
            break;
        case 4:
            InsertElement(dynamicArray);
            break;
        case 5:
            SortArray(dynamicArray);
            break;
        case 6:
            LinearSearchElement(dynamicArray);
            break;
        case 7:
            BinarySearchElement(dynamicArray);
            break;
        case 8:
            RecreatDynamicArray(dynamicArray);
            break;*/
        case 9:
            PrintDynamicArray(dynamicArray);
            break;
        case 10:
            system("cls");
        }
    }

}
