#include <iostream>
#include "DoubleLinkedList.h"
#include "IODoubleLinkedList.h"
#include "Validation.h"
#include "Tests.h"

using namespace std;


void PrintText();


int main()
{
	setlocale(LC_ALL, "");

	DoubleLinkedList* list = new DoubleLinkedList();

    InitList(list);
    PrintText();

    while (true)
    {
        cout << "\n--------------------------------------------" << endl;
        cout << "                                           |" << endl;

        int number = CheckingForDigit("������� ����� ��������: ");

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
            InsertElementBefore(list);
            break;
        case 7:
            SortList(list);
            break;
        case 8:
            LinearSearchElement(list);
            break;
        case 9:
            Show(list);
            break;
        case 10:
            RemoveList(list);
            Show(list);
            break;
        case 11:
            TestOperations();
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
        "6. �������� ������� ����� ��������.\n7. ����������.\n"
        "8. ����� ��������.\n9. ������� ������\n10. �������� ������\n"
        "11. �������� ���� ��� �������� ������� � ��������."<< endl;
    cout << endl;
}   