#include "StringSpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"

#include <iostream>
#include <cstdlib>

StringSpreadsheetCell::StringSpreadsheetCell() : mValue("#NOVALUE")
{ }

StringSpreadsheetCell::StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell) {
    mValue = inDoubleCell.getString();
}

void StringSpreadsheetCell::set(const std::string& inString) {
    mValue = inString;
}

std::string StringSpreadsheetCell::getString() const {
    return mValue;
}

StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
                                const StringSpreadsheetCell& rhs) {
    StringSpreadsheetCell newCell;
    double result = std::stod(lhs.getString()) + std::stod(rhs.getString());
    newCell.set(std::to_string(result));
    return newCell;
}