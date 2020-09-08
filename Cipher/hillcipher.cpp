/*
* 평문 “act" 을 다음 내용에 따라 암호화하시오.
*/

// Coded in C++
// Compiled with G++ 9.3.0
// OS: Debian/Buster10
#include <iostream>
#include <vector>

std::vector<std::vector<int>> key = {{ 6, 24,  1},
                                     {13, 16, 10},
                                     {20, 17, 15}};

std::vector<std::vector<int>> multiple(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b) {
    if(a.at(0).size() != b.size()) {
        std::cout << "ERROR!" << std::endl;
        exit(1);
    }
    std::vector<std::vector<int>> ret(a.size(), std::vector<int> (b.at(0).size(), 0));

    for(int i = 0; i < ret.size(); i++) {
        for(int j = 0; j < ret.at(0).size(); j++) {
            int temp = 0;
            for(int idx = 0; idx < ret.size(); idx++) {
                temp = temp + a.at(i).at(idx) * b.at(idx).at(j);
            }
            ret.at(i).at(j) = temp % 26;
        }
    }
    return ret;
}

std::vector<std::vector<int>> string_to_matrix(std::string input) {
    std::vector<std::vector<int>> ret(input.size(), std::vector<int>(1, 0));
    for(int i = 0; i < input.size(); i++) {
        ret.at(i).at(0) = input.at(i) - (int)'a';
    }
    return ret;
}

std::string cipher_to_string(std::vector<std::vector<int>> cipher) {
    std::string ret(cipher.size(), ' ');
    for(int i = 0; i < cipher.size(); i++) {
        ret.at(i) = cipher.at(i).at(0) + (int)'a';
    }
    return ret;
}

int main() {
    std::string message = "cat";
    std::vector<std::vector<int>> message_matrix = string_to_matrix(message);
    std::vector<std::vector<int>> cipher = multiple(key, message_matrix);
    std::cout << cipher_to_string(cipher) << std::endl;
}