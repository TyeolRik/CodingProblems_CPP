// https://www.acmicpc.net/problem/1085
#include <iostream>

int min(int* arr) {
    int ret = arr[0];
    for(int i = 0; i < 4; i++) {
        if(ret > arr[i]) {
            ret = arr[i];
        }
    }
    return ret;
}

int main() {
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;
    int arr[4] = {0, };
    arr[0] = x;
    arr[1] = y;
    (w - x) > 0 ? arr[2] = w - x : arr[2] = -1 * (w - x);
    (h - y) > 0 ? arr[3] = h - y : arr[3] = -1 * (h - y);
    std::cout << min(arr);
}