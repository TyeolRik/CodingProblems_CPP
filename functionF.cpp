#include <iostream>
#include <vector>
#include <bitset>
#include <random>
#include <cmath>
#include <map>

#define BITSIZE     8

const std::vector<std::vector<int>> problem_matrix = {{12, 10, 100}, \
                                                      {10, 12, 200}, \
                                                      {12, 11, 200}};

const std::vector<int> answer = {44, 8, 12};

template<std::size_t N>
void pretty_print(std::bitset<N> target) {
    std::cout << target << "\t" << target.to_ullong() << "\n";
}

int GetNumberOfDontCare(std::string input) {
    int ret = 0;
    for(int i = 0; i < input.size(); i++) {
        if(input.at(i) == 'X') {
            ret++;
        }
    }
    return ret;
}
int GetNumberOfSurvive(std::string input) {
    int ret = 0;
    for(int i = 0; i < input.size(); i++) {
        if(input.at(i) == 'S') {
            ret++;
        }
    }
    return ret;
}

std::vector<int> function(int A, int B, int C) {
    std::vector<int> ret;
    for(int row = 0; row < problem_matrix.size(); row++) {
        ret.push_back((A & problem_matrix.at(row).at(0)) | (B & problem_matrix.at(row).at(1)) | (C & problem_matrix.at(row).at(2)));
    }
    return ret;
}

std::vector<int> function(std::string inputA, std::string inputB, std::string inputC) {
    int A = std::bitset<BITSIZE>(inputA).to_ulong();
    int B = std::bitset<BITSIZE>(inputB).to_ulong();
    int C = std::bitset<BITSIZE>(inputC).to_ulong();

    std::vector<int> ret;
    for(int row = 0; row < problem_matrix.size(); row++) {
        ret.push_back((A & problem_matrix.at(row).at(0)) | (B & problem_matrix.at(row).at(1)) | (C & problem_matrix.at(row).at(2)));
    }
    return ret;
}

std::vector<std::string> combination(std::vector<std::vector<std::string>> results) {
    int output_count = results.at(0).size();
    std::vector<std::string> ret;
    ret.reserve(output_count);

    //std::cout << results.at(0).at(0) << "\t" << results.at(0).at(1) << "\t" << results.at(0).at(2) << "\n";
    //std::cout << results.at(1).at(0) << "\t" << results.at(1).at(1) << "\t" << results.at(1).at(2) << "\n";
    //std::cout << results.at(2).at(0) << "\t" << results.at(2).at(1) << "\t" << results.at(2).at(2) << "\n";
    

    for(int each = 0; each < output_count; each++) {
        std::string possible(BITSIZE, 'X');
        for(int guess = 0; guess < results.size(); guess++) {
            for(int bit_index = 0; bit_index < BITSIZE; bit_index++) {\
                if(possible.at(bit_index) == results.at(guess).at(each).at(bit_index) || results.at(guess).at(each).at(bit_index) == 'X') {

                } else if(possible.at(bit_index) == 'X') {
                    possible.at(bit_index) = results.at(guess).at(each).at(bit_index);
                } else if(possible.at(bit_index) == 'S' && results.at(guess).at(each).at(bit_index) == 'X') {

                } else if(possible.at(bit_index) == 'S' && (results.at(guess).at(each).at(bit_index) == '0' || results.at(guess).at(each).at(bit_index) == '1')) {
                    possible.at(bit_index) = results.at(guess).at(each).at(bit_index);
                } else {
                    std::cout << "Collsion Occured!\nAlready: " << possible.at(bit_index) << "\nBut: " << results.at(guess).at(each).at(bit_index) << "\n";
                    exit(-1);
                }
            }
        }
        ret.push_back(possible);
    }
    return ret;
}
std::vector<std::string> f_inverse(std::vector<int> given_coefficient, int given_answer) {
    std::vector<std::bitset<BITSIZE>> bit_coefs;
    std::vector<std::string> bit_rets;
    std::bitset<BITSIZE> bit_answer = given_answer;
    bit_coefs.reserve(given_coefficient.size());
    bit_rets.reserve(given_coefficient.size());
    for(int i = 0; i < given_coefficient.size(); i++) {
        bit_coefs.push_back(std::bitset<BITSIZE>(given_coefficient.at(i)));
        bit_rets.push_back(std::string(BITSIZE, 'X'));
    }

    for(int index = 0; index < BITSIZE; index++) {
        if(bit_answer[index] == 0) {
            for(int each = 0; each < bit_coefs.size(); each++) {
                if(bit_coefs.at(each)[index] == 1) {
                    bit_rets.at(each).at(BITSIZE - index - 1) = '0';
                }
            }
        } else {        // bit_answer[index] == 1
            // Count 1 bits
            int one_bit_count = 0;
            for(int i = 0; i < bit_coefs.size(); i++) {
                one_bit_count = one_bit_count + (int)bit_coefs.at(i)[index];
            }
            if(one_bit_count == 1) {
                for(int each = 0; each < bit_coefs.size(); each++) {
                    if(bit_coefs.at(each)[index] == 1) {
                        bit_rets.at(each).at(BITSIZE - index - 1) = '1';
                    }
                }
            } else if(one_bit_count == 2) { // Survive Condition
                for(int each = 0; each < bit_coefs.size(); each++) {
                    if(bit_coefs.at(each)[index] == 1) {
                        bit_rets.at(each).at(BITSIZE - index - 1) = 'S';
                    }
                }
            } else {    // one_bit_count == 3
                for(int each = 0; each < bit_coefs.size(); each++) {
                    if(bit_coefs.at(each)[index] == 1) {
                        bit_rets.at(each).at(BITSIZE - index - 1) = 'S';
                    }
                }
            }
        }
    }
    return bit_rets;
}

