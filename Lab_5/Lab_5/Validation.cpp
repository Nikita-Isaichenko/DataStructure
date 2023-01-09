#include "Validation.h"
#include <iostream>
#include <string>

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
			cout << "Ïðîèçîøëà îøèáêà. Ïîïðîáóéòå ñíîâà" << endl;
			continue;
		}

		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			cout << "Ïðîèçîøëà îøèáêà. Ïîïðîáóéòå ñíîâà" << endl;
			continue;
		}

		break;
	}

	return value;
}