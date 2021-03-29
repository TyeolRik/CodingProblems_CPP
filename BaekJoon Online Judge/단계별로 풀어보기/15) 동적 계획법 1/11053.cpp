// https://www.acmicpc.net/problem/11053
// Time Complexity : O(N^2)

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for(size_t i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> dp(N);
    dp[0] = 1;
    for(size_t i = 1; i < N; i++) {
        int now = 0;
        for(size_t j = 0; j < i; j++) {
            if(A[j] < A[i]) {
                now = std::max(now, dp[j]);
            }
        }
        dp[i] = now + 1;
    }
    std::cout << *std::max_element(dp.begin(), dp.end());
}