// https://www.acmicpc.net/problem/10872
#include <iostream>

int factorial(int input) {
    if(input < 2) {
        return 1;
    } else {
        return input * factorial(input - 1);
    }
}

int main() {
    int N;
    std::cin >> N;
    std::cout << factorial(N);
}