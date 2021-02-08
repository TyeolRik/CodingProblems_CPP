#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Block {
    public:
    int posX;
    int posY;

    Block() {

    }

    Block(int _x, int _y) {
        posX = _x;
        posY = _y;
    }

    void printBlock() {
        std::cout << "(" << posX << ", " << posY << ")\n";
    }


};

std::vector<Block> stack;

std::vector<int> initialNode;

int boardSize;
int answerCount;

std::vector<int> getChild(Block current) {
    std::vector<int> ret(boardSize);
    std::iota(ret.begin(), ret.end(), 0);
    ret.erase(std::remove(ret.begin(), ret.end(), current.posY - 1), ret.end());
    ret.erase(std::remove(ret.begin(), ret.end(), current.posY), ret.end());
    ret.erase(std::remove(ret.begin(), ret.end(), current.posY + 1), ret.end());

    for(Block each : stack) {
        ret.erase(std::remove(ret.begin(), ret.end(), each.posY), ret.end());
    }

    /*
    std::cout << "GETCHILD : {";
    for(auto each : ret) {
        std::cout << each << ' ';
    }
    std::cout << "}\n";
    */
    return ret;
}

bool isPossiblePutQueen(Block A, Block B) {
    int aX = A.posX;
    int bX = B.posX;
    int aY = A.posY;
    int bY = B.posY;
    int tempX = aX - bX;
    int tempY = aY - bY;
    // 옆에 있으면 불가능 || 세로가 같아도 불가능 || 대각선이면 불가능
    if((aX == bX) || (aY == bY) || (tempX == tempY) || (tempX == tempY * -1)) {
        return false;
    }
    return true;
}

bool isAllOK(std::vector<Block> _stack, Block _attempt_to_input) {
    for(Block each : _stack) {
        if(!isPossiblePutQueen(each, _attempt_to_input)) {
            return false;
        }
    }
    return true;
}

void DFS(int recursive_count) {

    // 탈출조건
    if(recursive_count == 0) {
        std::cout << "ESCAPE\n";
        for(Block each : stack) {
            each.printBlock();
        }
        stack.pop_back();
        answerCount++;
        return;
    }

    Block currentBlock;

    if(stack.size() == 0) {
        currentBlock = Block(0, initialNode.back());
        initialNode.pop_back();
        stack.push_back(currentBlock);
    } else {
        currentBlock = stack.back();
    }

    std::vector<int> children = getChild(currentBlock);

    for(int possibleCol : children) {
        Block attempt = Block(currentBlock.posX + 1, possibleCol);
        if(!isAllOK(stack, attempt)) {
            continue;
        }
        stack.push_back(attempt);
        DFS(recursive_count - 1);
        stack.pop_back();
    }

}

int main() {
    int N;
    // std::cin >> N;
    N = 8;
    boardSize = N;
    initialNode = std::vector<int>(boardSize);
    std::iota(initialNode.begin(), initialNode.end(), 0);

    DFS(boardSize);

    std::cout << answerCount << "\n";
}