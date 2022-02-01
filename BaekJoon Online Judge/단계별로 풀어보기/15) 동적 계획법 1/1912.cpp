// https://www.acmicpc.net/problem/1912
#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<long> seq(n);
    for(size_t index = 0; index < n; index++) {
        std::cin >> seq[index];
    }

    std::vector<long> dp(n);
    dp[0] = seq[0];
    long max = seq[0];
    for(size_t i = 1; i < seq.size(); i++) {
        dp[i] = std::max(dp[i-1]+seq[i], seq[i]);
        max = std::max(max, dp[i]);
    }
    std::cout << max;
}