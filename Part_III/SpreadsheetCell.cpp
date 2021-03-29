#include "SpreadsheetCell.h"
#include <iostream>
#include <sstream>

SpreadsheetCell::SpreadsheetCell() : mValue(0) 
{   
}

SpreadsheetCell::SpreadsheetCell(double initialValue) {
    setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const std::string& initialValue) {
    setString(initialValue);
}

void SpreadsheetCell::setValue(double inValue) {
    mValue = inValue;
    mString = doubleToString(mValue);
}

double SpreadsheetCell::getValue() const {
    return mValue;
}

void SpreadsheetCell::setString(const std::string& inString) {
    mString = inString;
    mValue = stringToDouble(mString);
}

const std::string& SpreadsheetCell::getString() const {
    return mString;
}

std::string SpreadsheetCell::doubleToString(double inValue) const{
    std::ostringstream ostr;
    ostr << inValue;
    return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string& inString) const {
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