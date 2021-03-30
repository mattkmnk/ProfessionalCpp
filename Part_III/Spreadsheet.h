#include "SpreadsheetCell.h"

class SpreadsheetApplication;
class Spreadsheet {
public:
    Spreadsheet(const SpreadsheetApplication& theApp, int inWidth, int inHeight);
    Spreadsheet(const Spreadsheet& src);
    ~Spreadsheet();
    Spreadsheet& operator=(const Spreadsheet& rhs);
    void setCellAt(int x, int y, const SpreadsheetCell& cell);
    SpreadsheetCell& getCellAt(int x, int y);
    int getId() const;

    static const int kMaxWidth = 100;
    static const int kMaxHeight = 100;

private:
    bool inRange(int val, int upper);
    void copyFrom(const Spreadsheet& src);
    int mWidth, mHeight;
    SpreadsheetCell** mCells;
    int mId;
    static int sCounter;
    const SpreadsheetApplication& mTheApp;
};