// https://www.acmicpc.net/problem/15649

/**
 * Attempt to build Recursive function call DFS code for problem no. 15649
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include <stack>
#include <chrono>

std::vector<unsigned int> stack;

void DFS(std::vector<unsigned int> graph, unsigned int recursive_count)
{

    // 재귀함수의 탈출조건
    if (recursive_count == 0)
    {
        // 출력
        for (auto each : stack)
        {
            std::cout << each << ' ';
        }
        std::cout << "\n";

        return;
    }

    for (auto each : graph)
    {
        // 만약, 중복된 것이 있다면 (문제조건 : 중복 없이 M개를 고른 수열)
        if (std::find(stack.begin(), stack.end(), each) < stack.end())
        {
            continue;
        }
        else
        {
            stack.push_back(each);
            DFS(graph, recursive_count - 1);
            stack.pop_back();
        }
    }
}

int main()
{

    unsigned int N, M;
    std::cin >> N >> M;

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<unsigned int> arr(N);
    std::iota(arr.begin(), arr.end(), 1);

    DFS(arr, M);

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    std::cout << "Time cost : " << microseconds / 1000.0 << "ms\n";
}