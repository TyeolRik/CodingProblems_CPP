// https://www.acmicpc.net/problem/11021
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N, a, b;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> a >> b;
        std::cout << "Case #" << i + 1 << ": " << a+b << "\n";
    }
}