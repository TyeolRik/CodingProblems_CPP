// https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

int N;
std::vector<std::vector<int>> S;
std::vector<int> member;
std::vector<bool> combination;
std::vector<int> teamStart;
std::vector<int> teamLink;

int main() {
    int minimum = INT32_MAX;
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::cin >> N;
    S = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> S[i][j];
        }
    }

    // 변수 초기화
    member = std::vector<int>(N);
    combination = std::vector<bool>(N);
    std::iota(member.begin(), member.end(), 0);
    std::fill(combination.begin(), combination.end(), false);
    std::fill_n(combination.begin(), (N / 2), true);
    teamStart = std::vector<int>(N/2);
    teamLink = std::vector<int>(N/2);

    do {
        int teamStartIndex = 0;
        int teamLinkIndex = 0;
        for(int i = 0; i < N; i++) {
            if(combination[i]) {
                teamStart[teamStartIndex++] = member[i];
            } else {
                teamLink[teamLinkIndex++] = member[i];
            }
        }

        int teamStartPower = 0;
        for(int i = 0; i < teamStartIndex; i++) {
            for(int j = 0; j < teamStartIndex; j++) {
                teamStartPower = teamStartPower + S[teamStart[i]][teamStart[j]];
            }
        }

        int teamLinkPower = 0;
        for(int i = 0; i < teamLinkIndex; i++) {
            for(int j = 0; j < teamLinkIndex; j++) {
                teamLinkPower = teamLinkPower + S[teamLink[i]][teamLink[j]];
            }
        }

        int ret = std::abs(teamLinkPower - teamStartPower);
        if(ret < minimum) {
            minimum = ret;
        }
    } while(std::prev_permutation(combination.begin(), combination.end()));

    std::cout << minimum;
} 