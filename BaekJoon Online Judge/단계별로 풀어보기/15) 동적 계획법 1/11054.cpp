// https://www.acmicpc.net/problem/11054
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 전략
 * 만약, A0, ..., Ak ..., An 까지의 수열 중
 * 임의로 선택된 Ak가 바이토닉 수열에서 가장 큰 숫자를 차지한다고 가정하자.
 */

int main() {
    std::ios::sync_with_stdio(false);

    unsigned int N;
    std::cin >> N;
    std::vector<unsigned int> A(N);
    std::vector<unsigned int> dp(N);
    std::vector<unsigned int> upDP(N);
    std::vector<unsigned int> downDP(N);

    for(auto i = 0; i < N; i++) {
        std::cin >> A[i];
    };
    
    upDP[0] = 1;
    for(auto i = 1; i < N; i++) {
        unsigned int now = 0;
        for(auto j = 0; j < i; j++) {
            if(A[j] < A[i]) {
                now = std::max(now, upDP[j]);
            }
        }
        upDP[i] = now + 1;
    }
    
    downDP[N-1] = 1;
    for(int i = N-1; i >= 0; i--) {
        unsigned int now = 0;
        for(int j = N-1; j >= i; j--) {
            if(A[j] < A[i]) {
                now = std::max(now, downDP[j]);
            }
        }
        downDP[i] = now + 1;
    }

    for(auto i = 0; i < N; i++) {
        dp[i] = upDP[i] + downDP[i] - 1;    // -1 하는 이유는 중복되는 가운데 원소 하나를 빼기 때문.
    }
    std::cout << *std::max_element(dp.begin(), dp.end());

}