// https://www.acmicpc.net/problem/9251
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    s1.insert(s1.begin(), '0');
    s2.insert(s2.begin(), '0');

    std::vector<std::vector<int>> dp(s2.size());
    for(int row = 0; row < dp.size(); row++) {
        dp[row] = std::vector<int>(s1.size());
        for(int col = 0; col < dp[row].size(); col++) {
            if(row == 0 || col == 0) {
                dp[row][col] = 0;
                continue;
            }
            if(s2[row] == s1[col]) {
                dp[row][col] = dp[row-1][col-1] + 1;
                continue;
            } else {
                dp[row][col] = std::max(dp[row-1][col], dp[row][col-1]);
            }
        }
    }
    std::cout << dp[s2.size()-1][s1.size()-1];
    return 0;
}