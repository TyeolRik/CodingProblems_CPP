// https://www.acmicpc.net/problem/2741
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cout << i + 1 << "\n";
    }
}