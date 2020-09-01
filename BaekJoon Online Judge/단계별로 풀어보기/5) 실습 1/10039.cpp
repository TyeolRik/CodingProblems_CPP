// https://www.acmicpc.net/problem/10039
#include <iostream>

int main() {
    int avg;
    int arr[5];
    for(int i = 0; i < 5; i++) {
        std::cin >> arr[i];
        if (arr[i] < 40) {
            arr[i] = 40;
        }
    }
    for(int i = 0; i < 5; i++) {
        avg = avg + arr[i];
    }
    std::cout << avg / 5;
}