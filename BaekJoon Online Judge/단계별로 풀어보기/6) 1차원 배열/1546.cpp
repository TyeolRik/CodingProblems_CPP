// https://www.acmicpc.net/problem/1546
#include <iostream>

float max(float* array, int size) {
    float ret = array[0];
    while(size --> 0) {
        if(array[size] > ret) {
            ret = array[size];
        }
    }
    return ret;
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int N;
    std::cin >> N;
    float* grade = (float *)malloc(sizeof(float) * N);
    for(int i = 0; i < N; i++) {
        std::cin >> grade[i];
    }
    float max_grade = max(grade, N);
    for(int i = 0; i < N; i++) {
        grade[i] = grade[i] / max_grade * 100;
    }
    float avg = 0;
    for(int i = 0; i < N; i++) {
        avg = avg + grade[i];
    }
    std::cout << avg / N;
}