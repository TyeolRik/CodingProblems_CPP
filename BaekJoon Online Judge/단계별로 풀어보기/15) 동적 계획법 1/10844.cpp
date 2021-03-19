// https://www.acmicpc.net/problem/10844
#include <iostream>
#include <vector>

std::vector<std::vector<unsigned long long>> table;

void printRow(int rowNum) {
    std::cout << rowNum << '\t';
    for(unsigned long long each : table[rowNum]) {
        std::cout << each << '\t';
    }
    std::cout << '\n';
}

int main() {
    unsigned int N;
    std::cin >> N;

    if(N == 1) {
        std::cout << 9;
        return 0;
    }

    for(size_t i = 0; i < N; i++) {
        std::vector<unsigned long long> counts(10, 0);
        table.push_back(counts);
    }

    table[0] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    //printRow(0);

    for(size_t row = 1; row < N; row++) {
        table[row][0] = table[row-1][1] % 1000000000;
        for(size_t col = 1; col < 9; col++) {
            table[row][col] = (table[row-1][col - 1] + table[row-1][col + 1]) % 1000000000;
        }
        table[row][9] = (table[row-1][8]) % 1000000000;
        //printRow(row);
    }

    unsigned long long sum = 0;
    for(unsigned long long each : table[N-1]) {
        sum = sum + each;
        if(sum >= 1000000000) {
            sum = sum % 1000000000;
        }
    }
    std::cout << sum;
}