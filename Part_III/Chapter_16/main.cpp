#include "RoundRobin.h"

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main() {

    RoundRobin<int> scheduler(1);

    return 0;
}

void whatever() {
vector<double> doubleVector(10);
    double max = -numeric_limits<double>::infinity();
    for(size_t i = 0; i < doubleVector.size(); i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> doubleVector[i];
        if(doubleVector[i] > max) {
            max = doubleVector.at(i);
        }
    }

    max /= 100.0;
    for(auto iter = begin(doubleVector); iter != end(doubleVector); ++iter) {
        *iter /= max;
        cout << *iter << ' ';
    }
}