#include <iostream>
#include "Grid.h"


int main() {
    Grid<int> myIntGrid;
    myIntGrid.setElementAt(1, 1, 50);
    std::cout << myIntGrid.getElementAt(1, 1);   
}