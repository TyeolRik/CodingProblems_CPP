// https://www.acmicpc.net/problem/10989
// Reference: https://bowbowbow.tistory.com/8
// 카운팅 정렬하기 (Counting Sort)
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;      // 수의 개수
    int temp;
    std::cin >> N;
    short* counter = new short[10000]();        // 10000 보다 작거나 같은 자연수이다.
    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        counter[temp-1]++;
    }
    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < counter[i]; j++) {
            std::cout << i+1 << '\n';
        }
    }
}