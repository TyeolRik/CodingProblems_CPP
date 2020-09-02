// https://www.acmicpc.net/problem/4673
#include <iostream>
#define TARGET    10000

int func(int n) {
    int ret = n;
    while(n > 0) {
        ret = ret + (n % 10);
        n = n / 10;
    }
    return ret;
}

int main() {
    int constant[TARGET];
    for(int i = 0; i < TARGET; i++) {
        constant[i] = i + 1;
    }
    for(int i = 1; i < TARGET; i++) {
        int now = func(i);
        if(now < TARGET) {
            constant[now - 1] = 0;
        }
    }
    for(int i = 0; i < TARGET; i++) {
        if(constant[i] != 0 && constant[i] < TARGET) {
            std::cout << constant[i] << "\n";
        }
    }
}