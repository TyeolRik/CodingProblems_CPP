// https://www.acmicpc.net/problem/2908
#include <iostream>

int convert(std::string input) {
    char* temp = new char[input.size() + 1];
    std::copy(input.begin(), input.end(), temp);
    temp[input.size()] = '\0';
    for(int i = 0; i < (input.size()) / 2; i++) {
        char tmp = temp[i];
        temp[i] = temp[input.size() - i - 1];
        temp[input.size() - i - 1] = tmp;
    }
    int ret = atoi(temp);
    return ret;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    int a_change = convert(a);
    int b_change = convert(b);
    if(a_change > b_change) {
        std::cout << a_change;
    } else {
        std::cout << b_change;
    }
}