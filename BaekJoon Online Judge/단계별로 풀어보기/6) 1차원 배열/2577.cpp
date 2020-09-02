// https://www.acmicpc.net/problem/2577
#include <iostream>

/* 전략
- int를 char 배열로 바꾼다.
- 배열이므로 index를 증가시킴에 따라 각 숫자가 무엇인지 알 수 있다.
*/

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int mul = a * b * c;
    std::string s = std::to_string(mul);
    char const *number = s.c_str();
    int digit[10] = {0, };
    for(int i = 0; i < s.length(); i++) {
        if(number[i] == 48) {           // 48인 이유: ACSII 에서 48은 숫자 0을 의미함.
            digit[0]++;
        } else {
            digit[number[i] - 48]++;    // index = 1 이 숫자 1의 개수이므로 ASCII에서는 49. (= 49 - 48 = 1)
        }
    }
    for(int i = 0; i < 10; i++) {
        std::cout << digit[i] << "\n";
    }
}