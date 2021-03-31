#include "SpreadsheetCell.h"

class StringSpreadsheetCell : public SpreadsheetCell {
public:
    StringSpreadsheetCell();

    virtual void set(const std::string& inString) override;
    virtual std::string getString() const override;

private:
    std::string mValue;
};