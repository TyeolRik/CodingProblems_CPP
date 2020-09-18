// https://www.acmicpc.net/problem/11729
#include <iostream>

std::string str_temp;

int hanoi(int number_of_disk, int from, int _and, int to) {
    int temp = 0;
    if(number_of_disk == 1) {
        str_temp.append(std::to_string(from) + " " + std::to_string(to) + "\n");
        //std::cout << from << " " << to << '\n';
        temp = temp + 1;
    } else {
        temp = temp + hanoi(number_of_disk - 1, from, to, _and);
        str_temp.append(std::to_string(from) + " " + std::to_string(to) + "\n");
        // std::cout << from << " " << to << '\n';
        temp = temp + 1;
        temp = temp + hanoi(number_of_disk - 1, _and, from, to);
    }
    return temp;
}

int main() {
    str_temp.reserve(10000000);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin >> N;

    std::cout << hanoi(N, 1, 2, 3) << "\n";
    std::cout << str_temp;
}