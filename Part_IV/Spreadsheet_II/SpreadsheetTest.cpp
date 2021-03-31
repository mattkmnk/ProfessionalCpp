#include "DoubleSpreadsheetCell.h"
#include "StringSpreadsheetCell.h"

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

int main() {
    vector<unique_ptr<SpreadsheetCell>> cellArray;

    cellArray.push_back(make_unique<StringSpreadsheetCell>());
    cellArray.push_back(make_unique<StringSpreadsheetCell>());
    cellArray.push_back(make_unique<DoubleSpreadsheetCell>());

    cellArray[0]->set("Hello");
    cellArray[1]->set("10");
    cellArray[2]->set("18");

    cout << "Vector values are [" << cellArray[0]->getString() << ", " <<
                                     cellArray[1]->getString() << ", " <<
                                     cellArray[2]->getString() << "]\n";

    return 0;
}