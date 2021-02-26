// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int size;
    std::cin >> size;

    std::vector<std::vector<unsigned long long>> triangle;
    std::vector<std::vector<unsigned long long>> dp;
    triangle.reserve(size);
    dp.reserve(size);
    for(int i = 0; i < size; i++) {
        std::vector<unsigned long long> eachRow(i + 1);
        std::vector<unsigned long long> eachdp(i + 1);
        for(int j = 0; j < i + 1; j++) {
            std::cin >> eachRow[j];
        }
        triangle.push_back(eachRow);
        dp.push_back(eachdp);
    }

    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[0][0] + triangle[1][0];
    dp[1][1] = triangle[0][0] + triangle[1][1];

    for(int i = 2; i < size; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];

        for(int j = 1; j < i; j++) {
            dp[i][j] = std::max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
        
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }

    std::cout << *std::max_element(dp[size-1].begin(), dp[size-1].end());
}