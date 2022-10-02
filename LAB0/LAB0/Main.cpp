#include <iostream>
#include "Tasks.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int taskNumber = 0;

	while (true)
	{
		cout << "0 - Exit for program\n1 - Task 1.1.1.1\n2 - Task 1.1.1.2\n3 - Task 1.1.2.1\n"
				"4 - Task 1.1.2.2\n5 - Task 1.1.2.3\n6 - Task 1.1.3.1\n"
				"7 - Task 1.1.3.2\n8 - Task 1.1.3.3\n9 - Task 1.1.3.4\n"
				"10 - Task 1.1.4.1\n11 - Task 1.1.4.2\n12 - Task 1.1.4.3\n"
				"13 - Task 1.1.4.4\n14 - Task 1.1.4.5\n15 - Task 1.1.4.6\n"
				"16 - Task 1.1.4.7\n17 - Task 1.1.4.8\n18 - Task 1.1.5.1\n"
				"19 - Task 1.1.5.2\n20 - Task 1.1.5.3\n21 - Task 1.1.5.4\n"
				"22 - Task 1.1.5.5\n23 - Task 1.1.5.6\n24 - Task 1.1.5.7\n"
				"25 - Task 1.1.5.8\n" << endl;
		cout << "\nEnter the task number: ";
		cin >> taskNumber;
		cout << "\n--------------------------------------------" << endl;

		switch (taskNumber)
		{
			case 0:
				return -1;
				break;
			case 1:
				Task1111();
				break;
			case 2:
				Task1112();
				break;
			case 3:
				Task1121();
				break;
			case 4:
				Task1122();
				break;
			case 5:
				Task1123();
				break;
			case 6:
				Task1131();
				break;
			case 7:
				Task1132();
				break;
			case 8:
				Task1133();
				break;
			case 9:
				Task1134();
				break;
			case 10:
				Task1141();
				break;
			case 11:
				Task1142();
				break;
			case 12:
				Task1143();
				break;
			case 13:
				Task1144();
				break;
			case 14:
				Task1145();
				break;
			case 15:
				Task1146();
				break;
			case 16:
				Task1147();
				break;
			case 17:
				Task1148();
				break;
			case 18:
				Task1151();
				break;
			case 19:
				Task1152();
				break;
			case 20:
				Task1153();
				break;
			case 21:
				Task1154();
				break;
			case 22:
				Task1155();
				break;
			case 23:
				Task1156();
				break;
			case 24:
				Task1157();
				break;
			case 25:
				Task1158();
				break;
			default:
				cout << "There is no such task" << endl;
				break;
		}
		cout << "--------------------------------------------\n" << endl;
	}
}