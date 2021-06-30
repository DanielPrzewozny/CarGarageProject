#include <iostream>
#include <string>
#include <list>
#include "DrawTable.h"
using namespace std;

namespace CarProject
{
	int DrawTable::tableWidth = 0;
	void DrawTable::PrintLine()
	{
		char prev = cout.fill('-');
		cout.width(DrawTable::tableWidth);
		cout << '\n';
	}

	void DrawTable::PrintRow(bool newline, string *columns)
	{
		int width = (DrawTable::tableWidth - sizeof(columns)) / sizeof(columns);
		string row = "|";

		for (unsigned int a = 0; a < sizeof(columns); a = a + 1)
		{
			row += DrawTable::AlignCentre(columns[a], width);
		}

		if (newline)
		{
			cout << row << std::endl;
		}
		else
		{
			cout << row;
		}
	}

	string DrawTable::AlignCentre(string text, int width)
	{
		text = text.length() > width ? text.substr(0, width - 3) + "..." : text;

		if (text.empty())
		{
			return string(width, ' ');
		}
		else
		{
			int pad1 = width - (width - text.length()) / 2;
			int pad2 = width;
			return string(pad1, ' ') + text + string(pad2, ' ');
		}
	}
}
