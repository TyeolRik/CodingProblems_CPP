// https://www.acmicpc.net/problem/2156
// Using Combinations
// 시간 초과
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<unsigned long long> wines;

unsigned long long max = 0;

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
    std::vector<bool> comb(n, 1);
    for(size_t idx = n - 1; idx >= (n - 1) - 2; idx--) {
        comb[idx] = 0;
        do {
            bool isPossible = true;
            // 만약, 3개 연속 1이면 continue;
            for(size_t i = 0; i < n - 2; i++) {
                if(comb[i] && comb[i + 1] && comb[i + 2]) {
                    isPossible = false;
                }
            }
            if(isPossible) {
                unsigned long long sum = 0;
                for(size_t i = 0; i < n; i++) {
                    if(comb[i]) {
                        sum = sum + wines[i];
                    }
                }
                if(sum > max) {
                    max = sum;
                }
            }
        } while(std::next_permutation(comb.begin(), comb.end()));
    }

    std::cout << max;
    
}