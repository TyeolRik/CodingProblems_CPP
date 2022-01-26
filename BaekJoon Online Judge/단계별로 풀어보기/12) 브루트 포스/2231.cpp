// https://www.acmicpc.net/problem/2231
#include <iostream>

int generate(int input) {
    int remain = input;
    int ret = input;
    while (remain % 10 > 0) {
        // std::cout << remain % 10;
        ret = ret + (remain % 10);
        remain = remain / 10;
    }
    return ret;
}

int main() {
    int N;
    std::cin >> N;
    for(int i = 1; i < N; i++) {
        if(N == generate(i)) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << 0;
    return 0;
}