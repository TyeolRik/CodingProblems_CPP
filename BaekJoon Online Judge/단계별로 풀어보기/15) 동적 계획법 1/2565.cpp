// https://www.acmicpc.net/problem/2565
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

typedef struct Line {
    int A, B;
} Line;

bool customCompare(Line a, Line b) {
    return a.A < b.A;
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int theNumberOfWire;
    std::cin >> theNumberOfWire;

    std::vector<int> pole(theNumberOfWire);
    std::vector<Line> connection(theNumberOfWire);

    int poleA, poleB;
    for(auto i = 0; i < theNumberOfWire; i++) {
        std::cin >> poleA >> poleB;
        connection[i] = {poleA, poleB};
    }
    std::sort(connection.begin(), connection.end(), customCompare);

    for(auto i = 0; i < theNumberOfWire; i++) {
        pole[i] = connection[i].B;
    }

    int length = 0;
    for(auto i = 0; i < theNumberOfWire; i++) {
        int here = pole[i];
        auto pos = std::lower_bound(pole.begin(), pole.begin() + length, here);
        *pos = here;
        if(pos == pole.begin() + length) {
            length++;
        }
    }

    std::cout << (theNumberOfWire - length);
}