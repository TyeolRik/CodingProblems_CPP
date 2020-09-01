// https://www.acmicpc.net/problem/2753
#include <iostream>

int main() {
    int year; 
    std::cin >> year;
    if (year % 4 == 0) {
        if (year % 400 == 0) {
            std::cout << "1";
        } else if (year % 100 != 0) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    } else {
        std::cout << "0";
    }
}