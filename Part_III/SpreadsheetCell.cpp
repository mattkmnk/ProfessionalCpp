#include "SpreadsheetCell.h"
#include <iostream>
#include <sstream>

SpreadsheetCell::SpreadsheetCell() : mValue(0) 
{   
}

SpreadsheetCell::SpreadsheetCell(double initialValue) {
    set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const std::string& initialValue) {
    set(initialValue);
}

void SpreadsheetCell::set(double inValue) {
    mValue = inValue;
    mString = doubleToString(mValue);
}

double SpreadsheetCell::getValue() const {
    mNumAccesses++;
    return mValue;
}

void SpreadsheetCell::set(const std::string& inString) {
    mNumAccesses++;
    mString = inString;
    mValue = stringToDouble(mString);
}

const std::string& SpreadsheetCell::getString() const {
    return mString;
}

std::string SpreadsheetCell::doubleToString(double inValue) {
    std::ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string& inString) {
    double temp;
    std::istringstream istr(inString);
    istr >> temp;
    if(istr.fail() || !istr.eof()) {
        return 0;
    }
    return temp;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs) {
    if(this == &rhs) return *this;
    mValue = rhs.mValue;
    mString = rhs.mString;
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const {
    SpreadsheetCell newCell;
    newCell.set(getValue() + cell.getValue());
    return newCell;
}

void SpreadsheetCell::setColor(Colors color) {
    mColor = color;
}