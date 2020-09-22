/*
* 강의명 : 암호알고리즘특강
* 작성자 : 백 승 록
* Coded in C++
* Compiled with G++ 9.3.0
* OS: Debian/Buster10
*/

/*
* 아래와 같은 키를 사용한 S-DES 방법으로 주어진 평문을 암호화하시오.
* 또한, 얻어진 암호문을 같은 키로 복호화하여 원래 평문이 얻어지는 것을 확인하시오.
* Plaintext : 00101000
*       Key : 1100011110
*/

#include <iostream>
#include <vector>

void print_bits(std::vector<int> input) {
    for(int i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << "\n";
}

std::vector<int> make1DvectorFrom2D(std::vector<std::vector<int>> two_dimension_vector) {
    int return_size = 0;
    for(int i = 0; i < two_dimension_vector.size(); i++) {
        return_size = return_size + two_dimension_vector[i].size();
    }
    std::vector<int> ret;
    ret.reserve(return_size);
    for(int i = 0; i < two_dimension_vector.size(); i++) {
        for(int j = 0; j < two_dimension_vector[i].size(); j++) {
            ret.push_back(two_dimension_vector[i][j]);
        }
    }
    return ret;
}

std::vector<int> P10(std::vector<int> key) {
    std::vector<int> ret = { key[2], key[4], key[1], key[6], key[3], key[9], key[0], key[8], key[7], key[5] };
    return ret;
}
std::vector<int> Left_Shift(std::vector<int> key) {
    std::vector<int> ret = { key[1], key[2], key[3], key[4], key[0], key[6], key[7], key[8], key[9], key[5] };
    return ret;
}
std::vector<int> P8(std::vector<int> key) {
    std::vector<int> ret = { key[5], key[2], key[6], key[3], key[7], key[4], key[9], key[8] };
    return ret;
}

std::vector<int> generate_K1(std::vector<int> key) {
    return P8(Left_Shift(P10(key)));
}
std::vector<int> generate_K2(std::vector<int> key) {
    return P8(Left_Shift(Left_Shift(P10(key))));
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

std::vector<int> Expansion_Permutation(std::vector<int> input) {
    if(input.size() != 4) {
        std::cout << "ERROR: input size is " << input.size() << " Not 4!\n";
        exit(-1);
    }
    std::vector<int> ret = { input[3], input[0], input[1], input[2], input[1], input[2], input[3], input[0] };
    return ret;
}

std::vector<std::vector<int>> XOR_afterEP_with_K(std::vector<int> afterEP, std::vector<int> K) {
    std::vector<int> P;
    P.reserve(8);
    for(int i = 0; i < 8; i++) {
        P.push_back(afterEP[i] ^ K[i]);
    }
    std::vector<std::vector<int>> ret = { { P[0], P[1], P[2], P[3] }, { P[4], P[5], P[6], P[7] } };
    return ret;
}

std::vector<int> S0(std::vector<int> afterXOR) {
    std::vector<std::vector<int>> S0 =     {{1, 0, 3, 2}, \
                                            {3, 2, 1, 0}, \
                                            {0, 2, 1, 3}, \
                                            {3, 1, 3, 2}};
    int row = afterXOR[0] * 2 + afterXOR[3];
    int col = afterXOR[1] * 2 + afterXOR[2];
    std::vector<int> ret = { (S0[row][col] / 2), (S0[row][col] % 2) };
    return ret;
}

std::vector<int> S1(std::vector<int> afterXOR) {
    std::vector<std::vector<int>> S1 =     {{0, 1, 2, 3}, \
                                            {2, 0, 1, 3}, \
                                            {3, 0, 1, 0}, \
                                            {2, 1, 0, 3}};
    int row = afterXOR[0] * 2 + afterXOR[3];
    int col = afterXOR[1] * 2 + afterXOR[2];
    std::vector<int> ret = { (S1[row][col] / 2), (S1[row][col] % 2) };
    return ret;
}

std::vector<int> P4(std::vector<int> afterS0, std::vector<int> afterS1) {
    std::vector<int> ret = { afterS0[0], afterS0[1], afterS1[0], afterS1[1] };
    return ret;
}

std::vector<std::vector<int>> f_k(std::vector<int> afterIP, std::vector<int> key) {
    std::vector<int> left4bits = { afterIP[0], afterIP[1], afterIP[2], afterIP[3] };
    std::vector<int> right4bits = { afterIP[4], afterIP[5], afterIP[6], afterIP[7] };

    std::vector<std::vector<int>> ret = { left4bits, right4bits };
    std::vector<std::vector<int>> temp = XOR_afterEP_with_K(Expansion_Permutation(right4bits), key);
    ret[0] = P4(S0(temp[0]), S1(temp[1]));
    ret[0] = { left4bits[0] ^ ret[0][0], left4bits[1] ^ ret[0][1], left4bits[2] ^ ret[0][2], left4bits[3] ^ ret[0][3] };
    return ret;
}

std::vector<int> S_DES_Encryption(std::vector<int> plaintext, std::vector<int> key) {
    std::vector<std::vector<int>> first_f_k1 = f_k(initial_permutation(plaintext), generate_K1(key));

    // Switch
    std::vector<int> afterSW = { first_f_k1[1][0], first_f_k1[1][1], first_f_k1[1][2], first_f_k1[1][3], first_f_k1[0][0], first_f_k1[0][1], first_f_k1[0][2], first_f_k1[0][3] };

    std::vector<std::vector<int>> second_f_k2 = f_k(afterSW, generate_K2(key));
    std::vector<int> encrypted = initial_permutation_inverse(make1DvectorFrom2D(second_f_k2));

    return encrypted;
}

std::vector<int> S_DES_Decryption(std::vector<int> encrypted, std::vector<int> key) {
    std::vector<std::vector<int>> first_f_k1 = f_k(initial_permutation(encrypted), generate_K2(key));
     
    // Switch
    std::vector<int> afterSW = { first_f_k1[1][0], first_f_k1[1][1], first_f_k1[1][2], first_f_k1[1][3], first_f_k1[0][0], first_f_k1[0][1], first_f_k1[0][2], first_f_k1[0][3] };

    std::vector<std::vector<int>> second_f_k2 = f_k(afterSW, generate_K1(key));
    std::vector<int> plaintext = initial_permutation_inverse(make1DvectorFrom2D(second_f_k2));

    return plaintext;
}

int main() {
    std::vector<int> plaintext = { 0, 0, 1, 0, 1, 0, 0, 0 };
    std::vector<int> encrypted;
    std::vector<int> key = { 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };

    std::cout << "PlainText: ";
    print_bits(plaintext);
    std::cout << "      Key: ";
    print_bits(key);
    std::cout << "Encrypted: ";
    encrypted = S_DES_Encryption(plaintext, key);
    print_bits(encrypted);
    std::cout << "Decrypted: ";
    print_bits(S_DES_Decryption(encrypted, key));
}