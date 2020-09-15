// https://www.acmicpc.net/problem/10870
#include <iostream>

int fibo(int input) {
    switch (input)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return fibo(input - 2) + fibo(input - 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibo(n);
}