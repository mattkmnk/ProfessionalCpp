#include <iostream>
#include "SpreadsheetCell.h"

int main() {
    SpreadsheetCell myCell, anotherCell;
    myCell.set(6);
    anotherCell.set("3.2");
    std::cout << "Cell 1: " << myCell.getValue() << '\n';
    std::cout << "Cell 2: " << anotherCell.getValue() << '\n'; 
    SpreadsheetCell cpCell = myCell + anotherCell;
    std::cout << "Cell 3: " << cpCell.getValue() << '\n';

}