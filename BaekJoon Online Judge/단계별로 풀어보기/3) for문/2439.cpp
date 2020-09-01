// https://www.acmicpc.net/problem/2439
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n;
    std::cin >> n;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for(int j = i; j < n; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}