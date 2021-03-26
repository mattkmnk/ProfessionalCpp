#include <iostream>

void sort(int arr[5], int size) {
    for(int i = 1; i < size; i++) {
        int element = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > element) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }
}

int main(){

    int array[] = {5, 4, 3, 2, 1};
    for(auto x : array) {
        std::cout << x << '\n';
    }
    sort(array, 5);
    for(auto x : array) {
        std::cout << x << '\n';
    }
    return 0;
}