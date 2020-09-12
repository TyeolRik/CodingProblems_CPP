// https://www.acmicpc.net/problem/9020
#include <iostream>

int main() {
    int T, n;

    // 에라토스테네스의 체 초기화
    int sieve_of_Eratosthenes[10000] = {0, };
    sieve_of_Eratosthenes[0] = 1;
    sieve_of_Eratosthenes[1] = 1;       // 1은 소수가 아니다.
    for(int i = 2; i < 100; i++) {
        int temp = 2;
        while(temp * i < 10000) {
            // 0이면 소수, 1이면 소수가 아니다.
            sieve_of_Eratosthenes[(temp++) * i] = 1;
        }
    }

    std::cin >> T;
    while(T --> 0) {
        std::cin >> n;
        for(int i = (n / 2); i >= 2; i--) {
            if(sieve_of_Eratosthenes[i] != 0) {
                // 소수가 아니면 넘어가기 :: 값이 0이어야 소수임
                continue;
            }
            // n = i + j 에서 정답이 되는 j = n - i 이므로,
            if(sieve_of_Eratosthenes[n - i] == 0) {
                std::cout << i << " " << n - i << "\n";
                break;
            }
        }
    }
}