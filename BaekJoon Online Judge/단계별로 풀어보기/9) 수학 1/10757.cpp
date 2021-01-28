// https://www.acmicpc.net/problem/10757
#include <iostream>
#include <vector>
#include <algorithm>

std::string stringADD(std::string a, std::string b) {
    std::string ret;

    int sizeA = a.size();
    int sizeB = b.size();
    int lastIndex;
    if(sizeA > sizeB) {
        lastIndex = sizeA;
        ret.reserve(lastIndex+1);
        b.insert(0, sizeA-sizeB, '0');
    } else {
        lastIndex = sizeB;
        a.insert(0, sizeB-sizeA, '0');
    }

    char left = 0;
    char carry = 0;
    while(lastIndex --> 0) {
        char up = a[lastIndex] - '0';
        char down = b[lastIndex] - '0';
        left = up + down + carry;
        if(left >= 10) {
            left = left - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        ret.push_back(left + '0');
    }
    if(carry == 1) {
        ret.push_back('1');
    }

    std::reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
    std::string A, B;
    std::cin >> A;
    std::cin >> B;

    std::cout << stringADD(A, B);
}