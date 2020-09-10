// https://www.acmicpc.net/problem/2581
#include <iostream>
#include <cmath>


bool is_prime_number(int input) {
    if(input == 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(input); i++) {
        if(input % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int M, N;
    std::cin >> M >> N;
    int sum = 0;
    int min = 0;
    for(int i = N; i >= M; i--) {
        if(is_prime_number(i)) {
            sum = sum + i;
            min = i;
        }
    }
    if(sum == 0) {
        std::cout << -1;
    } else {
        std::cout << sum << "\n";
        std::cout << min << "\n";
    }
}