#include <iostream>
#include "DoubleLinkedList.h"
#include "Actions.h"

using namespace std;


void PrintText();

int main()
{
	setlocale(LC_ALL, "");

    int number;
	List* list = new List();

    InitList(list);
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

            return 0;
        case 1:
            system("cls");
            PrintText();
            break;
        case 2:
            AddElement(list);
            break;
        case 3:
            RemoveElement(list);
            break;
        case 4:
            InsertElementInBegin(list);
            break;
        case 5:
            InsertElementAfter(list);
            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:
            Show(list);
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
        "4. Вставить элемент в начало.\n5. Вставить элемент после индекса.\n"
        "6. Линейный поиск элемента.\n7.Бинарный поиск элемента.\n"
        "8. Пересоздать массив.\n9. Вывести массив\n" << endl;
    cout << endl;
}

   