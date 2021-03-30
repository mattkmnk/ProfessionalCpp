#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int inWidth, int inHeight) :
    mWidth(inWidth), mHeight(inHeight) {
        mCells = new SpreadsheetCell* [mWidth];
        for (int i = 0; i < mWidth; i++) {
            mCells[i] = new SpreadsheetCell [mHeight];
        }
    }

Spreadsheet::Spreadsheet(const Spreadsheet& src) {
    copyFrom(src);
}

Spreadsheet::~Spreadsheet() {
    for (int i = 0; i < mWidth; i++) {
        delete [] mCells[i];
    }
    delete [] mCells;
    mCells = nullptr;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
    if(this == &rhs) {
        return *this;
    }

    for (int i = 0; i < mWidth; i++) {
        delete [] mCells[i];
    }
    delete [] mCells;
    mCells = nullptr;

    copyFrom(rhs);

    return *this;
}

void Spreadsheet::copyFrom(const Spreadsheet& src) {
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    mCells = new SpreadsheetCell* [mWidth];
    for(int i = 0; i < mWidth; i++) {
        mCells[i] = new SpreadsheetCell[mHeight];
    }
    for(int i = 0; i < mWidth; i++) {
        for(int j = 0; j < mHeight; j++) {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell) {
    if(!inRange(x, mWidth) || !inRange(y, mHeight)) {
        throw std::out_of_range("");
    }
    mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(int x, int y) {
    if(!inRange(x, mWidth) || !inRange(y, mHeight)) {
        throw std::out_of_range("");
    }
    return mCells[x][y];
}

bool inRange(int val, int upper) {
    return val < upper;
}