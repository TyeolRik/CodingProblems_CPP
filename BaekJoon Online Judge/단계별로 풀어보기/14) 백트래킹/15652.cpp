// https://www.acmicpc.net/problem/15652
#include <iostream>
#include <vector>

#define START       0

void DFS(std::vector<int> list, std::vector<int> storage, int now_index, int recursive) {
    if(recursive == 0) {
        for(int i = 0; i < storage.size(); i++) {
            std::cout << storage.at(i) << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int i = now_index; i < list.size(); i++) {
        storage.push_back(list.at(i));
        DFS(list, storage, i, recursive - 1);
        storage.pop_back();
    }
}



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> number_list;
    number_list.reserve(N);
    for(int i = 0; i < N; i++) {
        number_list.push_back(i + 1);
    }

    std::vector<int> picked_list;
    DFS(number_list, picked_list, START, M);
}