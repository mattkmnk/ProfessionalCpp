#include <stdexcept>
#include "SpreadsheetImpl.h"
#include <memory>

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetApplication& theApp, int inWidth, int inHeight) :
    mWidth(inWidth > kMaxWidth ? kMaxWidth : inWidth),
    mHeight(inHeight > kMaxHeight ? kMaxHeight : inHeight),
    mTheApp(theApp) {
        mId = sCounter++;

        mCells = new SpreadsheetCell* [mWidth];
        for (int i = 0; i < mWidth; i++) {
            mCells[i] = new SpreadsheetCell [mHeight];
        }
    }

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetImpl& src) :
    mTheApp(src.mTheApp) {
    mId = sCounter++;
    copyFrom(src);
}

SpreadsheetImpl::~SpreadsheetImpl() {
    for (int i = 0; i < mWidth; i++) {
        delete [] mCells[i];
    }
    delete [] mCells;
    mCells = nullptr;
}

SpreadsheetImpl& SpreadsheetImpl::operator=(const SpreadsheetImpl& rhs) {
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

void SpreadsheetImpl::copyFrom(const SpreadsheetImpl& src) {
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

void SpreadsheetImpl::setCellAt(int x, int y, const SpreadsheetCell& cell) {
    if(!inRange(x, mWidth) || !inRange(y, mHeight)) {
        throw std::out_of_range("");
    }
    mCells[x][y] = cell;
}

SpreadsheetCell& SpreadsheetImpl::getCellAt(int x, int y) {
    if(!inRange(x, mWidth) || !inRange(y, mHeight)) {
        throw std::out_of_range("");
    }
    return mCells[x][y];
}

bool SpreadsheetImpl::inRange(int val, int upper) {
    return val < upper;
}

int SpreadsheetImpl::getId() const {
    return mId;
}

int SpreadsheetImpl::sCounter;