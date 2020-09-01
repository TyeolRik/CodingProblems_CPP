// https://www.acmicpc.net/problem/2884
#include <iostream>

int main() {
    int hour, minute;
    std::cin >> hour >> minute;
    if(minute < 45) {
        minute = minute + 15;
        hour = hour - 1;
        if (hour < 0) {
            hour = hour + 24;
        }
    } else {
        minute = minute - 45;
    }
    std::cout << hour << " " << minute;
}