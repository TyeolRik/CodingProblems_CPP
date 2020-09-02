// https://www.acmicpc.net/problem/1065
#include <iostream>

bool func(int input) {
    if(input < 100) {
        return true;
    }
    if(input == 1000) {
        return false;
    }
    int a, b, c;
    a = input / 100;
    b = (input / 10) % 10;
    c = input % 10;
    if(b - a == c - b) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N;
    std::cin >> N;
    int count;
    if(N < 100) {
        count = N;
    } else {
        count = 99;
        for(int i = 100; i <= N; i++) {
            if(func(i) == true) {
                count++;
            }
        }
    }
    std::cout << count;
}