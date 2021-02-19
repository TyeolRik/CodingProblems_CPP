// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int inputSize;
int maximum = INT32_MIN;
int minimum = INT32_MAX;
std::vector<int> input;
std::vector<int> function;

int calculation(int input, int a, int b) {
    switch (input)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    default:
        std::cout << "ERROR\n";
        break;
    }
}

void DFS() {
    do {
        do {
            int ret = input[0];
            int func;
            for(int i = 1; i < inputSize; i++) {
                ret = calculation(function[i - 1], ret, input[i]);
            }
            if(ret > maximum) {
                maximum = ret;
            }
            if(ret < minimum) {
                minimum = ret;
            }
        } while(std::next_permutation(function.begin(), function.end()));
    } while(std::next_permutation(input.begin(), input.end()));
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::cin >> inputSize;
    input.reserve(inputSize);
    for(int i = 0; i < inputSize; i++) {
        std::cin >> input[i];
    }
    function.reserve(inputSize-1);
    int functionInputs[4];
    std::cin >> functionInputs[0] >> functionInputs[1] >> functionInputs[2] >> functionInputs[3];

    for(int i = 0; i < functionInputs[0]; i++) {
        function.push_back(0);
    }
    for(int i = 0; i < functionInputs[1]; i++) {
        function.push_back(1);
    }
    for(int i = 0; i < functionInputs[2]; i++) {
        function.push_back(2);
    }
    for(int i = 0; i < functionInputs[3]; i++) {
        function.push_back(3);
    }

    DFS();
    std::cout << maximum << '\n' << minimum;
}