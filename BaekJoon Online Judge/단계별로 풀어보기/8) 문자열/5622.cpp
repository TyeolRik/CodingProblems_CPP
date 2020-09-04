// https://www.acmicpc.net/problem/5622
#include <iostream>

int calculate(std::string input) {
    int calc = 0;
    int* ret = new int[input.size()];
    const char* temp = input.c_str();
    for(int i = 0; i < input.size(); i++) {
        if(temp[i] < 'D') {
            ret[i] = 2;
        } else if(temp[i] < 'G') {
            ret[i] = 3;
        } else if(temp[i] < 'J') {
            ret[i] = 4;
        } else if(temp[i] < 'M') {
            ret[i] = 5;
        } else if(temp[i] < 'P') {
            ret[i] = 6;
        } else if(temp[i] < 'T') {
            ret[i] = 7;
        } else if(temp[i] < 'W') {
            ret[i] = 8;
        } else {
            ret[i] = 9;
        }
    }
    for(int i = 0; i < input.size(); i++) {
        calc = calc + ret[i] + 1;
    }
    return calc;
}

int main() {
    std::string input_string;
    std::cin >> input_string;
    std::cout << calculate(input_string);
}