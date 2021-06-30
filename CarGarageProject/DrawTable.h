#pragma once
#include <string>
#include <vector>
#include <iostream>
#include<list>
using namespace std;

namespace CarProject
{
	class DrawTable
	{
	public:
		static int tableWidth;
		static void PrintLine();
		static void PrintRow(bool newline, string* columns, int numElem);

		static string AlignCentre(string text, int width);
	};
}