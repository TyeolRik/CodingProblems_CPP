// https://www.acmicpc.net/problem/15552
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int T, a, b;
    std::cin >> T;
    while (T --> 0) {
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }
}