// https://www.acmicpc.net/problem/9184
#include <iostream>
#include <vector>
#include <numeric>

#define UNDEFINED   -9999

int w[21][21][21];

int calc(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return 1;
    } else if(a > 20 || b > 20 || c > 20) {
        return w[20][20][20];
    } else if(w[a][b][c] != UNDEFINED) {
        return w[a][b][c];
    } else if(a < b && b < c) {
        int ret = calc(a, b, c-1) + calc(a, b-1, c-1) - calc(a, b-1, c);
        w[a][b][c] = ret;
        return ret;
    } else {
        int ret = calc(a-1, b, c) + calc(a-1, b-1, c) + calc(a-1, b, c-1) - calc(a-1, b-1, c-1);
        w[a][b][c] = ret;
        // std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << "\n";
        return ret;
    }
}

void initialize() {
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            for(int k = 0; k < 21; k++) {
                w[i][j][k] = UNDEFINED;
            }
        }
    }
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            for(int k = 0; k < 21; k++) {
                w[i][j][k] = calc(i, j, k);
            }
        }
    }
}

int main() {

    // Initialize Data
    initialize();
    int a = 0;
    int b = 0;
    int c = 0;

    while(true) {
        std::cin >> a >> b >> c;
        if((a == -1) && (b == -1) && (c == -1)) {
            exit(0);
        } else if(a <= 0 || b <= 0 || c <= 0) {
            std::cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
        } else if(a > 20 || b > 20 || c > 20) {
            std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w[20][20][20] << "\n";
        } else {
            std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << "\n";
        }
    }
}