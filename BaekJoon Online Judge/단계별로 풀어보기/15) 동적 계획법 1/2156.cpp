// https://www.acmicpc.net/problem/2156
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<unsigned long long> wines;
std::vector<unsigned long long> drinks;

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    // Initialization
    int n;
    std::cin >> n;
    wines = std::vector<unsigned long long>(n);
    for(size_t i = 0; i < n; i++) {
        std::cin >> wines[i];
    }

    if(n == 1) {
        std::cout << wines[0];
        return 0;
    } else if(n == 2) {
        std::cout << wines[0] + wines[1];
        return 0;
    }
    drinks = std::vector<unsigned long long>(n);

    drinks[0] = wines[0];
    drinks[1] = wines[0] + wines[1];
    drinks[2] = std::max(std::max(wines[0] + wines[1], wines[0] + wines[2]), wines[1] + wines[2]);
    for(size_t i = 3; i < n; i++) {
        drinks[i] = std::max(drinks[i - 2] + wines[i], drinks[i - 3] + wines[i - 1] + wines[i]);
        drinks[i] = std::max(drinks[i-1], drinks[i]);
    }
    std::cout << drinks[n - 1];
}