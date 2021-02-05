// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>

std::vector<unsigned int> stack;

bool isSomethingBigger(std::vector<unsigned int> arr, unsigned int comparing) {
    for(auto each : arr) {
        if(each >= comparing) {
            return true;
        }
    }
    return false;
}

void DFS(std::vector<unsigned int> graph, unsigned int recursive_count) {

    // 재귀함수의 탈출조건
    if(recursive_count == 0) {
        for(auto item : stack) {
            std::cout << item << ' ';
        }
        std::cout << "\n";

        return;
    }

    for(auto each : graph) {
        // 만약, stack 안의 값들이 현재 값보다 크면 (문제조건)
        if(isSomethingBigger(stack, each)) {
            continue;
        }

        stack.push_back(each);
        DFS(graph, recursive_count - 1);
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