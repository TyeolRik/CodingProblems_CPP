// https://www.acmicpc.net/problem/1152
#include <iostream>
#include <sstream>

/*
* 반드시 std::string과 std::stringstream을 이용해서 파싱하는 것 잊지 말 것.
* 토크나이저는 getline(std::cin, (저장 될)std::string, delimiter(ex. ' '))
* #include <sstream> 잊지 말 것.
*/

int main() {
    std::string input_line;
    std::string word;
    int count_word = 0;
    std::getline(std::cin, input_line);
    std::stringstream linestream(input_line);
    while(linestream >> word) {
        ++count_word;
    }
    std::cout << count_word;
}