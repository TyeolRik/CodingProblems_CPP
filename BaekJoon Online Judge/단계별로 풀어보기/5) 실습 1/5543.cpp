// https://www.acmicpc.net/problem/5543
#include <iostream>

int min(int* arr, int size) {
    int min = arr[0];
    for(int i = 0; i < size; i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int burger[3];
    int soda[2];
    for(int i = 0; i < 3; i++) {
        std::cin >> burger[i];
    }
    for(int i = 0; i < 2; i++) {
        std::cin >> soda[i];
    }
    std::cout << min(burger, 3) + min(soda, 2) - 50;
}