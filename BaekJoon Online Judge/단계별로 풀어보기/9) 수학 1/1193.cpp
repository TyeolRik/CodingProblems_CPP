// https://www.acmicpc.net/problem/1193
#include <iostream>

// 1 2 6 7 15 16 28 29 45 46
int main() {
    int X;
    std::cin >> X;
    
    bool direction = true;      // TRUE: 좌하향, FALSE: 우상향
    int temp = 1;
    int mother = 1;
    int son = 1;
    int a = 1;
    int d = 1;

    while(X >= a) {
        a = a + d;
        d = d + 1;
        temp++;
        direction = !direction;
    }
    a = a - d + 1;               // Start Line
    temp = temp - 1;
    if(direction) {
        mother = temp;
        son = 1;
    } else {
        mother = 1;
        son = temp;
    }

    for(int i = 0; i < (X - a); i++) {
        if(direction) {
            mother--;
            son++;
        } else {
            mother++;
            son--;
        }
    }

    std::cout << son << "/" << mother;

}