// https://www.acmicpc.net/problem/1929
#include <iostream>
#include <cmath>

int main() {
    int M, N;
    std::cin >> M >> N;
    int sieve_of_Eratosthenes[1000000] = {0,};
    for(int i = 2; i <= 1000; i++) {
        int temp = 2;
        while(temp * i < 1000000) {
            sieve_of_Eratosthenes[temp++ * i] = 1;
        }
    }
    sieve_of_Eratosthenes[1] = 1;       // 1은 소수가 아니다.
    for(int i = M; i <= N; i++) {
        if(sieve_of_Eratosthenes[i] == 0) {
            std::cout << i << "\n";
        }
    }
}