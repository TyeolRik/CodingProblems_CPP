// https://www.acmicpc.net/problem/2562
#include <iostream>

int main() {
    int n = 9;
    int arr[9];
    int max, ret;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if(i == 0) {
            max = arr[i];
            ret = i;
        }
        if(max < arr[i]) {
            max = arr[i];
            ret = i;
        }
    }
    std::cout << max << "\n";
    std::cout << ret + 1 << "\n";
}