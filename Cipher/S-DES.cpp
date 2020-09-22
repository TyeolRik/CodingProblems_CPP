#include <iostream>
#include <vector>

void print_bits(std::vector<int> input) {
    for(int i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
}

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
std::vector<int> initial_permutation_inverse(std::vector<int> input) {
    std::vector<int> ret = input;
    ret[0] = input[3];
    ret[1] = input[0];
    ret[2] = input[2];
    ret[3] = input[4];
    ret[4] = input[6];
    ret[5] = input[1];
    ret[6] = input[7];
    ret[7] = input[5];
    return ret;
}

int main() {
    std::vector<int> plaintext = { 0, 0, 1, 0, 1, 0, 0, 0 };
    std::vector<int> encrypted;
    
}