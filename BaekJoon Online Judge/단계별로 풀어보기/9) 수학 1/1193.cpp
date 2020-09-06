// https://www.acmicpc.net/problem/1193
#include <iostream>

// 1 2 4 7 11 ...
int main() {
    int X;
    std::cin >> X;
    int now = 1;
    int d = 1;
    while(true) {
        if(now >= X) {
            break;
        }
        now = now + d;
        d = d + 1;
    }
    std::cout << now << std::endl;
    int denominator = 1;
    int numerator = d - 1;
    while(now -->= X) {
        denominator++;
        numerator--;
    }
    std::cout << numerator << "/" << denominator;
}