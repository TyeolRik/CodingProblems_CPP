// https://www.acmicpc.net/problem/10250
#include <iostream>

int main() {
    int T, H, W, N;
    std::cin >> T;
    while(T --> 0) {
        std::cin >> H >> W >> N;
        int line = ((N - 1 )/ H) + 1;
        int floor = ((N - 1) % H) + 1;
        std::cout << floor*100 + line << std::endl;
    }
}