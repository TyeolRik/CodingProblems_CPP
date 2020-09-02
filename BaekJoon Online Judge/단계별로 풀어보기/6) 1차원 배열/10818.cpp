// https://www.acmicpc.net/problem/10818
#include <iostream>
#include <stdlib.h>

int min(int *arr, int size) {
    int ret = arr[0];
    while(size --> 0) {
        if (ret > arr[size]) {
            ret = arr[size];
        }
    }
    return ret;
}

int max(int *arr, int size) {
    int ret = arr[0];
    while(size --> 0) {
        if (ret < arr[size]) {
            ret = arr[size];
        }
    }
    return ret;
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n;
    int *arr;
    std::cin >> n;
    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cout << min(arr, n) << " " << max(arr, n);
}