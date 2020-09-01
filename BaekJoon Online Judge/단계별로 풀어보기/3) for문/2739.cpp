// https://www.acmicpc.net/problem/2739
#include <iostream>

int main() {
    int a;
    std::cin >> a;
    for (int i = 1; i < 10; i++) {
        std::cout << a << " * " << i << " = " << a * i << std::endl;
    }
}