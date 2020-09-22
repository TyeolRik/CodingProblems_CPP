#include <iostream>
#include <vector>

std::vector<int> initial_permutation(std::vector<int> input) {
    std::vector<int> ret = input;
    ret[0] = input[1];
    ret[1] = input[5];
    ret[2] = input[2];
    ret[3] = input[0];
    ret[4] = input[3];
    ret[5] = input[7];
    ret[6] = input[4];
    ret[7] = input[6];
    return ret;
}

int main() {
    std::vector<int> plaintext = { 0, 0, 1, 0, 1, 0, 0, 0 };



}