// https://www.acmicpc.net/problem/10871
#include <iostream>
#include <stdlib.h>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N, X;
    int* array;
    std::cin >> N >> X;
    array = (int *)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        std::cin >> array[i];
        if (array[i] < X) {
            std::cout << array[i] << " ";
        }
    }
}