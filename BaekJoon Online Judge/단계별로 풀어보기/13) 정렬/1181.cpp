// https://www.acmicpc.net/problem/1181
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::string a, std::string b) {
    if(a.size() == b.size()) {
        return a < b;
    } else {
        return a.size() < b.size();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::string> list;
    list.reserve(N);
    for(int i = 0; i < N; i++) {
        std::string temp;
        std::cin >> temp;
        list.push_back(temp);
    }

    std::sort(list.begin(), list.end(), compare);                   // 정렬
    list.erase(std::unique(list.begin(), list.end()), list.end());  // 중복제거

    for(int i = 0; i < list.size(); i++) {
        std::cout << list.at(i) << "\n";
    }
}