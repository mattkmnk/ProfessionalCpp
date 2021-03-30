#include "SpreadsheetCell.h"

class Spreadsheet {
public:
    Spreadsheet(int inWidth, int inHeight);
    Spreadsheet(const Spreadsheet& src);
    ~Spreadsheet();
    Spreadsheet& operator=(const Spreadsheet& rhs);
    void setCellAt(int x, int y, const SpreadsheetCell& cell);
    SpreadsheetCell& getCellAt(int x, int y);
    int getId() const;

private:
    bool inRange(int val, int upper);
    void copyFrom(const Spreadsheet& src);
    int mWidth, mHeight;
    SpreadsheetCell** mCells;
    int mId;
    static int sCounter;
};