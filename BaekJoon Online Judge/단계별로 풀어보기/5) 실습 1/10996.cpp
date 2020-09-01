// https://www.acmicpc.net/problem/10996
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n;
    std::cin >> n;
    int even = 0;
    for(int i = 0; i < 2*n; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < n; j++) {
                if(j % 2 == 0) {
                    std::cout << "*";
                } else {
                    std::cout << " ";
                }
            }
        } else {
            for(int j = 0; j < n; j++) {
                if(j % 2 == 0) {
                    std::cout << " ";
                } else {
                    std::cout << "*";
                }
            }
        }
        std::cout << "\n";
    }
}