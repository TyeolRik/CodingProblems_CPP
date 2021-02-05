// https://www.acmicpc.net/problem/15651
#include <iostream>
#include <vector>
#include <numeric>

std::vector<unsigned int> stack;

void DFS(std::vector<unsigned int> graph, unsigned int recursive_count) {
    // 탈출조건
    if(recursive_count == 0) {
        for(auto each : stack) {
            std::cout << each << ' ';
        }
        std::cout << "\n";
        
        return;
    }

    for(auto each : graph) {
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