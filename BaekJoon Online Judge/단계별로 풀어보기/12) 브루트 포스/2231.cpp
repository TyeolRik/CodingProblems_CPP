// https://www.acmicpc.net/problem/2231
#include <iostream>
#include <vector>

int main() {
    int N, ret;
    std::cin >> N;

    for(int i = 10; i < N; i++) {
        std::vector<int> single_digit;
        int temp_sum = i;
        ret = i;
        while(ret > 0) {
            single_digit.push_back(ret % 10);
            ret = ret / 10;
        }
        for(int idx = 0; idx < single_digit.size(); idx++) {
            temp_sum = temp_sum + single_digit[idx];
        }
        if(temp_sum == N) {
            std::cout << i;
            return 0;
        }
    }

    std::cout << "0";
}