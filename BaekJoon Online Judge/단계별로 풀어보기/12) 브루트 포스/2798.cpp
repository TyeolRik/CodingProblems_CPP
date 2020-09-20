// https://www.acmicpc.net/problem/2798
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int N, M;
    int ret[3];
    std::cin >> N >> M;

    std::vector<int> numbers;
    std::vector<int> temp;
    int answer[3] = {0,};
    for(int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        numbers.push_back(x);
        temp.push_back(0);
    }

    ret[0] = numbers[0];
    ret[1] = numbers[1];
    ret[2] = numbers[2];
    
    int difference = std::abs((ret[0] + ret[1] + ret[2]) - M);

    temp.at(N - 3) = 1;
    temp.at(N - 2) = 1;
    temp.at(N - 1) = 1;

    do {
        int temp_sel[3];
        int idx_count = 0;
        for(int i = 0; i < N; i++) {
            if(temp[i] == 1) {
                temp_sel[idx_count++] = numbers[i];
            }
        }
        int sum = 0;
        for(int i = 0; i < 3; i++) {
            sum = sum + temp_sel[i];
        }
        int temp_diff = std::abs(sum - M);
        if(sum == M) {
            ret[0] = temp_sel[0];
            ret[1] = temp_sel[1];
            ret[2] = temp_sel[2];
            goto answer;
        }
        if(sum < M && temp_diff < difference) {
            ret[0] = temp_sel[0];
            ret[1] = temp_sel[1];
            ret[2] = temp_sel[2];
            difference = temp_diff;
        }

    } while(std::next_permutation(temp.begin(), temp.end()));

    answer:;
    std::cout << ret[0] + ret[1] + ret[2];
}