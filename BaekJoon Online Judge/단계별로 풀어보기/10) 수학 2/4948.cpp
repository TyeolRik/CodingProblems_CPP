// https://www.acmicpc.net/problem/4948
#include <iostream>
#include <cmath>

int main() {
    int sieve[300000] = {0, };
    for(int i = 2; i <= (int)sqrt(300000); i++) {
        int temp = 2;
        while(temp * i < 300000) {
            sieve[temp++ * i] = 1;
        }
    }
    sieve[1] = 1;           // 1은 소수가 아니다.

    while(true) {
        int n;
        int count = 0;
        std::cin >> n;
        if(n == 0) {
            break;
        }
        for(int i = n + 1; i <= 2*n; i++) {
            if(sieve[i] == 0) {
                count++;
            }
        }
        std::cout << count << "\n";
    }
}