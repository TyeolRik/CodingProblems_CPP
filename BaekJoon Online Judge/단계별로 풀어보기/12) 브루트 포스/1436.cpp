// https://www.acmicpc.net/problem/1436
#include <iostream>

int main() {
    int N;
    int count = 600;
    std::string input;
    std::cin >> N;
    while(N > 0) {
        input = std::to_string(count++);
        for(int i = 0; i < input.size() - 2; i++) {
            if(input[i] == '6' && input[i+1] == '6' && input[i+2] == '6') {
                N--;
                goto personal_continue;
            }
        }
        personal_continue:;
    }
    std::cout << input;
}