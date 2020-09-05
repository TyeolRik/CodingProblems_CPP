// https://www.acmicpc.net/problem/2292
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    // 1 7 19 37 61
    //  6 12 18 24
    int count = 1;
    int start = 1;
    int temp = 6;
    while(true) {
        if(N == 1) {
            std::cout << count;
            return 0;
        }
        start = start + temp;
        temp = temp + 6;
        count++;
        if(N <= start) {
            std::cout << count;
            break;
        }
    }
}