// https://www.acmicpc.net/problem/1978
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
    int N , temp;
    int count = 0;
    std::cin >> N;
    while(N --> 0) {
        std::cin >> temp;
        if(is_prime_number(temp)) {
            count++;
        }
    }
    std::cout << count;
}