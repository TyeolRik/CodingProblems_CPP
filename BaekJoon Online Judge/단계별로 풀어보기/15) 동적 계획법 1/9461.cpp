// https://www.acmicpc.net/problem/9461
#include <iostream>

unsigned long long save[101];

void initializer() {
    for(int i = 5; i < 101; i++) {
        save[i] = save[i - 1] + save[i - 5];
    }
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int T;
    int input;

    save[0] = 1;
    save[1] = 1;
    save[2] = 1;
    save[3] = 2;
    save[4] = 2;

    initializer();
    std::cin >> T;
    while(T --> 0) {
        std::cin >> input;
        std::cout << save[input - 1] << '\n';
    }
}