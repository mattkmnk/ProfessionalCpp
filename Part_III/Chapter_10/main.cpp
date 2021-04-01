#include <iostream>


void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << x << '\t' << y << '\n';
    swap(x, y);
    std::cout << x << '\t' << y << '\n';

}