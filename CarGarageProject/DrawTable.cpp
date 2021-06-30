#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
#include "DrawTable.h"
using namespace std;

namespace CarProject {
int DrawTable::tableWidth;
void DrawTable::PrintLine() {
  cout << string(DrawTable::tableWidth, '-') << "\n";
}

void DrawTable::PrintRow(bool newline, string *columns, int numElem) {

  int width = (DrawTable::tableWidth - numElem) / numElem;
  string row = "|";

  for (unsigned int a = 0; a < numElem; a = a + 1) {
    row.append(DrawTable::AlignCentre(columns[a], width) + "|");
  }

  if (newline) {
    cout << row << endl;
  } else {
    cout << row;
  }
}

string DrawTable::AlignCentre(string text, int width) {
    text = text.length() > width ? text.substr(0, width - 3) + "..." : text;
    int len = text.length();
    if (width < len) { return text; }

    int diff = width - len;
    int pad1 = diff / 2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + text + string(pad2, ' ');
}
}
