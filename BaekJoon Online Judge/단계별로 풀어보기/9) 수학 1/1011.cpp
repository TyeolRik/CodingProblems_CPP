// https://www.acmicpc.net/problem/1011
#include <iostream>

/*
     1: 1       1
     2: 2       1 1
     3: 3       1 1 1
     4: 3       1 2 1
     5: 4       1 2 1 1
     6: 4       1 2 2 1
     7: 5       1 2 2 1 1
     8: 5       1 2 2 2 1
     9: 5       1 2 3 2 1
    10: 6       1 2 3 2 1 1
    11: 6       1 2 3 2 2 1
    12: 6       1 2 3 3 2 1
    13: 7       1 2 3 3 2 1 1
    14: 7       1 2 3 3 2 2 1
    15: 7       1 2 3 3 3 2 1
    16: 7       1 2 3 4 3 2 1

3 - 2
4 - 2
5 - 3
6 - 3
7 - 4
8 - 4
9 - 4
*/

int length_to_hop(int length) {
    

}

int main() {
    int T, x, y;
    std::cin >> T;
    while(T --> 0) {
        std::cin >> x >> y;
        int length = y - x;
        if(length < 3) {
            std::cout << length;
        } else {

        }
    }
}