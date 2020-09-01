// https://www.acmicpc.net/problem/10817
#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a == b) {
        std::cout << a;
    } else if (a > b) {
        if(b >= c) {
            std::cout << b;
        } else {
            if (a > c) {
                std::cout << c;
            } else {
                std::cout << a;
            }
        }
    } else {
        if (a >= c ) {
            std::cout << a;
        } else {
            if (b > c) {
                std::cout << c;
            } else {
                std::cout << b;
            }
        }
    }
}