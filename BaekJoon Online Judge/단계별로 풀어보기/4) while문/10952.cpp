// https://www.acmicpc.net/problem/10952
#include <iostream>

int main() {
    int a, b;
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    while(true) {
        std::cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        } else {
            std::cout << a + b << "\n";
        }
    }
}