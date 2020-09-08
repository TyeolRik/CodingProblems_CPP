/*
* 평문 “iloveyou" 을 다음 내용에 따라 암호화하시오.
*/

// Coded in C++
// Compiled with G++ 9.3.0
// OS: Debian/Buster10

#include <iostream>
#include <algorithm>

char playfair_box[5][5];

int* get_coordinate(char something) {
    int* ret = new int[2];
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if (playfair_box[i][j] == something) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    std::cout << "ERROR!!" << std::endl;
    return ret;
}


int main() {
    std::string message = "iloveyou";
    std::string keyword = "computer";
    std::string substring_duplicated_keyword = "";
    char alphabet[25] = {0,};
    int original_key_size = keyword.size();

    // Initialize Message
    // 중복 문자는 X 추가
    for(int i = 1; i < message.size(); i = i + 2) {
        if(message.at(i - 1) == message.at(i)) {
            message.insert(i, 1, 'x');
        }
    }
    if(message.size() % 2 == 1) {
        message.insert(message.size(), 1, 'x');
    }

    // Initialize Alphabet
    for(int i = 0; i < 25; i++) {
        if (i <= (int)'i' - (int)'a') {
            alphabet[i] = (int)'a' + i;
        } else {
            alphabet[i] = (int)'a' + i + 1;
        }
    }

    // J -> I 치환
    std::replace(keyword.begin(), keyword.end(), 'j', 'i');

    // Keyword 내의 중복 제거 Loop
    for(int i = 0; i < keyword.size(); i++) {
        // 만약 중복된 char라면,
        if(substring_duplicated_keyword.find(keyword.at(i)) != std::string::npos) {     
            // Find
        } else {        
            // Not Found
            substring_duplicated_keyword = substring_duplicated_keyword + keyword.at(i);
        }
    }

    // Make Playfair string
    for(int i = 0; i < 25; i++) {
        if(substring_duplicated_keyword.find(alphabet[i]) != std::string::npos) {     
            // Find
        } else {        
            // Not Found
            substring_duplicated_keyword = substring_duplicated_keyword + alphabet[i];
        }
    }
    
    // Initialize Playfair box
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            playfair_box[i][j] = substring_duplicated_keyword.at(i * 5 + j);
        }
    }

    // Playfair Algorithm
    for(int i = 1; i < message.size(); i = i + 2) {
        int* first_letter  = get_coordinate(message.at(i - 1));
        int* second_letter = get_coordinate(message.at(i));
        
        if(first_letter[0] == second_letter[0]) {
            // 같은 행에 두 문자가 있을 경우 우측에 있는 문자와 치환
            message.at(i - 1) = playfair_box[first_letter[0]][(first_letter[1] + 1) % 5];
            message.at(i) = playfair_box[second_letter[0]][(second_letter[1] + 1) % 5];
        } else if(first_letter[1] == second_letter[1]) {
            // 같은 열에 두 문자가 있을 경우 바로 밑에 있는 문자와 치환
            message.at(i - 1) = playfair_box[(first_letter[0] + 1) % 5][first_letter[1]];
            message.at(i) = playfair_box[(second_letter[0] + 1) % 5][second_letter[1]];
        } else {
            // 그 외에 평문자 쌍은 대각선에 위치한 문자와 치환
            message.at(i - 1) = playfair_box[first_letter[0]][second_letter[1]];
            message.at(i) = playfair_box[second_letter[0]][first_letter[1]];
        }
        delete first_letter;
        delete second_letter;
    }
    std::cout << message << std::endl;
}