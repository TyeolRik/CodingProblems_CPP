/*
* 강의명 : 암호알고리즘특강
* 작성자 : 백 승 록
* Coded in C++
* Compiled with G++ 9.3.0
* OS: Debian/Buster10
*/

/*
* DES 내용을 이해한 후 DES 암호화 프로그램을 작성해 보십시오.
* Plaintext: 123456ABCD132536
* Key      : AABB09182736CCDD

* Reference : http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm
*/

#include <iostream>
#include <vector>
#include <bitset>       // 비트 표현
#include <algorithm>
#include <sstream>      // To Hexadecimal

void print_bitset_pretty(std::bitset<64> input) {
    for(int i = 0; i < 64; i++) {
        if(i % 4 == 0) {
            std::cout << " ";
        }
        std::cout << input[i];
    }
    std::cout << "\n";
}

void print_bitset_pretty(std::bitset<56> input) {
    for(int i = 0; i < 56; i++) {
        if(i % 7 == 0) {
            std::cout << " ";
        }
        std::cout << input[i];
    }
    std::cout << "\n";
}

void print_bitset_pretty(std::bitset<48> input) {
    for(int i = 0; i < 48; i++) {
        if(i % 6 == 0) {
            std::cout << " ";
        }
        std::cout << input[i];
    }
    std::cout << "\n";
}

void print_bitset_pretty(std::bitset<32> input) {
    for(int i = 0; i < 32; i++) {
        if(i % 4 == 0) {
            std::cout << " ";
        }
        std::cout << input[i];
    }
    std::cout << "\n";
}

void print_bitset_pretty(std::bitset<28> input) {
    for(int i = 0; i < 28; i++) {
        if(i % 7 == 0) {
            std::cout << " ";
        }
        std::cout << input[i];
    }
    std::cout << "\n";
}

class DES {
    private:
    std::bitset<64> _plaintext;
    std::bitset<56> _key;
    std::bitset<64> _encrypted_message;

