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

std::vector<std::string> possible_C1_C2_C3(std::vector<std::bitset<BIT_LENGTH>> left_matrix_one_row, std::bitset<BIT_LENGTH> right_matrix_one_row) {
    std::vector<std::string> possibles = { "XXXXXXXX", "XXXXXXXX", "XXXXXXXX" };
    
    for(int i = 0; i < BIT_LENGTH; i++) {
        int one_counter = 0;
        for (int j = 0; j < 3; j++) {
            if (left_matrix_one_row[j][i] == 1) {
                one_counter++;
            }
        }
        if (one_counter == 1) {
            for (int j = 0; j < 3; j++) {
                if (left_matrix_one_row[j][i] == 1) {
                    if(right_matrix_one_row[i] == 0) {
                        possibles[j][BIT_LENGTH - 1 - i] = '0';
                    } else {
                        possibles[j][BIT_LENGTH - 1 - i] = '1';
                    }
                }
            }
        }
    }
    return possibles;
}
std::vector<std::string> assemble_possibles(std::vector<std::string> possible1, std::vector<std::string> possible2, std::vector<std::string> possible3) {

    std::vector<std::string> ret = { "XXXXXXXX", "XXXXXXXX", "XXXXXXXX" };

    std::cout << "Print Input Possibles!" << std::endl;
    std::cout << "Possible1\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "C_" << (i+1) << "\t" << possible1[i] << std::endl;
    }
    std::cout << "Possible2\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "C_" << (i+1) << "\t" << possible2[i] << std::endl;
    }
    std::cout << "Possible3\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "C_" << (i+1) << "\t" << possible3[i] << std::endl;
    }

    for(int i = 0; i < BIT_LENGTH; i++) {
        for(int j = 0; j < possible1.size(); j++) {
            if(possible1[j][i] != 'X') {
                ret[j][i] = possible1[j][i];
            }
            if(possible2[j][i] != 'X') {
                ret[j][i] = possible2[j][i];
            }
            if(possible3[j][i] != 'X') {
                ret[j][i] = possible3[j][i];
            }
        }
    }

    return ret;
}

std::vector<std::vector<std::bitset<BIT_LENGTH>>> function_F(std::vector<std::vector<std::bitset<BIT_LENGTH>>> MxN, std::vector<std::vector<std::bitset<BIT_LENGTH>>> NxP) {
    std::vector<std::vector<std::bitset<BIT_LENGTH>>> MxP =   { { MxN[0][0] & NxP[0][0] | MxN[0][1] & NxP[1][0] | MxN[0][2] & NxP[2][0] }, \
                                                                { MxN[1][0] & NxP[0][0] | MxN[1][1] & NxP[1][0] | MxN[1][2] & NxP[2][0] }, \
                                                                { MxN[2][0] & NxP[0][0] | MxN[2][1] & NxP[1][0] | MxN[2][2] & NxP[2][0] } };
    return MxP;                                                                
}

std::vector<std::string> function_F_inverse(std::vector<std::vector<std::bitset<BIT_LENGTH>>> given_left_matrix, std::vector<std::vector<std::bitset<BIT_LENGTH>>> given_right_matrix) {
    std::vector<std::vector<std::string>> possibles;
    for(int i = 0; i < 3; i++) {
        possibles.push_back(possible_C1_C2_C3(given_left_matrix[i], given_right_matrix[i][0]));
    }
    return assemble_possibles(possibles[0], possibles[1], possibles[2]);
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

    std::vector<std::vector<std::bitset<BIT_LENGTH>>> correct_answer =  { { bin[13] }, \
                                                                          { bin[24] }, \
                                                                          { bin[57] } };
                                                                          
    std::vector<std::string> inverse_calculated = function_F_inverse(given_left_matrix, given_right_matrix);

    std::cout << "\nCORRECT\t\t|\tCalculated ANSWER\n";
    for(int i = 0; i < 3; i++) {
        std::cout << correct_answer[i][0] << "\t|\t" << inverse_calculated[i] << "\n";
    }
}