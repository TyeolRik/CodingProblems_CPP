// https://www.acmicpc.net/category/detail/1915
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> country(4);
std::vector<double> score(4, 0.0);

int getIndex(std::string input) {
    return std::find(country.begin(), country.end(), input) - country.begin();
}

int main() {
    double board[4][4] = {0.0, };
    for(int i = 0; i < 4; i++) {
        std::cin >> country[i];
    }

    for(int i = 0; i < 6; i++) {
        std::string country1, country2;
        double win, draw, lose;
        std::cin >> country1 >> country2 >> win >> draw >> lose;

        int temp1 = getIndex(country1);
        int temp2 = getIndex(country2);

        score[temp1] = score[temp1] + 3.0 * win + 1.0 * draw;
        score[temp2] = score[temp2] + 1.0 * draw + 3.0 * lose;

    }

    std::vector<double> scoreRank(4);
    std::copy(score.begin(), score.end(), scoreRank.begin());
    std::sort(scoreRank.begin(), scoreRank.end());
    scoreRank.erase(std::unique(scoreRank.begin(), scoreRank.end()), scoreRank.end());
    std::vector<int> scoreCount(scoreRank.size(), 0);
    
    for(int i = 0; i < 4; i++) {
        int index = std::find(scoreRank.begin(), scoreRank.end(), score[i]) - scoreRank.begin();
        scoreCount[index]++;
    }

    int remain = 2;
    for(int i = 0; i < 4; i++) {
        int index = std::find(scoreRank.begin(), scoreRank.end(), score[i]) - scoreRank.begin();
        if(index == scoreRank.size() - 1) {
            if(scoreCount[index] > 1) {
                std::cout << scoreCount[index] / 2.0 << '\n';
            } else {
                remain--;
                std::cout << 1.0 << '\n';
            }
        } else if(index == scoreRank.size() - 2) {
            std::cout << remain / (double)scoreCount[index] << '\n';
        } else {
            std::cout << (double)0 << '\n';
        }
    }
}