void random_test(std::vector<std::string> possibles, std::vector<int> wanted) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);

    std::vector<int> int_possibles;
    int_possibles.reserve(possibles.size());

    for(int i = 0; i < 10000; i++) {
        // Don't care input X
        for(int each = 0; each < possibles.size(); each++) {
            std::string eachString = possibles.at(each);
            for(int idx = 0; idx < eachString.size(); idx++) {
                if(eachString.at(idx) == 'X') {
                    eachString.at(idx) = (char)(dis(gen) + '0');
                    std::cout << "dis(gen): " << dis(gen) << "\n";
                }
            }
            int_possibles.push_back(std::bitset<BITSIZE>(eachString).to_ulong());
        }
        std::vector<int> result = function(int_possibles.at(0), int_possibles.at(1), int_possibles.at(2));
        for(int i = 0; i < result.size(); i++) {
            if(result.at(i) != answer.at(i)) {
                std::cout << "Input 1: ";
                pretty_print(std::bitset<BITSIZE>(int_possibles.at(0)));
                std::cout << "Input 2: ";
                pretty_print(std::bitset<BITSIZE>(int_possibles.at(1)));
                std::cout << "Input 3: ";
                pretty_print(std::bitset<BITSIZE>(int_possibles.at(2)));
                std::cout << "FAILED\nCalculated result: ";
                pretty_print(std::bitset<BITSIZE>(result.at(i)));
                std::cout << "Correct answer: ";
                pretty_print(std::bitset<BITSIZE>(answer.at(i)));
                exit(-1);
            }
        }
    }
    std::cout << "SUCCESS!\n";
}

template<std::size_t N>
std::string intercalateCertainsBetweenDontcare(std::string withDontCare, std::bitset<N> target, int originalTargetBitSize) {
    if(GetNumberOfDontCare(withDontCare) != originalTargetBitSize) {
        std::cout << "ERROR :: intercalateCertainsBetweenDontcare : Could occur error because of bit shift\n";
        std::cout << "The Number of Don't care: " << GetNumberOfDontCare(withDontCare) << "\n";
        std::cout << "originalTargetSize: " << originalTargetBitSize << "\n";
    }
    // std::cout << "intercalateCertainsBetweenDontcare\n";
    // std::cout << " Input: " << withDontCare << "\n";
    // std::cout << "target: " << target << "\n";
    // std::cout << "originalTargetBitSize: " << originalTargetBitSize << "\n";
    std::string temp = target.to_string();
    // std::cout << "Carget: " << temp.substr(temp.size() - originalTargetBitSize, originalTargetBitSize) << "\n";
    temp = temp.substr(temp.size() - originalTargetBitSize, originalTargetBitSize);
    // std::cout << temp << "\n";
    for(int i = 0; i < withDontCare.size(); i++) {
        if(withDontCare.at(i) != 'X') {
            temp.insert(i, 1, withDontCare.at(i));
        }
    }
    temp.substr(temp.size() - BITSIZE, BITSIZE);
    return temp;
}

