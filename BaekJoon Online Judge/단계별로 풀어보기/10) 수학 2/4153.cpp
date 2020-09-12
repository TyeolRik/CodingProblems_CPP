// https://www.acmicpc.net/problem/4153
#include <iostream>

void swap(double* arr, int a, int b) {
    double temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sort(double* arr) {
    if(arr[0] > arr[1]) {
        swap(arr, 0, 1);
    }
    if(arr[1] > arr[2]) {
        swap(arr, 1, 2);
    }
    if(arr[0] > arr[1]) {
        swap(arr, 0, 1);
    }
}

int main() {
    double length[3];

    while(true) {
        std::cin >> length[0] >> length[1] >> length[2];
        if(length[0] == 0 && length[1] == 0 && length[2] == 0) {
            break;
        }
        sort(length);
        if((length[0] * length[0] + length[1] * length[1]) == (length[2] * length[2])) {
            std::cout << "right" << "\n";
        } else {
            std::cout << "wrong" << "\n";
        }
    }
    
}