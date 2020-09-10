// https://www.acmicpc.net/problem/1011
#include <iostream>
#include <math.h>

/*
Pattern
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
*/

long long test2(long long length) {
    int temp = floor(sqrt(length - 1));
    // std::cout << "Input: " << length << "\t\t" << temp * temp << " AND " << temp*temp + temp << " AND " << (temp + 1) * (temp + 1) << "\n";
    if(temp * temp < length && length <= temp*temp + temp) {
        return 2 * temp;
    } else {
        return 2 * temp + 1;
    }
}

long long test(long long length) {
    double odd_min = sqrt(4 * length) - 1;
    /*
    double odd_max = 2 * sqrt(length);
    double even_min = (-2 + sqrt(16 * length + 4)) / (double)2.0;
    double even_max = sqrt(4 * length + 1);
    std::cout << "홀: " << odd_min << " ~ " << odd_max << "\n";
    std::cout << "짝: " << even_min << " ~ " << even_max << "\n";
    */
    return (long long)floor(odd_min);
}

long long length_to_hop(long long length) {

    long long before_n = 3;
    long long x = 3;
    long long n = 3;

    while(true) {
        if(length == n) {
            return x - 1;
        } else if(length < n) {
            return x - 1;
        } else {
            before_n = n;
            if (x % 2 == 0) {
                n = x / 2 * (2 + x) / 2;
            } else {
                n = ((x + 1) / 2) * (1 + x) / 2;
            }
            // std::cout << "before_n: " << before_n << "\tx: " << x << "\tn: " << n << "\n";
            x++;
        }
    }
}

int main() {
    long long T, x, y;
    std::cin >> T;
    while(T --> 0) {
        std::cin >> x >> y;
        long long length = y - x;
        if(length <= 3) {
            std::cout << length << "\n";
        } else {
            std::cout << length_to_hop(length) << "\n";
        }
    }
}