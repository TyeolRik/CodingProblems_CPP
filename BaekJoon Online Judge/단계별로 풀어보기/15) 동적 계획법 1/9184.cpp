// https://www.acmicpc.net/problem/9184
#include <iostream>
#include <vector>
#include <numeric>

short w[21][21][21];

void initialize() {
    w[0][0][0] = 1;
    w[0][0][1] = 1;
    w[0][1][0] = 1;
    w[0][1][1] = 1;
    w[1][0][0] = 1;
    w[1][0][1] = 1;
    w[1][1][0] = 1;
    
    
}

int main() {

    // Initialize Data
    initialize();
    short a = 0;
    short b = 0;
    short c = 0;

    while(true) {
        std::cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) {
            exit(-1);
        } else if(a > 20 || b > 20 || c > 20) {
            std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w[20][20][20] << "\n";
        } else {
            std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << "\n";
        }
    }
}