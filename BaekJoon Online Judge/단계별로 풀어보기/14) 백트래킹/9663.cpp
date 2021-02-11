#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

typedef struct Block {
    int row, col;
} Block;

std::vector<Block> stack;
int BoardSize;
int solutionCount = 0;

std::vector<int> getPossibleChildren(Block current) {
    std::vector<int> ret(BoardSize);
    std::iota(ret.begin(), ret.end(), 0);
    if(current.col == 0) {
        ret.erase(std::remove(ret.begin(), ret.end(), 0), ret.end());
        ret.erase(std::remove(ret.begin(), ret.end(), 1), ret.end());
    } else if(current.col == (BoardSize - 1)) {
        ret.erase(std::remove(ret.begin(), ret.end(), (BoardSize - 1)), ret.end());
        ret.erase(std::remove(ret.begin(), ret.end(), (BoardSize - 2)), ret.end());
    } else {
        ret.erase(std::remove(ret.begin(), ret.end(), (current.col - 1)), ret.end());
        ret.erase(std::remove(ret.begin(), ret.end(), current.col), ret.end());
        ret.erase(std::remove(ret.begin(), ret.end(), (current.col + 1)), ret.end());
    }
    for(Block each : stack) {
        ret.erase(std::remove(ret.begin(), ret.end(), (each.col)), ret.end());
    }

    return ret;
}

bool isAllOK(Block testBlock) {
    for(Block each : stack) {
        // 대각선으로 일치하는지만 체크하면 됨
        if((each.row - testBlock.row) == (each.col - testBlock.col) || (each.row - testBlock.row) == (each.col - testBlock.col) * -1) {
            return false;
        }
    }
    return true;
}

void DFS(Block currentBlock) {
    // 탈출조건
    if(currentBlock.row == (BoardSize - 1)) {
        solutionCount++;
        return;
    }

    for(int each : getPossibleChildren(currentBlock)) {
        Block testBlock = {currentBlock.row + 1, each};
        if(!isAllOK(testBlock)) {
            continue;
        } else {
            stack.push_back(testBlock);
            DFS(testBlock);
            stack.pop_back();
        }
    }
}

void DFS() {
    for(int i = 0; i < BoardSize; i++) {
        Block firstBlock = {0, i};
        stack.push_back(firstBlock);
        DFS(firstBlock);
        stack.pop_back();
    }
}

int main() {
    int N;
    std::cin >> N;
    BoardSize = N;

    DFS();
    std::cout << solutionCount << "\n";
}