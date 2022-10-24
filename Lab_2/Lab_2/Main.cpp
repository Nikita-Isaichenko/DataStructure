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
        cout << "������� ����� ��������: ";
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
            cout << "������������ ����� ��������!";
        }
        cout << "                                           |" << endl;
        cout << "--------------------------------------------\n" << endl;
    }
}

void PrintText()
{
    cout << "0. ��������� ���������.\n1. �������� �������.\n"
        "2. �������� �������� � ������.\n3. ������� �������� �� �������.\n"
        "4. �������� ������� � ������.\n5. �������� ������� ����� �������.\n"
        "6. �������� ����� ��������.\n7.�������� ����� ��������.\n"
        "8. ����������� ������.\n9. ������� ������\n" << endl;
    cout << endl;
}

   