// https://www.acmicpc.net/problem/10989
#include <iostream>
#include <vector>
#include <algorithm>

int counter[10001] = {0,};

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    std::cin >> N;
    int eachInput;
    for(int i = 0; i < N; i++) {
        std::cin >> eachInput;
        counter[eachInput]++;
    }
    for(int i = 1; i < 10001; i++) {
        if(counter[i] > 0) {
            for(int j = 0; j < counter[i]; j++) {
                std::cout << i << "\n";
            }
        }
    }
}