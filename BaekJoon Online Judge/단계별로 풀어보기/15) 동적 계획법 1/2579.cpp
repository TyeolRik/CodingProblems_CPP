// https://www.acmicpc.net/problem/2579
#include <iostream>
#include <vector>
#include <algorithm>

typedef struct Possibles {
    int one;        // 1 + 2
    int two;        // 2 + 1
    int three;      // 2 + 2
} Possibles;

int maximumStacked(Possibles input) {
    return std::max(std::max(input.one, input.two), input.three);
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int theNumberOfStairs;
    std::cin >> theNumberOfStairs;
    std::vector<int> stairPoint(theNumberOfStairs);
    for(int i = 0; i < theNumberOfStairs; i++) {
        std::cin >> stairPoint[i];
    }

    std::vector<int> temp;
    Possibles temp1, tempPossible;
    switch (theNumberOfStairs)
    {
    case 1:
        std::cout << stairPoint[0];
        break;
    case 2:
        std::cout << stairPoint[0] + stairPoint[1];
        break;
    case 3:
        std::cout << std::max(stairPoint[0] + stairPoint[2], stairPoint[1] + stairPoint[2]);
        break;
    case 4:
        temp = {stairPoint[0] + stairPoint[1] + stairPoint[3], stairPoint[0] + stairPoint[2] + stairPoint[3], stairPoint[1] + stairPoint[3]};
        std::cout << *std::max_element(temp.begin(), temp.end());
        break;
    case 5:
        temp1 = {stairPoint[0] + stairPoint[1], stairPoint[1], stairPoint[1]};
        temp = {stairPoint[1] + stairPoint[2] + stairPoint[4], maximumStacked(temp1) + stairPoint[3] + stairPoint[4], stairPoint[0] + stairPoint[2] + stairPoint[4]};
        std::cout << *std::max_element(temp.begin(), temp.end());
        break;
    default:
        std::vector<Possibles> stackedPoint(theNumberOfStairs);
        stackedPoint[0] = {stairPoint[0], stairPoint[0], stairPoint[0]};
        stackedPoint[1] = {stairPoint[0] + stairPoint[1], stairPoint[1], stairPoint[1]};
        stackedPoint[2] = {stairPoint[0] + stairPoint[2], stairPoint[1] + stairPoint[2], 0};
        stackedPoint[3] = {stairPoint[0] + stairPoint[1] + stairPoint[3], stairPoint[0] + stairPoint[2] + stairPoint[3], stairPoint[1] + stairPoint[3]};
        stackedPoint[4] = {stairPoint[1] + stairPoint[2] + stairPoint[4], maximumStacked(stackedPoint[1]) + stairPoint[3] + stairPoint[4], stairPoint[0] + stairPoint[2] + stairPoint[4]};
        stackedPoint[5] = {std::max(stackedPoint[2].one, stackedPoint[2].three) + stairPoint[3] + stairPoint[5]\
                            , maximumStacked(stackedPoint[2]) + stairPoint[4] + stairPoint[5]\
                            , maximumStacked(stackedPoint[1]) + stairPoint[3] + stairPoint[5]};
        
        for(size_t i = 6; i < theNumberOfStairs; i++) {
            tempPossible = {0, 0, 0};
            tempPossible.one    = std::max(stackedPoint[i - 3].one, stackedPoint[i - 3].three) + stairPoint[i - 2] + stairPoint[i];
            tempPossible.two    = maximumStacked(stackedPoint[i - 3]) + stairPoint[i - 1] + stairPoint[i];
            tempPossible.three  = maximumStacked(stackedPoint[i - 4]) + stairPoint[i - 2] + stairPoint[i];
            stackedPoint[i] = tempPossible;
        }
        std::cout << std::max(std::max(stackedPoint[theNumberOfStairs - 1].one, stackedPoint[theNumberOfStairs - 1].two), stackedPoint[theNumberOfStairs - 1].three);
        break;
    }
}