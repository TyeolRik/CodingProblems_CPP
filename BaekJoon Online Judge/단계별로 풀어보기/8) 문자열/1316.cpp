// https://www.acmicpc.net/problem/1316
#include <iostream>

bool wordCheck() {
    int flag[26] = {0,};
    std::string input;
    std::cin >> input;
    const char* inputArray = input.c_str();
    for(int i = 0; i < input.size(); i++) {
        int char_to_index = (int)input[i] - (int)'a';
        if(flag[char_to_index] == 0) {
            flag[char_to_index]++;
        } else {
            if(inputArray[i] != inputArray[i-1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    int count = 0;
    std::cin >> N;
    while(N --> 0) {
        if(wordCheck()) {
            count++;
        }
    }
    std::cout << count;
}