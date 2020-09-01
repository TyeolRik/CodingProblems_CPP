// https://www.acmicpc.net/problem/9498
#include <iostream>

int main() {
    int a;
    std::cin >> a;
    if (a >= 90) {
        std::cout << "A";
    } else if (a >= 80) {
        std::cout << "B";
    } else if (a >= 70) {
        std::cout << "C";
    } else if (a >= 60) {
        std::cout << "D";
    } else {
        std::cout << "F";
    }
}