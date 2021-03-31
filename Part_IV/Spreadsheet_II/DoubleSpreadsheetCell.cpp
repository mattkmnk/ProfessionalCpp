#include "DoubleSpreadsheetCell.h"
#include <limits>
#include <cstdlib>

DoubleSpreadsheetCell::DoubleSpreadsheetCell()
    : mValue(std::numeric_limits<double>::quiet_NaN())
{ }

void DoubleSpreadsheetCell::set(double inDouble) {
    mValue = inDouble;
}

void DoubleSpreadsheetCell::set(const std::string& inString) {
    mValue = stringToDouble(inString);
}

std::string DoubleSpreadsheetCell::getString() const {
    return doubleToString(mValue);
}

std::string DoubleSpreadsheetCell::doubleToString(double inValue)
{
	return std::to_string(inValue);
}

double DoubleSpreadsheetCell::stringToDouble(const std::string& inString)
{
	return std::stod(inString);
}