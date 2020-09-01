// https://www.acmicpc.net/problem/8393
#include <iostream>

int main() {
    int a;
    std::cin >> a;
    int total = 0;
    while (a --> 0) {
        total = total + (a + 1);
    }
    std::cout << total << std::endl;
}