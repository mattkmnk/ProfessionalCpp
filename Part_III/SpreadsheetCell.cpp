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

void SpreadsheetCell::setColor(Colors color) {
    mColor = color;
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    SpreadsheetCell newCell;
    newCell.set(lhs.getValue() + rhs.getValue());
    return newCell;
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    SpreadsheetCell newCell;
    newCell.set(lhs.getValue() - rhs.getValue());
    return newCell;
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    SpreadsheetCell newCell;
    newCell.set(lhs.getValue() * rhs.getValue());
    return newCell;
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    if(rhs.mValue == 0)
        throw std::invalid_argument("Divide by zero.");
    SpreadsheetCell newCell;
    newCell.set(lhs.getValue() / rhs.getValue());
    return newCell;
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs) {
    set(mValue + rhs.mValue);
    return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs) {
    set(mValue - rhs.mValue);
    return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs) {
    set(mValue * rhs.mValue);
    return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs) {
    if(rhs.mValue == 0)
        throw std::invalid_argument("Divide by zero.");
    set(mValue / rhs.mValue);
    return *this;
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
 return (lhs.mValue == rhs.mValue);
}
bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
 return (lhs.mValue < rhs.mValue);
}
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
 return (lhs.mValue > rhs.mValue);
}
bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
 return (lhs.mValue != rhs.mValue);
}
bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
 return (lhs.mValue <= rhs.mValue);
}
bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
 return (lhs.mValue >= rhs.mValue);
}