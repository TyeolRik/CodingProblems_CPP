// https://www.acmicpc.net/problem/11653
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

std::vector<int> getPrimeNumbers(int limit) {
    std::vector<int> ret(limit + 1);
    std::iota(ret.begin(), ret.end(), 0);

    ret[1] = 0;

    for(int i = 2; i < (int)std::sqrt(limit / 2); i++) {
        if(ret[i] == 0) {
            continue;
        }
        for(int j = i * 2; j < ret.size(); j = j + i) {
            ret[j] = 0;
        }
    }

    ret.erase(std::remove(ret.begin(), ret.end(), 0), ret.end());
    ret.shrink_to_fit();

    return ret;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> primeNumbers = getPrimeNumbers(N);

    while(N > 1.0) {
        for(auto i = 0; primeNumbers[i] <= N; i++) {
            if(N % primeNumbers[i] == 0) {
                N = N / primeNumbers[i];
                std::cout << primeNumbers[i] << "\n";
                break;
            }
        }
    }
    
}