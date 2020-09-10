// https://www.acmicpc.net/problem/9020
#include <iostream>

int main() {
    int T, n;
    int sieve_of_Eratosthenes[10000] = {0, };
    sieve_of_Eratosthenes[0] = 1;
    sieve_of_Eratosthenes[1] = 1;       // 1은 소수가 아니다.
    for(int i = 2; i < 100; i++) {
        int temp = 2;
        while(temp * i < 10000) {
            sieve_of_Eratosthenes[(temp++) * i] = 1;
        }
    }

    std::cin >> T;
    while(T --> 0) {
        std::cin >> n;
        int small = 0;
        int large = 0;
        int difference = 10000;
        for(int i = 3; i < n; i++) {
            if(sieve_of_Eratosthenes[i] != 0) {
                continue;
            }
            for(int j = i; j < n; j++) {
                if(sieve_of_Eratosthenes[j] != 0) {
                    continue;
                }
                if(i + j == n) {
                    if (difference > (j - i)) {
                        small = i;
                        large = j;
                        difference = j - i;
                    }
                    if(difference == 0) {
                        goto loop_breaker;
                    }
                }
            }
        }
        loop_breaker:;
        std::cout << small << " " << large << "\n";
    }
}