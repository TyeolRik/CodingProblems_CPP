// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> lastLine = std::vector<int>(N);
    std::vector<int> currentLine = std::vector<int>(N);

    for(int height = 1; height <= N; height++) {
        for(int i = 0; i < height; i++) {
            std::cin >> currentLine[i];
        }
        currentLine[0] = currentLine[0] + lastLine[0];
        for(int i = 1; i < height - 1; i++) {
            if(lastLine[i-1] > lastLine[i]) {
                currentLine[i] = currentLine[i] + lastLine[i-1];
            } else {
                currentLine[i] = currentLine[i] + lastLine[i];
            }
        }
        currentLine[height - 1] = currentLine[height - 1] + lastLine[height-2];
        std::copy(currentLine.begin(), currentLine.begin()+height, lastLine.begin());
    }

    std::cout << *std::max_element(lastLine.begin(), lastLine.end());
}