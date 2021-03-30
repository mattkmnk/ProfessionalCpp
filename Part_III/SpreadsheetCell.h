#pragma once
#include <string>

class SpreadsheetCell {
public:
    friend class Spreadsheet;
    SpreadsheetCell();
    SpreadsheetCell(double initialValue);
    explicit SpreadsheetCell(const std::string& initialValue);
    void set(double inValue);
    double getValue() const;
    void set(const std::string& inString);
    const std::string& getString() const;

    SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
    
    friend SpreadsheetCell operator+(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend SpreadsheetCell operator-(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend SpreadsheetCell operator*(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend SpreadsheetCell operator/(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);

    SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
    SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
    SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
    SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

    friend bool operator==(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend bool operator<(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend bool operator>(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend bool operator!=(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend bool operator<=(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    friend bool operator>=(const SpreadsheetCell& lhs,
        const SpreadsheetCell& rhs);
    enum class Colors {Red = 1, Green, Blue, Yellow};
    void setColor(Colors color);

private:
    static std::string doubleToString(double inValue);
    static double stringToDouble(const std::string& inString);
    double mValue;
    std::string mString;
    mutable int mNumAccesses = 0;
    Colors mColor = Colors::Red;
};
