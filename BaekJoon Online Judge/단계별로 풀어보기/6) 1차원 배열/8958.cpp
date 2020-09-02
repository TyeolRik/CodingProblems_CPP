// https://www.acmicpc.net/problem/8958
#include <iostream>
#include <string>

int calc(std::string _inputs) {
    int point = 0;
    int temp = 0;
    const char* _inputs_array = _inputs.c_str();
    for(int i = 0; i < _inputs.length(); i++) {
        if(_inputs_array[i] == 'O') {
            point = point + (++temp);
        } else {
            temp = 0;
        }
    }
    return point;
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::string input;
        std::cin >> input;
        std::cout << calc(input) << "\n";
    }
}