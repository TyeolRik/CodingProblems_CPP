#include <iostream>
#include <vector>
#include <bitset>

#define BIT_LENGTH     8

void print_bitset(std::bitset<BIT_LENGTH> target) {
    std::cout << target.to_ulong() << "\t: " << target << "\n";
}

std::string newBitString(int a) {
    std::bitset<BIT_LENGTH> __binary(a);
    std::string ret = __binary.to_string();
    return ret;
}

std::vector<std::bitset<BIT_LENGTH>> possible_C1_C2_C3(std::vector<std::bitset<BIT_LENGTH>> left_matrix_one_row, std::bitset<BIT_LENGTH> right_matrix_one_row) {
    std::vector<std::bitset<BIT_LENGTH>> possibles(3);
    for(int i = 0; i < BIT_LENGTH; i++) {
        if(right_matrix_one_row[i] == 0) {
            int one_counter = 0;
            for(int j = 0; j < BIT_LENGTH; j++) {
                if(left_matrix_one_row[i][j] == 1) {
                    one_counter++;
                }
            }
            if(one_counter == 1) {
                
            }

        }
    }
    return possibles;
}

std::vector<std::vector<std::bitset<BIT_LENGTH>>> function_F(std::vector<std::vector<std::bitset<BIT_LENGTH>>> MxN, std::vector<std::vector<std::bitset<BIT_LENGTH>>> NxP) {
    std::vector<std::vector<std::bitset<BIT_LENGTH>>> MxP =   { { MxN[0][0] & NxP[0][0] | MxN[0][1] & NxP[1][0] | MxN[0][2] & NxP[2][0] }, \
                                                                { MxN[1][0] & NxP[0][0] | MxN[1][1] & NxP[1][0] | MxN[1][2] & NxP[2][0] }, \
                                                                { MxN[2][0] & NxP[0][0] | MxN[2][1] & NxP[1][0] | MxN[2][2] & NxP[2][0] } };
    return MxP;                                                                
}

int main() {
    std::vector<std::bitset<BIT_LENGTH>> bin;
    bin.reserve(256);
    for(int i = 0; i < 256; i++) {
        std::bitset<BIT_LENGTH> temp(i);
        bin.push_back(temp);
    }

    std::vector<std::vector<std::bitset<BIT_LENGTH>>> given_left_matrix = { {bin[12], bin[10], bin[100]   }, \
                                                                            {bin[10], bin[12], bin[200]   }, \
                                                                            {bin[12], bin[11], bin[200]   } };

    std::vector<std::vector<std::bitset<BIT_LENGTH>>> given_right_matrix = { { bin[44] },\
                                                                             { bin[8] },\
                                                                             { bin[12] } };
/* 정답지
    std::vector<std::vector<std::bitset<BIT_LENGTH>>> correct_answer =  { { bin[13] }, \
                                                                          { bin[24] }, \
                                                                          { bin[57] } };
*/


}