// https://www.acmicpc.net/problem/1904
#include <iostream>
#include <vector>

unsigned long long calc(int input) {
    unsigned long long a = 1;
    unsigned long long b = 2;
    unsigned long long ret;

    for(int i = 2; i < input; i++) {
        ret = (a + b) % 15746;
        a = b;
        b = ret;
    }
    return ret;
}

int main() {
    int N;
    std::cin >> N;
    
    switch (N)
    {
    case 1:
        std::cout << 1;
        break;
    
    case 2:
        std::cout << 2;
        break;
    
    case 3:
        std::cout << 3;
        break;
    
    default:
        std::cout << calc(N) % 15746;
        break;
    }
}