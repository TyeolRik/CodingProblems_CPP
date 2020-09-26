// https://www.acmicpc.net/problem/15651
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> stack;

// procedure DFS(G, v) is
void DFS(std::vector<int> list, int recursive_count) {

    // 재귀함수의 탈출조건
    if(recursive_count == 0) {
        std::vector<int> temp = stack;
        // 출력
        int stack_size = temp.size();
        for(int i = 0; i < stack_size; i++) {
            std::cout << temp.at(i) << " ";
        }
        std::cout << "\n";

        return;
    }

    // label v as discovered // No need because this problem allows duplication
    // for all directed edges from v to w that are in G.adjacentEdges(v) do
    for(int i = 0; i < list.size(); i++) {
        // G.adjacentEdges(v) is list.at(i)
        // std::cout << list.at(i) << " ";
        stack.push_back(list.at(i));
        
        // if vertex w is not labeled as discovered then // All Vertex is not discovered because this problem allows duplication
            // recursively call DFS(G, w)
        // std::cout << "CALL Function DFS(list, " << recursive_count << ") From list.at(" << i << ")\n";
        DFS(list, recursive_count - 1);

        stack.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> list;
    list.reserve(N);
    for(int i = 0; i < N; i++) {
        list.push_back(i + 1);
    }

    DFS(list, M);
}