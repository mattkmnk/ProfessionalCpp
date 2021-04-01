#include <iostream>
#include "Spreadsheet.h"


using namespace std;

class SpreadsheetApplication {};

int main()
{
	SpreadsheetApplication theApp;
	Spreadsheet s1(theApp, 5, 6);
	SpreadsheetCell myCell(5);
	s1.setCellAt(1, 1, myCell);

	s1.getCellAt(1, 1).set("7");
	std::cout << s1.getCellAt(1, 1).getValue();

	return 0;
}
