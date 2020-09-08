// https://www.acmicpc.net/problem/2869
#include <iostream>
#include <math.h>

int main() {
    int A, B, V;
    std::cin >> A >> B >> V;
    
    // n 일에 도착한다고 쳤을 때,
    // V <= A * n - B * (n-1)
    // V <= An-Bn + B
    // (V - B) / (A - B) <= n
    std::cout << (int)ceil((double)(V - B) / (double)(A - B));
}