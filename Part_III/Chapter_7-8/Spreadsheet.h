#pragma once

#include "SpreadsheetCell.h"
#include <memory>

// forward declarations
class SpreadsheetImpl;
class SpreadsheetApplication;

class Spreadsheet
{
public:
	Spreadsheet(const SpreadsheetApplication& theApp,
		int inWidth = kMaxWidth, int inHeight = kMaxHeight);
	Spreadsheet(const Spreadsheet& src);

	Spreadsheet& operator=(const Spreadsheet& rhs);
	
	void setCellAt(int x, int y, const SpreadsheetCell& inCell);
	SpreadsheetCell& getCellAt(int x, int y);
	
	int getId() const;

	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;

private:
	std::shared_ptr<SpreadsheetImpl> mImpl;
};
