// https://www.acmicpc.net/problem/1157
#include <iostream>

int main() {
    int alphabet_frequency[26] = {0,};
    std::string input_string;
    std::cin >> input_string;
    const char* input_c_array = input_string.c_str();

    for(int i = 0; i < input_string.size(); i++) {
        if((int)input_c_array[i] >= (int)'a') {
            alphabet_frequency[(int)input_c_array[i] - (int)'a']++;
        } else {
            alphabet_frequency[(int)input_c_array[i] - (int)'A']++;
        }
        
    }
    int max = 0;
    int idx = -1;
    for(int i = 0; i < 26; i++) {
        if(alphabet_frequency[i] > max) {
            max = alphabet_frequency[i];
            idx = i;
        }
    }
    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(alphabet_frequency[i] == max) {
            count++;
        }
    }
    if(count == 1) {
        std::cout << (char)(idx + (int)'A');
    } else {
        std::cout << "?";
    }
}