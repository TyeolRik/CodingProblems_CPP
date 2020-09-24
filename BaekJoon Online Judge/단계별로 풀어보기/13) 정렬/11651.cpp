// https://www.acmicpc.net/problem/11650
#include <iostream>
#include <vector>
#include <algorithm>

class coordination {
    public:
    int x;
    int y;

    coordination() {
        x = 0;
        y = 0;
    }
    coordination(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

bool compare(coordination a, coordination b) {
    if(a.y == b.y) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin >> N;
    std::vector<coordination> list;
    for(int i = 0; i < N; i++) {
        int x;
        int y;
        std::cin >> x >> y;
        list.push_back(coordination(x, y));
    }
    std::sort(list.begin(), list.end(), compare);

    for(int i = 0; i < list.size(); i++) {
        std::cout << list.at(i).x << " " << list.at(i).y << "\n";
    }
}