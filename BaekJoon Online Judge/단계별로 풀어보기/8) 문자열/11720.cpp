// https://www.acmicpc.net/problem/11720
#include <iostream>

int main() {
    int ret = 0;
    int N;
    std::cin >> N;
    std::string input;
    std::cin >> input;
    const char* inputarray = input.c_str();
    for(int i = 0; i < input.size(); i++) {
        ret = ret + (inputarray[i] - 48);
    }
    std::cout << ret << "\n";
}