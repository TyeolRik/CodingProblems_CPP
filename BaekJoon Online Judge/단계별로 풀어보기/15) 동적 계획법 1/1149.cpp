// https://www.acmicpc.net/problem/1149
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<std::vector<unsigned long long>> cost;
std::vector<std::vector<unsigned long long>> results;

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::cin >> N;

    cost.reserve(N);
    for(int i = 0; i < N; i++) {
        std::vector<unsigned long long> eachRow(3);
        std::vector<unsigned long long> eachResults(3);
        for(int j = 0; j < 3; j++) {
            std::cin >> eachRow[j];
        }
        cost.push_back(eachRow);
        results.push_back(eachResults);
    }
    results[0][0] = cost[0][0];
    results[0][1] = cost[0][1];
    results[0][2] = cost[0][2];

    for(int i = 1; i < N; i++) {
        results[i][0] = std::min(results[i-1][1], results[i-1][2]) + cost[i][0];
        results[i][1] = std::min(results[i-1][0], results[i-1][2]) + cost[i][1];
        results[i][2] = std::min(results[i-1][1], results[i-1][0]) + cost[i][2];
    }

    std::cout << *std::min_element(results[N-1].begin(), results[N-1].end()) << "\n";
}