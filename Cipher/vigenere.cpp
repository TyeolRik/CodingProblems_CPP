/*
* 평문 “iloveyou" 을 다음 내용에 따라 암호화하시오.
*/

// Coded in C++
// Compiled with G++ 9.3.0
// OS: Debian/Buster10
#include <iostream>

int main() {
    std::string input = "iloveyou";
    char output[input.size() + 1];
    std::copy(input.begin(), input.end(), output);
    output[input.size()] = '\0';

    int key[4] = {1, 3, 5, 7};
    for(int i = 0; i < input.size(); i++) {
        output[i] = ((int)input[i] - (int)'a' + key[i % 4]) % 26 + (int)'a';
    }
    std::cout << output;
}