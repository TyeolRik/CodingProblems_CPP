// https://www.acmicpc.net/problem/4344
#include <iostream>

float calc(int* data, int data_size, float average) {
    float count = 0.0;
    for(int i = 0; i < data_size; i++) {
        if(data[i] > average) {
            count++;
        }
    }
    return count / (float)data_size;
}

float avg(int* data, int size) {
    float ret = 0;
    for(int i = 0; i < size; i++) {
        ret = ret + data[i];
    }
    return ret / (float)size;
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int C;
    std::cin >> C;
    std::cout << std::fixed;
    std::cout.precision(3);
    while(C --> 0) {
        int N;
        int *data;
        std::cin >> N;
        data = (int *)malloc(sizeof(int) * N);
        for(int i = 0; i < N; i++) {
            std::cin >> data[i];
        }
        std::cout << calc(data, N, avg(data, N)) * 100 << "%\n";
    }

}