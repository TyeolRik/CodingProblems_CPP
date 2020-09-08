// https://www.acmicpc.net/problem/2775
#include <iostream>

int how_many(int k, int n) {
    if(k == 0) {
        return n;
    } else {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum = sum + how_many(k-1, i);
        }
        return sum;
    }
}

int main() {
    int T, k, n;
    std::cin >> T;
    while(T --> 0) {
        std::cin >> k >> n;
        std::cout << how_many(k, n) << "\n";
    }
}