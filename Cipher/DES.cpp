#include <iostream>
#include <vector>
#include <bitset>       // 비트 표현
#include <algorithm>

void print_bitset_pretty(std::bitset<64> input) {
    for(int i = 63; i >= 0; i--) {
        std::cout << input[i];
        if(i % 4 == 0) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

class DES {
    private:
    std::bitset<64> _plaintext;
    std::bitset<56> _key;

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
    }

    std::bitset<64> Encryption() {
        std::bitset<64> crypto_message;
        crypto_message = InitialPermutation(_plaintext);



        return crypto_message;
    }

    void nowStatus() {
        std::cout << "NOW STATUS OF DES\n";
        std::cout << "PlainText \t\t" << _plaintext << "\n";
    }

    /**
     * @brief One char is 4 bits in Hexadecimal
     */
    std::bitset<64> ASCIIstring_to_bitset(std::string input) {
        std::bitset<64> output;
        int temp_index = 0;
        for(int i = 0; i < input.size(); i++) {
            std::bitset<4> char_bitarray = char_to_bitset4((input.at(i)));
            for(int j = 0; j < 4; j++) {
                output[temp_index++] = char_bitarray[j];
            }
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
};

int main() {
    DES test = DES("123456ABCD132536", "AABB09182736CCDD");
    test.Encryption();
    // test.nowStatus();

/*
    int a = 11;
    std::bitset<4> test = a;
    std::cout << (int)a << std::endl; 
    std::cout << test << std::endl;

    int temp = 10;
    */
}