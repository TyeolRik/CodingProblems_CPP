// https://www.acmicpc.net/problem/2438
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i+1; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}