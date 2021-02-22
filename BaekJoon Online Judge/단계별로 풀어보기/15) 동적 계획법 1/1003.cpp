// https://www.acmicpc.net/problem/1003
#include <iostream>
#include <vector>

std::vector<int> fibo(41);

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < 41; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int T, N;
    std::cin >> T;

    for(int i = 0; i < T; i++) {
        std::cin >> N;
        if(N == 0) {
            std::cout << 1 << ' ' << 0 << '\n';
        } else if(N == 1) {
            std::cout << 0 << ' ' << 1 << '\n';
        } else {
            std::cout << fibo[N-1] << ' ' << fibo[N] << '\n';
        }
    }
}