std::vector<std::string> GenerateAllPossibility(std::string withDontCare) {
    //std::cout << "Generating All Possibilities\n";
    //std::cout << "Input Data which has Don't care: " << withDontCare << "\n";
    int theNumberOfDontCare = GetNumberOfDontCare(withDontCare);
    std::vector<std::string> ret(std::pow(2, theNumberOfDontCare));
    for(int i = 0; i < ret.size(); i++) {
        ret.at(i) = intercalateCertainsBetweenDontcare(withDontCare, std::bitset<BITSIZE>(i), theNumberOfDontCare);
    }
    return ret;
}
std::vector<std::string> GenerateSurvivePossibility(std::string withSurvive) {
    std::vector<std::string> ret;
    ret.reserve(std::pow(2, GetNumberOfSurvive(withSurvive)));
    
    std::bitset<BITSIZE> data;
    for(int i = 0; i < std::pow(2, GetNumberOfSurvive(withSurvive)); i++) {
        data = i;
        std::string temp = withSurvive;
        for(int j = 0; j < GetNumberOfSurvive(withSurvive); j++) {
            for(int stringindex = 0; stringindex < withSurvive.size(); stringindex++) {
                if(temp.at(stringindex) == 'S') {
                    temp.at(stringindex) = data[j] + '0';
                    break;
                }
            }
        }
        ret.push_back(temp);
    }
    
    /*
    std::cout << "GenerateSurvivePossibility\n";
    for(int i = 0; i < ret.size(); i++) {
        std::cout << ret.at(i) << "\n";
    }
    */
    return ret;
}

bool doesMeetConditions(std::string input1, std::string input2, std::string input3, std::vector<std::vector<std::string>> possibles) {
    std::vector<std::string> group = {input1, input2, input3};
    for(int i = 0; i < possibles.size(); i++) {
        for(int bitindex = 0; bitindex < BITSIZE; bitindex++) {
            if(possibles.at(i).at(0).at(bitindex) == 'S' || possibles.at(i).at(1).at(bitindex) == 'S' || possibles.at(i).at(2).at(bitindex) == 'S') {
                int survived = 0;
                for(int j = 0; j < possibles.at(i).size(); j++) {
                    if((possibles.at(i).at(j).at(bitindex) == 'S') && (group.at(j).at(bitindex) == '1')) {
                        survived++;
                    }
                }
                if(survived == 0) {
                    return false;
                }
            }
            
        }
    }
    return true;
}

bool doesMeetConditions(std::string input1, std::string input2, std::string input3, std::string conditionWithSurvive1, std::string conditionWithSurvive2, std::string conditionWithSurvive3) {
    if(input1.size() != input2.size() || input2.size() != input3.size()) {
        std::cout << "Doesn't meet conditions :: input string size is different!\n";
        exit(-1);
    }
    for(int i = 0; i < input1.size(); i++) {
        if(conditionWithSurvive1.at(i) == 'S' || conditionWithSurvive2.at(i) == 'S' || conditionWithSurvive3.at(i) == 'S') {
            if(input1.at(i) == '0' && input2.at(i) == '0' && input3.at(i) == '0') {
                //std::cout << "Input1: " << input1 << " Input2: " << input2 << " Input3: " << input3 << "\n";
                //std::cout << "conditionWithSurvive1: " << conditionWithSurvive1 << " conditionWithSurvive2: " << conditionWithSurvive2 << " conditionWithSurvive3: " << conditionWithSurvive3 << "\n";
                return false;
            }
        }
    }
    return true;
}
/**
 * C1: XXXXS10X
 * C2: XXXXS000
 * C3: 001XSSXX
 * 
 */
