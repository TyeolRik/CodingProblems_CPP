#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<int> coordinate(N);

    for(size_t i = 0; i < N; i++) {
        std::cin >> coordinate[i];
    }

    std::vector<int> copy = coordinate;
    std::copy(coordinate.begin(), coordinate.end(), copy.begin());

    std::sort(coordinate.begin(), coordinate.end());
    coordinate.erase(std::unique(coordinate.begin(), coordinate.end()), coordinate.end());

    std::vector<int> aligned(N);
    for(size_t i = 0; i < N; i++) {
        aligned[i] = std::lower_bound(coordinate.begin(), coordinate.end(), copy[i]) - coordinate.begin();
    }

    for(auto each : aligned) {
        std::cout << each << ' ';
    }
}