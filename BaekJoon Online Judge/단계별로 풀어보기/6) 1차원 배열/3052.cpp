// https://www.acmicpc.net/problem/3052
#include <iostream>

int main() {
    int count = 0;
    int i, idx;
    int inputs[10];
    for(int i = 0; i < 10; i++) {
        std::cin >> inputs[i];
        inputs[i] = inputs[i] % 42;
    }
    for(i = 0; i < 10; i++) {
        bool flag = false;
        for(idx = 0; idx < i; idx++) {
            if(inputs[i] == inputs[idx]) {
                break;
            }
        }
        if(i == idx) {
            count++;
        }
    }
    std::cout << count << "\n";
}