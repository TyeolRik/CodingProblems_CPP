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

class AES {
    private:
    int Nb;
    int Nk;
    int Nr;
    std::bitset<128> plaintext;
    std::bitset<128> key;
    std::bitset<32> W[44];

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
        
    }

    std::bitset<128> OneRound(std::bitset<128> input, int roundNumber) {

    }

    public:
    AES() {

    }
    AES(std::bitset<128> _plaintext, std::bitset<128> _key) {
        std::cout << "AES Start!\n";
        plaintext = _plaintext;
        std::cout << "Plaintext:\t" << plaintext << "\n";
        key = _key;
        std::cout << "Key:\t\t" << key << "\n";
        Nb = plaintext.size() / 32;
        Nk = key.size() / 32;
        Nr = GetNumberOfRounds(Nb, Nk);
        std::cout << "Total Number of Rounds:\t" << Nr << "\n";
        
        Initialize();       // Set W[0] ~ W[3]
        std::bitset<128> encrypted = AddRoundKey(plaintext, W[0], W[1], W[2], W[3]);
        for(int i = 0; i < 9; i++) {

        }

    }


};

int main() {

    // Plaintext = 0x0123456789abcdeffedcba9876543210
    std::bitset<128> plaintext = (std::bitset<128>(0x0123456789abcdef) << 64) | std::bitset<128>(0xfedcba9876543210);
    // Key = 0x0f1571c947d9e8590cb7add6af7f6798
    std::bitset<128> key = (std::bitset<128>(0x0f1571c947d9e859) << 64) | std::bitset<128>(0x0cb7add6af7f6798);

    // std::cout << plaintext << "\n";
    // std::cout << key << "\n";
    AES test = AES(plaintext, key);

}
