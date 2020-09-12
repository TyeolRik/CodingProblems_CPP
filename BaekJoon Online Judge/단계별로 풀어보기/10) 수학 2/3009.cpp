// https://www.acmicpc.net/problem/3009
#include <iostream>

int less(int a, int b, int c) {
    if(a == b) {
        return c;
    } else if(a == c) {
        return b;
    } else {
        return a;
    }
}

int main() {
    int position[4][2];
    for(int i = 0; i < 3; i++) {
        std::cin >> position[i][0] >> position[i][1];
    }
    std::cout << less(position[0][0], position[1][0], position[2][0])\
              << " "\
              << less(position[0][1], position[1][1], position[2][1]);
}