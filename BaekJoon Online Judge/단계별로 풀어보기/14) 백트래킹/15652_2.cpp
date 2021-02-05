// https://www.acmicpc.net/problem/15652
#include <iostream>
#include <numeric>
#include <vector>

std::vector<unsigned int> stack;

bool isSomethingBigger(std::vector<unsigned int> arr, unsigned int compare) {
    for(auto each : arr) {
        if(each > compare) {
            return true;
        }
    }
    return false;
}

void DFS(std::vector<unsigned int> graph, unsigned int recurisve_count) {
    // 재귀함수의 탈출조건
    if(recurisve_count == 0) {
        for(auto each : stack) {
            std::cout << each << ' ';
        }
        std::cout << "\n";
        return;
    }
    for(auto each : graph) {
        if(isSomethingBigger(stack, each)) {
            continue;
        }

        stack.push_back(each);
        DFS(graph, recurisve_count - 1);
        stack.pop_back();
    }
}

int main() {
    unsigned int N, M;
    std::cin >> N >> M;

    std::vector<unsigned int> arr(N);
    std::iota(arr.begin(), arr.end(), 1);

    DFS(arr, M);
}