void test_bruteforce(std::vector<std::string> possible_C1, std::vector<std::string> possible_C2, std::vector<std::string> possible_C3) {
    unsigned int testCount = 0;
    for(int indexC1 = 0; indexC1 < possible_C1.size(); indexC1++) {
        for(int indexC2 = 0; indexC2 < possible_C2.size(); indexC2++) {
            for(int indexC3 = 0; indexC3 < possible_C3.size(); indexC3++) {
                std::string C1 = possible_C1.at(indexC1);
                std::string C2 = possible_C2.at(indexC2);
                std::string C3 = possible_C3.at(indexC3);

                std::vector<std::string> C1_noneS = GenerateSurvivePossibility(C1);
                std::vector<std::string> C2_noneS = GenerateSurvivePossibility(C2);
                std::vector<std::string> C3_noneS = GenerateSurvivePossibility(C3);
                
                for(int i = 0; i < C1_noneS.size(); i++) {
                    for(int j = 0; j < C2_noneS.size(); j++) {
                        for(int k = 0; k < C3_noneS.size(); k++) {
                            /*
                            if(doesMeetConditions(C1_noneS.at(i), C2_noneS.at(j), C3_noneS.at(k), C1, C2, C3)) {
                                testCount++;
                                std::vector<int> ret = function(C1_noneS.at(i), C2_noneS.at(j), C3_noneS.at(k));
                                if(ret.at(0) == answer.at(0) && ret.at(1) == answer.at(1) && ret.at(2) == answer.at(2)) {

                                } else {
                                    std::cout << "ERROR Found!\n";
                                    std::cout << "Calulated Function:: " << ret.at(0) << " " << ret.at(1) << " " << ret.at(2) << "\n";
                                    std::cout << "    Correct Answer:: " << answer.at(0) << " " << answer.at(1) << " " << answer.at(2) << "\n";
                                    std::cout << "C1: " << C1_noneS.at(i) << "\t" << std::bitset<BITSIZE>(C1_noneS.at(i)).to_ulong() << "\n";
                                    std::cout << "C2: " << C2_noneS.at(j) << "\t" << std::bitset<BITSIZE>(C2_noneS.at(j)).to_ulong() << "\n";
                                    std::cout << "C3: " << C3_noneS.at(k) << "\t" << std::bitset<BITSIZE>(C3_noneS.at(k)).to_ulong() << "\n";
                                }
                            }
                            */
                        }
                    }
                }
            }
        }
    }
    std::cout << "Brute Force Test Complete!\nThe Number of Test Case: " << testCount << "\n";
}

