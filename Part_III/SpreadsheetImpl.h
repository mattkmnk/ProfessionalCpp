#pragma once

#include "SpreadsheetCell.h"

class SpreadsheetApplication;
class SpreadsheetImpl {
public:
    SpreadsheetImpl(const SpreadsheetApplication& theApp, int inWidth, int inHeight);
    SpreadsheetImpl(const SpreadsheetImpl& src);
    ~SpreadsheetImpl();
    SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs);
    void setCellAt(int x, int y, const SpreadsheetCell& cell);
    SpreadsheetCell& getCellAt(int x, int y);
    int getId() const;

    static const int kMaxWidth = 100;
    static const int kMaxHeight = 100;

private:
    bool inRange(int val, int upper);
    void copyFrom(const SpreadsheetImpl& src);
    int mWidth, mHeight;
    SpreadsheetCell** mCells;
    int mId;
    static int sCounter;
    const SpreadsheetApplication& mTheApp;
};