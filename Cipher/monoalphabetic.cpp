/*
* 작성일: 2020. 09. 08.
* 교수명: 최  혁
* 저  자: 백승록
* 강의명: 암호알고리즘특강 (Topics in Cryptographic Algorithm)
*/

/*
* 단일문자 치환 암호기법
* Monoalphabetic Ciphers
*/

#include <iostream>
#include <sstream>

void decrypt(std::string input, char key[26]) {
    for(int i = 0; i < input.size(); i++) {
        std::cout << key[(int)input.at(i) - (int)'A'];
    }
}

int main() {
    std::string input = "PBFPVYFBQXZTYFPBFEQJHDXXQVAPTPQJKTOYQWIPBVWLXTOXBTFXQWAXBVCXQWAXFQJVWLEQNTOZQGGQLFXQWAKVWLXQWAEBIPBFXFQVXGTVJVWLBTPQWAEBFPBFHCVLXBQUFEVWLXGDPEQVPQGVPPBFTIXPFHXZHVFAGFOTHFEFBQUFTDHZBQPOTHXTYFTODXQHFTDPTOGHFQPBQWAQJJTODXQHFOQPWTBDHHIXQVAPBFZQHCFWPFHPBFIPBQWKFABVYYDZBOTHPBQPQJTQOTOGHFQAPBFEQJHDXXQVAVXEBQPEFZBVFOJIWFFACFCCFHQWAUVWFLQHGFXVAFXQHFUFHILTTAVWAFFAWTEVOITDHFHFQAITIXPFHXAFQHEFZQWGFLVWPTOFFA";
    char result[input.size() + 1];
    std::copy(input.begin(), input.end(), result);
    result[input.size()] = '\0';

    char key[26] = {0,};
    for(int i = 0; i < 26; i++) {
        key[i] = key[i] + 65 + i;
    }
    key[0]  = 'D';           // A   21
    key[1]  = 'H';           // B   26
    key[2]  = 'P';           // C   6
    key[3]  = 'U';           // D   10
    key[4]  = 'W';           // E   12
    key[5]  = 'E';           // F   51
    key[6]  = 'B';           // G   10
    key[7]  = 'R';           // H   25
    key[8]  = 'Y';           // I   10
    key[9]  = 'L';           // J   9
    key[10] = 'K';           // K   3
    key[11] = 'G';           // L   10
    key[12] = 'J';           // M   0
    key[13] = 'X';           // N   1
    key[14] = 'F';           // O   15
    key[15] = 'T';           // P   28
    key[16] = 'A';           // Q   42
    key[17] = 'Q';           // R   0
    key[18] = 'Z';           // S   0
    key[19] = 'O';           // T   27
    key[20] = 'B';           // U   4
    key[21] = 'I';           // V   24
    key[22] = 'N';           // W   22
    key[23] = 'S';           // X   28
    key[24] = 'M';           // Y   6
    key[25] = 'C';           // Z   8

    decrypt(input, key);
}