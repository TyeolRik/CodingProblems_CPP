// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> list;
    list.reserve(N);

    for(int i = 0; i < N; i++) {
        list.push_back(i + 1);
    }

    std::string bitmask(M, 1);
    bitmask.resize(N, 0);
    
    do{
        for(int i = 0; i < N; i++) {
            if(bitmask.at(i)) {
                std::cout << list.at(i) << " ";
            }
        }
        std::cout << "\n";
    } while(std::prev_permutation(bitmask.begin(), bitmask.end()));
}
