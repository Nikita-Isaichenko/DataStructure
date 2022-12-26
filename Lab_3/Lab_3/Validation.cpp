#include "Validation.h"
#include <iostream>

using namespace std;

int CheckingForDigit(const char* text)
{
	if (text != "")
	{
		cout << text << endl;
	}


	int value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "Произошла ошибка. Попробуйте снова" << endl;
			continue;
		}

		break;
	}

	return value;
}