/*
* 강의명 : 암호알고리즘특강
* 작성자 : 백 승 록
* Coded in C++
* Compiled with G++ 9.3.0
* OS: Debian/Buster10
*/

/*
* AES 예제에 대해 1라운드 결과까지를 직접 수행해 보시오.
* Plaintext: 0x0123456789abcdeffedcba9876543210
* Key      : 0x0f1571c947d9e8590cb7add6af7f6798
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

template<std::size_t N>
void pretty_print_bitset(std::bitset<N> target) {
    std::cout << target[0];
    for(int i = 1; i < target.size(); i++) {
        if(i%4 == 0) {
            std::cout << " ";
        }
        std::cout << target[i];
    }
    std::cout << "\n";
}

template<std::size_t N>
std::string bitset_to_hex_string(std::bitset<N> target) {
    std::string ret;
    ret.resize(target.size() / 4);      // 1 Hexadecimal = 4 bits
    for(int i = 0; i < target.size(); i = i + 4) {
        std::stringstream res;
        res << (std::hex) << (std::uppercase) << (target[i] + target[i + 1] * 2 + target[i + 2] * 4 + target[i + 3] * 8);
        ret.at((target.size() - i) / 4 - 1) = res.str()[0];
    }
    return ret;
}

template<std::size_t N>
std::bitset<N> left_rotate(std::bitset<N> target, int howMany) {
    return (target << howMany) | (target >> (target.size() - howMany));
}

template<std::size_t N>
std::bitset<N> right_rotate(std::bitset<N> target, int howMany) {
    return (target >> howMany) | (target << (target.size() - howMany));
}

class AES {
    private:
    int Nb;
    int Nk;
    int Nr;
    std::bitset<128> plaintext;
    std::bitset<128> key;
    std::bitset<128> cipher;
    std::bitset<32> W[44];

    const std::bitset<8> S_BOX[16][16] = {{0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x1, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
                                          {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
                                          {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
                                          {0x4, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x5, 0x9a, 0x7, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
                                          {0x9, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
                                          {0x53, 0xd1, 0x0, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
                                          {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x2, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
                                          {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
                                          {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
                                          {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
                                          {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x6, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
                                          {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x8},
                                          {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
                                          {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x3, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
                                          {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
                                          {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}};
    const std::bitset<8> S_BOX_INVERSE[16][16] = {{0x52, 0x9, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb},
                                                  {0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb},
                                                  {0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e},
                                                  {0x8, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25},
                                                  {0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92},
                                                  {0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84},
                                                  {0x90, 0xd8, 0xab, 0x0, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x5, 0xb8, 0xb3, 0x45, 0x6},
                                                  {0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x2, 0xc1, 0xaf, 0xbd, 0x3, 0x1, 0x13, 0x8a, 0x6b},
                                                  {0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73},
                                                  {0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e},
                                                  {0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b},
                                                  {0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4},
                                                  {0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x7, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f},
                                                  {0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef},
                                                  {0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61},
                                                  {0x17, 0x2b, 0x4, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d}};

    const int MixColumnTransformation[4][4] = {{2, 3, 1, 1}, {1, 2, 3, 1}, {1, 1, 2, 3}, {3, 1, 1, 2}};

    const unsigned int RCON[10] = {0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000};

    int GetNumberOfRounds(int Nb, int Nk) {
        if(Nb == 4) {
            switch (Nk)
            {
            case 4:
                return 10;
            case 6:
                return 12;
            case 8:
                return 14;
            default:
                std::cout << "ERROR :: Unavailable Nk!\n";
                exit(-1);
                break;
            }
        } else if (Nb == 6) {
            switch (Nk)
            {
            case 4:
                return 12;
            case 6:
                return 12;
            case 8:
                return 14;
            default:
                std::cout << "ERROR :: Unavailable Nk!\n";
                exit(-1);
                break;
            }
        } else if (Nb == 8) {
            switch (Nk)
            {
            case 4:
                return 14;
            case 6:
                return 14;
            case 8:
                return 14;
            default:
                std::cout << "ERROR :: Unavailable Nk!\n";
                exit(-1);
                break;
            }
        } else {
            std::cout << "ERROR :: Unavailable Nb!\n";
            exit(-1);
        }
    }

    void Initialize() {
        W[0] = std::bitset<32>(((key >> (128 - 32 * 1)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        W[1] = std::bitset<32>(((key >> (128 - 32 * 2)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        W[2] = std::bitset<32>(((key >> (128 - 32 * 3)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        W[3] = std::bitset<32>(((key >> (128 - 32 * 4)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        // std::cout << "W[0]:\t\t" << W[0] << "\n" << "W[1]:\t\t" << W[1] << "\n" << "W[2]:\t\t" << W[2] << "\n" << "W[3]:\t\t" << W[3] << "\n";

        // Key Expansion
        // Auxiliary Function
        for(int i = 1; i <= 10; i++) {
            std::bitset<32> nextKey = W[i * 4 - 1];
            std::bitset<32> x = left_rotate(W[i * 4 - 1], 8);
            std::bitset<32> y;
            for(int i = 0; i < 4; i++) {      // 1 byte = 8 bits
                int row = x[i * 8 + 4] * 1 + x[i * 8 + 5] * 2 + x[i * 8 + 6] * 4 + x[i * 8 + 7] * 8;
                int col = x[i * 8 + 0] * 1 + x[i * 8 + 1] * 2 + x[i * 8 + 2] * 4 + x[i * 8 + 3] * 8;
                std::bitset<8> value = S_BOX[row][col].to_ulong();
                //std::cout << "(" << row << ", " << col << ")\t" << value.to_ulong() << "\t" << bitset_to_hex_string(value) << "\n";
                for(int j = 0; j < 8; j++) {
                    y[i * 8 + j] = value[j];
                }
            }
            std::bitset<32> z = y ^ std::bitset<32>(RCON[i - 1]);

            W[i*4 + 0] = W[i*4 - 4] ^ z;
            W[i*4 + 1] = W[i*4] ^ W[i*4 - 3];
            W[i*4 + 2] = W[i*4 + 1] ^ W[i*4 - 2];
            W[i*4 + 3] = W[i*4 + 2] ^ W[i*4 - 1];
        }

        for(int i = 0; i < 44; i++) {
            std::cout << "W[" << i << "]: " << bitset_to_hex_string(W[i]) << "\n";
        }
    }

    std::bitset<128> AddRoundKey(std::bitset<128> input, std::bitset<32> w1, std::bitset<32> w2, std::bitset<32> w3, std::bitset<32> w4) {
        std::bitset<128> w_collect = std::bitset<128>((std::bitset<128>(w1.to_ullong()) << 96) |\
                                                      (std::bitset<128>(w2.to_ullong()) << 64) |\
                                                      (std::bitset<128>(w3.to_ullong()) << 32) |\
                                                      (std::bitset<128>(w4.to_ullong())));
        //std::cout << "w_collect:\t\t" << w_collect << "\n";
        return input ^ w_collect;
    }

    std::bitset<128> SubstituteBytes(std::bitset<128> input) {
        std::bitset<128> ret;
        for(int i = 0; i < 16; i++) {      // 1 byte = 8 bits
            int row = input[i * 8 + 4] * 1 + input[i * 8 + 5] * 2 + input[i * 8 + 6] * 4 + input[i * 8 + 7] * 8;
            int col = input[i * 8 + 0] * 1 + input[i * 8 + 1] * 2 + input[i * 8 + 2] * 4 + input[i * 8 + 3] * 8;
            std::bitset<8> value = S_BOX[row][col].to_ulong();
            //std::cout << "(" << row << ", " << col << ")\t" << value.to_ulong() << "\t" << bitset_to_hex_string(value) << "\n";
            for(int j = 0; j < 8; j++) {
                ret[i * 8 + j] = value[j];
            }
        }
        return ret;
    }

    std::bitset<128> ShiftRows(std::bitset<128> input) {
        std::bitset<32> C0 = std::bitset<32>(((input >> (128 - 32 * 1)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        std::bitset<32> C1 = std::bitset<32>(((input >> (128 - 32 * 2)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        std::bitset<32> C2 = std::bitset<32>(((input >> (128 - 32 * 3)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        std::bitset<32> C3 = std::bitset<32>(((input >> (128 - 32 * 4)) & std::bitset<128>(0xFFFFFFFF)).to_ullong());
        
        //std::cout << "C0 : " << bitset_to_hex_string(C0) << "\n";\
        std::cout << "C1 : " << bitset_to_hex_string(C1) << "\n";\
        std::cout << "C2 : " << bitset_to_hex_string(C2) << "\n";\
        std::cout << "C3 : " << bitset_to_hex_string(C3) << "\n";

        for(int i = 0; i < 8; i++) {
            bool temp = C0[16 + i];
            C0[16 + i] = C1[16 + i];
            C1[16 + i] = C2[16 + i];
            C2[16 + i] = C3[16 + i];
            C3[16 + i] = temp;
        }
        
        for(int i = 0; i < 8; i++) {
            bool temp1 = C0[8 + i];
            bool temp2 = C1[8 + i];
            C0[8 + i] = C2[8 + i];
            C1[8 + i] = C3[8 + i];
            C2[8 + i] = temp1;
            C3[8 + i] = temp2;
        }
        
        for(int i = 0; i < 8; i++) {
            bool temp = C3[0 + i];
            C3[0 + i] = C2[0 + i];
            C2[0 + i] = C1[0 + i];
            C1[0 + i] = C0[0 + i];
            C0[0 + i] = temp;
        }

        
        //std::cout << "C0 : " << bitset_to_hex_string(C0) << "\n";\
        std::cout << "C1 : " << bitset_to_hex_string(C1) << "\n";\
        std::cout << "C2 : " << bitset_to_hex_string(C2) << "\n";\
        std::cout << "C3 : " << bitset_to_hex_string(C3) << "\n";

        std::bitset<128> ret = (std::bitset<128>(C0.to_ullong()) << (128 - (32 * 1))) | (std::bitset<128>(C1.to_ullong()) << (128 - (32 * 2))) | (std::bitset<128>(C2.to_ullong()) << (128 - (32 * 3))) | (std::bitset<128>(C3.to_ullong()) << (128 - (32 * 4)));
        return ret;
    }

    unsigned int mixcolumnCalulation(unsigned int a, unsigned int target) {
        switch (a)
        {
        case 1:
            return 0xFF & target;
        
        case 2:
            if(target >> 7 == 1) {
                return 0xFF & (target << 1) ^ (0x1b);
            } else {
                return 0xFF & (target << 1);
            }

        case 3:
            if(target >> 7 == 1) {
                return 0xFF & (target << 1) ^ (0x1b) ^ target;
            } else {
                return 0xFF & (target << 1) ^ target;
            }
        }
    }

    std::bitset<128> MixColumns(std::bitset<128> input) {
        int state[4][4];
        for(int col = 0; col < 4; col++) {
            for(int row = 0; row < 4; row++) {
                state[3 - row][3 - col] = input[col * 32 + row * 8 + 0] * 1\
                + input[col * 32 + row * 8 + 1] * 2\
                + input[col * 32 + row * 8 + 2] * 4\
                + input[col * 32 + row * 8 + 3] * 8\
                + input[col * 32 + row * 8 + 4] * 16\
                + input[col * 32 + row * 8 + 5] * 32\
                + input[col * 32 + row * 8 + 6] * 64\
                + input[col * 32 + row * 8 + 7] * 128;\
            }
        }

        unsigned int calc[4][4];

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                calc[j][i] = mixcolumnCalulation(MixColumnTransformation[j][0], state[0][i])\
                            ^ mixcolumnCalulation(MixColumnTransformation[j][1], state[1][i])\
                            ^ mixcolumnCalulation(MixColumnTransformation[j][2], state[2][i])\
                            ^ mixcolumnCalulation(MixColumnTransformation[j][3], state[3][i]);
                // std::cout << "(" << j << ", " << i << ")\t" << calc[j][i] << "\n";
            }
        }

        //for(int i = 0; i < 4; i++) {\
            for(int j = 0; j < 4; j++) {\
                std::cout << bitset_to_hex_string(std::bitset<8>(calc[i][j])) << " ";\
            }\
            std::cout << "\n";\
        }

        std::bitset<128> ret(0);
        for(int col = 0; col < 4; col++) {
            for(int row = 0; row < 4; row++) {
                // std::cout << calc[row][col] << "\t" << bitset_to_hex_string(std::bitset<128>(calc[row][col]) << ((3 - col) * 32 + (3 - row) * 8)) << "\t"\
                            << (std::bitset<128>(calc[row][col]) << ((3 - col) * 32 + (3 - row) * 8)) << "\n";  // 96 + 24 = 120
                ret = ret | (std::bitset<128>(calc[row][col]) << ((3 - col) * 32 + (3 - row) * 8));
            }
        }
        // std::cout << bitset_to_hex_string(ret) << "\n";
        return ret;
    }

    std::bitset<128> OneRound(std::bitset<128> input, int roundNumber) {
        input = SubstituteBytes(input);
        std::cout << "Substitute Bytes:\t" << bitset_to_hex_string(input) << "\n";
        input = ShiftRows(input);
        std::cout << "Shift Rows:\t" << bitset_to_hex_string(input) << "\n";
        input = MixColumns(input);
        std::cout << "MixColumns:\t" << bitset_to_hex_string(input) << "\n";
        input = AddRoundKey(input, W[roundNumber * 4], W[roundNumber * 4 + 1], W[roundNumber * 4 + 2], W[roundNumber * 4 + 3]);
        std::cout << "AddRoundKey:\t" << bitset_to_hex_string(input) << "\n";


        return input;
    }

    std::bitset<128> OneRoundWithoutLastMixColumns(std::bitset<128> input, int roundNumber) {
        input = SubstituteBytes(input);
        std::cout << "Substitute Bytes:\t" << bitset_to_hex_string(input) << "\n";
        input = ShiftRows(input);
        std::cout << "Shift Rows:\t" << bitset_to_hex_string(input) << "\n";
        input = AddRoundKey(input, W[roundNumber * 4], W[roundNumber * 4 + 1], W[roundNumber * 4 + 2], W[roundNumber * 4 + 3]);
        std::cout << "AddRoundKey:\t" << bitset_to_hex_string(input) << "\n";
        return input;
    }


    public:
    AES() {

    }
    AES(std::bitset<128> _plaintext, std::bitset<128> _key) {
        std::cout << "AES Start!\n";
        plaintext = _plaintext;
        std::cout << "Plaintext:\t" << bitset_to_hex_string(plaintext) << "\n";
        key = _key;
        std::cout << "Key:\t\t" << bitset_to_hex_string(key) << "\n";
        Nb = plaintext.size() / 32;
        Nk = key.size() / 32;
        Nr = GetNumberOfRounds(Nb, Nk);
        std::cout << "Total Number of Rounds:\t" << Nr << "\n";
        
        Initialize();       // Set W[0] ~ W[3]
        std::bitset<128> encrypted = AddRoundKey(plaintext, W[0], W[1], W[2], W[3]);
        std::cout << "Add Round Key:\t" << bitset_to_hex_string(encrypted) << "\n";
        for(int i = 1; i < 10; i++) {
            std::cout << "=======ROUND " << i << "=======\n";
            encrypted = OneRound(encrypted, i);
            std::cout << "Round " << i << " : " << bitset_to_hex_string(encrypted) << "\n";
        }
        std::cout << "=======ROUND " << 10 << "=======\n";
        encrypted = OneRoundWithoutLastMixColumns(encrypted, 10);
        std::cout << "Round " << 10 << " : " << bitset_to_hex_string(encrypted) << "\n";

        cipher = encrypted;
    }

    std::string to_string() {
        return bitset_to_hex_string(cipher);
    }

};

int main() {

    // Plaintext = 0x0123456789abcdeffedcba9876543210
    std::bitset<128> plaintext = (std::bitset<128>(0x0123456789abcdef) << 64) | std::bitset<128>(0xfedcba9876543210);
    // Key = 0x0f1571c947d9e8590cb7add6af7f6798
    std::bitset<128> key = (std::bitset<128>(0x0f1571c947d9e859) << 64) | std::bitset<128>(0x0cb7add6af7f6798);

    AES test = AES(plaintext, key);

    std::cout << "\nAES Encrypted : " << test.to_string() << "\n";

}
