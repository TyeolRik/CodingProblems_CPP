// https://www.acmicpc.net/problem/2941
#include <iostream>

int main() {
    std::string input;
    int wordcount = 0;
    std::cin >> input;
    const char* inputArray = input.c_str();
    for(int i = 0; i < input.size(); i++) {
        if(i != 0 && inputArray[i] == '-') {

        } else if(i != 0 && inputArray[i] == '=') {
            if(i > 1 && inputArray[i-1] == 'z' && inputArray[i-2] == 'd') {
                wordcount--;
            }
        } else if(i != 0 && inputArray[i] == 'j' && (inputArray[i-1] == 'l' || inputArray[i-1] == 'n')) {
            
        } else {
            wordcount++;
        }
    }
    std::cout << wordcount;
}