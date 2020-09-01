// https://www.acmicpc.net/problem/10951
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int a, b;
    while(true) {
        std::cin >> a >> b;
        if(std::cin.eof() == true) {
            break;
        }
        std::cout << a + b << "\n";
    }
}