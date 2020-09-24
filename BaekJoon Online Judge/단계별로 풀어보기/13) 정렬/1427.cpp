// https://www.acmicpc.net/problem/1427
#include <iostream>
#include <algorithm>

bool desc(char a, char b) {
    return a > b;
}

int main() {
    std::string N;
    std::cin >> N;
    std::sort(N.begin(), N.end(), desc);
    std::cout << N;
}