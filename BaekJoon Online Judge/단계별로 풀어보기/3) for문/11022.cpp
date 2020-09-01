// https://www.acmicpc.net/problem/11022
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n, a, b;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a >> b;
        std::cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << a+b << "\n";
    }
}