void test_bruteforce(std::vector<std::string> possible_C1, std::vector<std::string> possible_C2, std::vector<std::string> possible_C3, std::vector<std::vector<std::string>> possibles) {
    unsigned int testCount = 0;
    for(int indexC1 = 0; indexC1 < possible_C1.size(); indexC1++) {
        for(int indexC2 = 0; indexC2 < possible_C2.size(); indexC2++) {
            for(int indexC3 = 0; indexC3 < possible_C3.size(); indexC3++) {
                std::string C1 = possible_C1.at(indexC1);
                std::string C2 = possible_C2.at(indexC2);
                std::string C3 = possible_C3.at(indexC3);

                std::vector<std::string> C1_noneS = GenerateSurvivePossibility(C1);
                std::vector<std::string> C2_noneS = GenerateSurvivePossibility(C2);
                std::vector<std::string> C3_noneS = GenerateSurvivePossibility(C3);
                
                for(int i = 0; i < C1_noneS.size(); i++) {
                    for(int j = 0; j < C2_noneS.size(); j++) {
                        for(int k = 0; k < C3_noneS.size(); k++) {
                            if(doesMeetConditions(C1_noneS.at(i), C2_noneS.at(j), C3_noneS.at(k), possibles)) {
                                testCount++;
                                std::vector<int> ret = function(C1_noneS.at(i), C2_noneS.at(j), C3_noneS.at(k));
                                if(ret.at(0) == answer.at(0) && ret.at(1) == answer.at(1) && ret.at(2) == answer.at(2)) {
                                    std::cout << "C1: " << C1_noneS.at(i) << "\tC2: " << C2_noneS.at(j) << "\tC3: " << C3_noneS.at(k) << "\n";
                                } else {
                                    std::cout << "ERROR Found!\n";
                                    std::cout << "Calulated Function:: " << ret.at(0) << " " << ret.at(1) << " " << ret.at(2) << "\n";
                                    std::cout << "    Correct Answer:: " << answer.at(0) << " " << answer.at(1) << " " << answer.at(2) << "\n";
                                    std::cout << "C1: " << C1_noneS.at(i) << "\t" << std::bitset<BITSIZE>(C1_noneS.at(i)).to_ulong() << "\n";
                                    std::cout << "C2: " << C2_noneS.at(j) << "\t" << std::bitset<BITSIZE>(C2_noneS.at(j)).to_ulong() << "\n";
                                    std::cout << "C3: " << C3_noneS.at(k) << "\t" << std::bitset<BITSIZE>(C3_noneS.at(k)).to_ulong() << "\n";
                                }
                            }
                            /*
                            if(doesMeetConditions(C1_noneS.at(i), C2_noneS.at(j), C3_noneS.at(k), C1, C2, C3)) {
                                testCount++;
                                std::vector<int> ret = function(C1_noneS.at(i), C2_noneS.at(j), C3_noneS.at(k));
                                if(ret.at(0) == answer.at(0) && ret.at(1) == answer.at(1) && ret.at(2) == answer.at(2)) {

                                } else {
                                    std::cout << "ERROR Found!\n";
                                    std::cout << "Calulated Function:: " << ret.at(0) << " " << ret.at(1) << " " << ret.at(2) << "\n";
                                    std::cout << "    Correct Answer:: " << answer.at(0) << " " << answer.at(1) << " " << answer.at(2) << "\n";
                                    std::cout << "C1: " << C1_noneS.at(i) << "\t" << std::bitset<BITSIZE>(C1_noneS.at(i)).to_ulong() << "\n";
                                    std::cout << "C2: " << C2_noneS.at(j) << "\t" << std::bitset<BITSIZE>(C2_noneS.at(j)).to_ulong() << "\n";
                                    std::cout << "C3: " << C3_noneS.at(k) << "\t" << std::bitset<BITSIZE>(C3_noneS.at(k)).to_ulong() << "\n";
                                }
                            }
                            */
                        }
                    }
                }
            }
        }
    }
    std::cout << "Brute Force Test Complete!\nThe Number of Test Case: " << testCount << "\n";
}

int main() {
    srand(time(NULL));
    std::vector<int> solution = {13, 24, 57};
    std::vector<int> ret = function(solution.at(0), solution.at(1), solution.at(2));
    std::cout << ret.at(0) << "\t" << ret.at(1) << "\t" << ret.at(2)  << "\n";

    std::vector<std::vector<std::string>> possibles;
    possibles.reserve(3);

    for(int i = 0; i < 3; i++) {
        possibles.push_back(f_inverse(problem_matrix.at(i), answer.at(i)));
    }
    std::vector<std::string> withDontcare = combination(possibles);
    std::cout << "C1: " << withDontcare.at(0) << "\n";
    std::cout << "C2: " << withDontcare.at(1) << "\n";
    std::cout << "C3: " << withDontcare.at(2) << "\n";

    std::vector<std::string> C1Possibles = GenerateAllPossibility(withDontcare.at(0));
    std::vector<std::string> C2Possibles = GenerateAllPossibility(withDontcare.at(1));
    std::vector<std::string> C3Possibles = GenerateAllPossibility(withDontcare.at(2));

    test_bruteforce(C1Possibles, C2Possibles, C3Possibles, possibles);
    // test_bruteforce(C1Possibles, C2Possibles, C3Possibles);
    /*
    std::cout << "C1 Possibles :: Size: " << C1Possibles.size() << "\n";
    for(int i = 0; i < C1Possibles.size(); i++) {
        std::cout << C1Possibles.at(i) << "\n";
    }
    std::cout << "C2 Possibles :: Size: " << C2Possibles.size() << "\n";
    for(int i = 0; i < C2Possibles.size(); i++) {
        std::cout << C2Possibles.at(i) << "\n";
    }
    std::cout << "C3 Possibles :: Size: " << C3Possibles.size() << "\n";
    for(int i = 0; i < C3Possibles.size(); i++) {
        std::cout << C3Possibles.at(i) << "\n";
    }
    */

    // random_test(withDontcare, answer);
    
    /* Dont forget Test case
    std::string test = "00000011";
    std::bitset<BITSIZE> bittest(test);
    std::cout << bittest << "\t" << bittest.to_ullong() << "\n";        // Returns: 00000011        3
    */
}