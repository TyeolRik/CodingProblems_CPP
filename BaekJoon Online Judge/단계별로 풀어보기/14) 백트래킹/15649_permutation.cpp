// https://www.acmicpc.net/problem/15649
#include <iostream>
#include <vector>
#include <algorithm>

#include <chrono>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::vector<int>> permutation_list;
    std::vector<int> temp;
    temp.reserve(N);
    for(int i = 0; i < N; i++) {
        temp.push_back(i + 1);
    }
    do {
        std::vector<int> feed;
        feed.reserve(M);
        for(int i = 0; i < M; i++) {
            feed.push_back(temp.at(i));
        }
        permutation_list.push_back(feed);
    } while(std::next_permutation(temp.begin(), temp.end()));

    permutation_list.erase(std::unique(permutation_list.begin(), permutation_list.end()), permutation_list.end());

    for(int i = 0; i < permutation_list.size(); i++) {
        for(int j = 0; j < permutation_list.at(i).size(); j++) {
            // std::cout << permutation_list.at(i).at(j) << " ";
        }
        // std::cout << "\n";
    }
    
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    std::cout << "Time cost : " << microseconds / 1000.0 << "ms\n";
}