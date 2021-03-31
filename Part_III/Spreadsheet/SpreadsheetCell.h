#pragma once

#include <string>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string initialValue);

	void set(double inValue);
	void set(std::string inString);

	double getValue() const { mNumAccesses++; return mValue; }
	std::string getString() const { mNumAccesses++; return doubleToString(mValue); }

	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string inString);

	friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	friend bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

private:
	double mValue = 0;
	mutable size_t mNumAccesses = 0;
};
