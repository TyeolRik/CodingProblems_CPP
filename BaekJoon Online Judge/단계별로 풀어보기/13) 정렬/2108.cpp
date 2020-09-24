// https://www.acmicpc.net/problem/2108
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int arithmetic_mean(short* arr, int size) {
    double ret = 0.0;
    for(int i = 0; i < size; i++) {
        ret = ret + arr[i];
    }
    return round((ret / (double)size));   // 반올림
}

short median(short* arr, int size) {
    return arr[size / 2];
}

short mode(short* arr, int size) {
    int* counter = new int[8001]();       // 입력되는 정수의 값은 4,000이 넘지 않는다.
    for(int i = 0; i < size; i++) {
        counter[arr[i]+4000]++;         // -4000 ~ +4000
    }
    int max = counter[0];
    for(int i = 0; i < 8001; i++) {
        if(max < counter[i]) {
            max = counter[i];
        }
    }
    std::vector<int> temp;
    for(int i = 0; i < 8001; i++) {
        if(max == counter[i]) {
            temp.push_back(i - 4000);
        }
    }

    if(temp.size() == 1) {
        return temp[0];
    } else {
        return temp[1];
    }
}

short range(short* arr, int size) {
    if(size == 1) {
        return 0;
    } else {    
        return arr[size-1] - arr[0];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;      // 수의 개수
    std::cin >> N;
    short* inputs = new short[N];
    for(int i = 0; i < N; i++) {
        std::cin >> inputs[i];  // 입력받기
    }
    std::sort(inputs, inputs + N);

    // 산술평균
    std::cout << arithmetic_mean(inputs, N) << "\n";
    
    // 중앙값
    std::cout << median(inputs, N) << "\n";

    // 최빈값
    std::cout << mode(inputs, N) << "\n";
    
    // 범위
    std::cout << range(inputs, N) << "\n";
}