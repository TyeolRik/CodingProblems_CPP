// https://www.acmicpc.net/problem/1110
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int count = 1;
    int original;
    std::cin >> original;
    int newNumber = (original % 10) * 10 + ((original / 10) + (original % 10)) % 10;
    while (original != newNumber) {
        newNumber = (newNumber % 10) * 10 + ((newNumber / 10) + (newNumber % 10)) % 10;
        count++;
    }
    std::cout << count;
}