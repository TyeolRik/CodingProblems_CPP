// https://www.acmicpc.net/problem/10809
#include <iostream>

int main() {
    std::string S;
    std::cin >> S;
    const char* S_array = S.c_str();
    bool flag;
    int arr[26] = {-1,};
    for(int i = 0; i < 26; i++) {
        arr[i] = -1;
    }
    for(int i = 0; i < 26; i++) {
        flag = false;
        for(int j = 0; j < S.size(); j++) {
            if(i + (int)'a' == S_array[j]) {
                flag = true;
                std::cout << j << " ";
                break;
            }
        }
        if(flag == false) {
            std::cout << "-1 ";
        }
    }
}