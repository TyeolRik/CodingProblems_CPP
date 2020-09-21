// https://www.acmicpc.net/problem/2750
#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    int* data = new int[N];
    for(int i = 0; i < N; i++) {
        std::cin >> data[i];
    }
    std::sort(data, data + N);
    for(int i = 0; i < N; i++) {
        std::cout << data[i] << "\n";
    }
}