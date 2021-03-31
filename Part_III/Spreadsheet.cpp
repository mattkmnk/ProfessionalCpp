#include "Spreadsheet.h"
#include "SpreadsheetImpl.h"

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& inCell)
{
	mImpl->setCellAt(x, y, inCell);
}

SpreadsheetCell& Spreadsheet::getCellAt(int x, int y)
{
	return mImpl->getCellAt(x, y);
}

int Spreadsheet::getId() const
{
	return mImpl->getId();
}

Spreadsheet::Spreadsheet(const SpreadsheetApplication &theApp, int inWidth, int inHeight)
{
	mImpl = std::make_shared<SpreadsheetImpl>(theApp, inWidth, inHeight);
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
{
	mImpl = std::make_shared<SpreadsheetImpl>(*src.mImpl);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	*mImpl = *rhs.mImpl;
	return *this;
}
