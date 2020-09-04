// https://www.acmicpc.net/problem/2675
#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int T;
    std::cin >> T;
    for(int i = 0; i < T; i++) {
        int R;
        std::string S;
        std::cin >> R >> S;
        const char* S_array = S.c_str();
        for(int idx = 0; idx < S.size(); idx++) {
            for(int i = 0; i < R; i++) {
                std::cout << S_array[idx];
            }
        }
        std::cout << "\n";
    }
}