    const std::vector<int> Shift_Schedule_of_Keys = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    const std::vector<int> Key_Compression_Permutation_left  = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2};
    const std::vector<int> Key_Compression_Permutation_right = {41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};

    const std::vector<int> Expansion_Permutation_Table = {32,  1,  2,  3,  4,  5,\
                                                           4,  5,  6,  7,  8,  9,\
                                                           8,  9, 10, 11, 12, 13,\
                                                          12, 13, 14, 15, 16, 17,\
                                                          16, 17, 18, 19, 20, 21,\
                                                          20, 21, 22, 23, 24, 25,\
                                                          24, 25, 26, 27, 28, 29,\
                                                          28, 29, 30, 31, 32,  1};
    const std::vector<std::vector<int>> S_Box = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                                                  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                                                  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                                                  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},
                                                 {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                                                  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                                                  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                                                  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
                                                 {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                                                  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                                                  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                                                  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
                                                 {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                                                  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                                                  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                                                  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
                                                 {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                                                  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                                                  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                                                  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},
                                                 {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                                                  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                                                  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                                                  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
                                                 {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                                                  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                                                  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                                                  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
                                                 {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                                                  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                                                  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                                                  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};
    const std::vector<int> Permutation_table = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};

    /**
     * @brief One char is 4 bits in Hexadecimal
     */
    std::bitset<64> ASCIIstring_to_bitset(std::string input) {
        std::bitset<64> output;
        int temp_index = 0;
        for(int i = 0; i < input.size(); i++) {
            std::bitset<4> char_bitarray = char_to_bitset4((input.at(i)));

            output[temp_index++] = char_bitarray[3];
            output[temp_index++] = char_bitarray[2];
            output[temp_index++] = char_bitarray[1];
            output[temp_index++] = char_bitarray[0];

            //print_bitset_pretty(output);
        }
        int less_size = 16 - input.size();
        if(less_size > 0) {
            // Padding Technique: PKCS5
            for(int i = 0; i < less_size; i++) {
                std::bitset<4> char_bitarray = less_size;
                for(int j = 0; j < 4; j++) {
                    output[temp_index++] = char_bitarray[j];
                }
                //print_bitset_pretty(output);
            }
        }
        

        return output;
    }
    std::bitset<4> char_to_bitset4(char input) {
        std::bitset<4> ret;
        switch (input)
        {
        case '0':
            ret = 0;
            break;
        
        case '1':
            ret = 1;
            break;
            
        case '2':
            ret = 2;
            break;
            
        case '3':
            ret = 3;
            break;
            
        case '4':
            ret = 4;
            break;
            
        case '5':
            ret = 5;
            break;
            
        case '6':
            ret = 6;
            break;
            
        case '7':
            ret = 7;
            break;
            
        case '8':
            ret = 8;
            break;
            
        case '9':
            ret = 9;
            break;
            
        case 'A':
            ret = 10;
            break;
            
        case 'a':
            ret = 10;
            break;

        case 'B':
            ret = 11;
            break;
            
        case 'b':
            ret = 11;
            break;
            
        case 'C':
            ret = 12;
            break;
            
        case 'c':
            ret = 12;
            break;
            
        case 'D':
            ret = 13;
            break;

        case 'd':
            ret = 13;
            break;

        case 'E':
            ret = 14;
            break;

        case 'e':
            ret = 14;
            break;

        case 'F':
            ret = 15;
            break;

        case 'f':
            ret = 15;
            break;

        default:
            std::cout << "ERROR. This is not Hexadecimal. Input: " << input << "\n";
            exit(-1);
            break;
        }
        return ret;
    }
    char uint_to_char(unsigned int input) {
        switch (input)
        {
        case 0:
            return '0';
            break;
            
        case 1:
            return '1';
            break;
            
        case 2:
            return '2';
            break;
            
        case 3:
            return '3';
            break;
            
        case 4:
            return '4';
            break;
            
        case 5:
            return '5';
            break;
            
        case 6:
            return '6';
            break;
            
        case 7:
            return '7';
            break;
            
        case 8:
            return '8';
            break;
            
        case 9:
            return '9';
            break;
            
        case 10:
            return 'A';
            break;
            
        case 11:
            return 'B';
            break;
            
        case 12:
            return 'C';
            break;
            
        case 13:
            return 'D';
            break;
            
        case 14:
            return 'E';
            break;
            
        case 15:
            return 'F';
            break;
        
        default:
            std::cout << "Input is not Hexadecimal (0 ~ 15). Input was " << input << "\n";
            exit(-1);
            break;
        }
    }

    std::bitset<64> InitialPermutation(std::bitset<64> target) {
        std::bitset<64> ret;
        std::vector<int> table = {58, 50, 42, 34, 26, 18, 10, 2,\
                                  60, 52, 44, 36, 28, 20, 12, 4,\
                                  62, 54, 46, 38, 30, 22, 14, 6,\
                                  64, 56, 48, 40, 32, 24, 16, 8,\
                                  57, 49, 41, 33, 25, 17,  9, 1,\
                                  59, 51, 43, 35, 27, 19, 11, 3,\
                                  61, 53, 45, 37, 29, 21, 13, 5,\
                                  63, 55, 47, 39, 31, 23, 15, 7};
        for(int i = 0; i < 64; i++) {
            ret[i] = target[table.at(i) - 1];
        }
        return ret;
    }
    std::bitset<64> Inverse_of_InitialPermutation(std::bitset<64> target) {
        std::bitset<64> ret;
        std::vector<int> table = {40, 8, 48, 16, 56, 24, 64, 32,\
                                  39, 7, 47, 15, 55, 23, 63, 31,\
                                  38, 6, 46, 14, 54, 22, 62, 30,\
                                  37, 5, 45, 13, 53, 21, 61, 29,\
                                  36, 4, 44, 12, 52, 20, 60, 28,\
                                  35, 3, 43, 11, 51, 19, 59, 27,\
                                  34, 2, 42, 10, 50, 18, 58, 26,\
                                  33, 1, 41,  9, 49, 17, 57, 25};
        for(int i = 0; i < 64; i++) {
            ret[i] = target[table.at(i) - 1];
        }
        return ret;
    }

    std::bitset<56> KeyPermutation(std::bitset<64> input_key) {
        std::bitset<56> ret;
        std::vector<int> table = {57, 49, 41, 33, 25, 17,  9,\
                                   1, 58, 50, 42, 34, 26, 18,\
                                  10,  2, 59, 51, 43, 35, 27,\
                                  19, 11,  3, 60, 52, 44, 36,\
                                  63, 55, 47, 39, 31, 23, 15,\
                                   7, 62, 54, 46, 38, 30, 22,\
                                  14,  6, 61, 53, 45, 37, 29,\
                                  21, 13,  5, 28, 20, 12, 4};

        for(int i = 0; i < 56; i++) {
            ret[i] = input_key[table[i] - 1];
        }
        return ret;
    }

    std::vector<std::bitset<32>> OneRound(std::bitset<32> left, std::bitset<32> right, int now_round) {
        
        std::bitset<48> afterExpansion = Expansion_Permutation(right);      // Expansion and Permutation with E table
        std::bitset<48> now_round_key = KeyGenerate(now_round);
        
        std::bitset<48> afterXOR = afterExpansion ^ now_round_key;          // XOR
        
        std::bitset<32> after_S_BOX = S_box_Substitution(afterXOR);         // S-Box Calculation
        std::bitset<32> after_Permutation = Permutation(after_S_BOX);       // Permutation
        std::bitset<32> last_XOR = left ^ after_Permutation;

        std::bitset<32> new_left = right;
        std::bitset<32> new_right = last_XOR;

        std::vector<std::bitset<32>> ret = {new_left, new_right};
        return ret;
    }

    std::bitset<48> KeyGenerate(int now_round) {

        // Now round starts from 0. (1 is 0, 2 is 1 etc..)
        std::bitset<28> left;
        std::bitset<28> right;

        for(int i = 0; i < 28; i++) {
            left[i] = _key[i];
            right[i] = _key[i+28];
        }

        // Left Shift according to Shift Schedule of Keys
        left  = (left  >> Shift_Schedule_of_Keys.at(now_round)) | (left  << (28 - Shift_Schedule_of_Keys.at(now_round)));
        right = (right >> Shift_Schedule_of_Keys.at(now_round)) | (right << (28 - Shift_Schedule_of_Keys.at(now_round)));
        
        // Saving Left Rotate Shift.
        for(int i = 0; i < 28; i++) {
            _key[i] = left[i];
            _key[i+28] = right[i];
        }

        std::bitset<48> generated_key;

        for(int i = 0; i < 24; i++) {
            generated_key[i]      = _key[Key_Compression_Permutation_left.at(i)  - 1];
            generated_key[i + 24] = _key[Key_Compression_Permutation_right.at(i) - 1];
        }

        return generated_key;
    }
    std::bitset<48> Expansion_Permutation(std::bitset<32> right) {
        std::bitset<48> ret;
        for(int i = 0; i < 48; i++) {
            ret[i] = right[Expansion_Permutation_Table[i] - 1];
        }
        return ret;
    }

    std::bitset<32> S_box_Substitution(std::bitset<48> input) {
        std::bitset<32> ret;
        int temp = 0;
        for(int index = 0; index < 8; index++) {
            int row = input[index * 6] * 2 + input[index * 6 + 5];
            int col = input[index * 6 + 1] * 8 + input[index * 6 + 2] * 4 + input[index * 6 + 3] * 2 + input[index * 6 + 4];
            std::bitset<4> value_of_resulting_cell = S_Box[index][row * 16 + col];

            ret[temp++] = value_of_resulting_cell[3];
            ret[temp++] = value_of_resulting_cell[2];
            ret[temp++] = value_of_resulting_cell[1];
            ret[temp++] = value_of_resulting_cell[0];
        }
        return ret;
    }
    std::bitset<32> Permutation(std::bitset<32> input) {
        std::bitset<32> ret;
        for(int i = 0; i < 32; i++) {
            ret[i] = input[Permutation_table[i] - 1];
        }
        return ret;
    }

    public:
    DES();

    /**
     * @brief This is for initializing DES Class
     * 
     * @param plaintext    should be hexadecimal. 
     * @param key          key.
     */
    DES(std::string plaintext, std::string key) {
        _plaintext = ASCIIstring_to_bitset(plaintext);      // Including Padding Technique.
        _key = KeyPermutation(ASCIIstring_to_bitset(key));  // Key Permuation when Input comes.
    }

    std::bitset<64> Encryption() {
        std::bitset<64> crypto_message;
        crypto_message = InitialPermutation(_plaintext);

        // Cut 64 bits to 32 bits
        std::bitset<32> left;
        std::bitset<32> right;
        for(int i = 0; i < 32; i++) {
            left[i] = crypto_message[i];
            right[i] = crypto_message[i+32];
        }
        std::vector<std::bitset<32>> each = {left, right};
        
        for(int i = 0; i < 16; i++) {
            each = OneRound(each.at(0), each.at(1), i);
        }

        // 32-bit swap
        for(int i = 0; i < 32; i++) {
            crypto_message[i]    = each.at(1)[i];
            crypto_message[i+32] = each.at(0)[i];
        }
        crypto_message = Inverse_of_InitialPermutation(crypto_message);
        _encrypted_message = crypto_message;
        return crypto_message;
    }

    void nowStatus() {
        std::cout << "NOW STATUS OF DES\n";
        std::cout << "PlainText \t\t" << _plaintext << "\n";
    }

    std::string to_hexadecimal_string() {
        std::string ret;
        for(int i = 0; i < 16; i++) {
            unsigned int now = _encrypted_message[i*4 + 0] * 8 + _encrypted_message[i*4 + 1] * 4 + _encrypted_message[i*4 + 2] * 2 + _encrypted_message[i*4 + 3];
            ret = ret + uint_to_char(now);
            if(i % 2 == 1) {
                ret = ret + " ";
            }
        }
        return ret;
    }
};

int main() {
    DES test = DES("123456ABCD132536", "AABB09182736CCDD");
    test.Encryption();
    std::cout << test.to_hexadecimal_string() << "\n";
}