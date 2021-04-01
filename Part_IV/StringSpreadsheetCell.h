#pragma once

#include "SpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"

class StringSpreadsheetCell : public SpreadsheetCell {
public:
    StringSpreadsheetCell();
    StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell);

    virtual void set(const std::string& inString) override;
    virtual std::string getString() const override;

    friend StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
                                           const StringSpreadsheetCell& rhs);

private:
    std::string mValue;
};