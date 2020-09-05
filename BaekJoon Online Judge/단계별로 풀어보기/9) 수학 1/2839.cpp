// https://www.acmicpc.net/problem/2839
#include <iostream>

int main() {
    int N, a, b;
    std::cin >> N;
    for(int kg_3 = 0; kg_3 < (N / 3) + 1; kg_3++) {
        for(int kg_5 = 0; kg_5 < (N / 5) + 1; kg_5++) {
            if((kg_5*5 + kg_3*3) == N) {
                std::cout << kg_5 + kg_3;
                exit(0);
            }
        }
    }
    std::cout << "-1";
}