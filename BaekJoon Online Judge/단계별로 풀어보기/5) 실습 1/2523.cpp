// https://www.acmicpc.net/problem/2523
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    std::cin >> N;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    while(N --> 0) {
        for(int i = N + 1; i > 0; i--) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}