// https://www.acmicpc.net/problem/2446
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n;
    std::cin >> n;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for(int k = n - 1; k > i; k--) {
            std::cout << "*";
        }
        std::cout << "*";
        for(int k = n - 1; k > i; k--) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for(int k = n - 1; k > i; k--) {
            std::cout << "*";
        }
        std::cout << "*";
        for(int k = n - 1; k > i; k--) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    for(int i = 0; i < 2*n - 1; i++) {
        std::cout << "*";
    }
}