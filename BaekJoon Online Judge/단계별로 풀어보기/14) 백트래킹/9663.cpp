// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

/*
class Block {
    public:
    unsigned int positionX;
    unsigned int positionY;
    bool isQueen;

    Block() {

    };

    Block(unsigned int posX, unsigned int posY)
        : positionX(posX), positionY(posY), isQueen(false) {};

    void getBlockInfo() {
        // std::cout << isQueen << "\n";
        if(isQueen) {
            std::cout << "(" << positionX << ", " << positionY << ") QUEEN\n";
        } else {
            std::cout << "(" << positionX << ", " << positionY << ") BLANK\n";
        }
    }

};
*/

typedef struct Block {
    int positionX, positionY;
} Block;

std::vector<Block> stack;
std::vector<std::vector<int>> aliveCOLUMN;
int answerCount = 0;
int boardSize;

/*
void printChessBoard(std::vector<std::vector<Block>> board) {
    for(std::vector<Block> each1 : board) {
        for(Block each2 : each1) {
            each2.getBlockInfo();
        }
        std::cout << "\n";
    }
}
*/

bool isPossiblePutQueen(Block A, Block B) {
    int aX = A.positionX;
    int bX = B.positionX;
    int aY = A.positionY;
    int bY = B.positionY;
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

void DFS(std::vector<std::vector<Block>> graph, int recursive_count) {

    // 재귀함수의 탈출조건
    if(recursive_count == 0) {
        answerCount++;
        return;
    }

    for(int i = 0; i < boardSize; i++) { 
        Block test;
        if(stack.size() == 0) {
            test = {0, i};
        } else {
            test = {stack.back().positionX + 1, i};
        }
        if(!isAllOK(stack, test)) {
            continue;
        }
        stack.push_back(test);
        DFS(graph, recursive_count - 1);
        stack.pop_back();

    }
    
}


int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<Block>> chessBoard;
    boardSize = N;

    chessBoard.reserve(N);

    for(int i = 0; i < N; i++) {
        std::vector<Block> eachLine;
        eachLine.reserve(N);
        for(int j = 0; j < N; j++) {
            eachLine.push_back({i, j});
        }
        chessBoard.push_back(eachLine);
    }
    
    DFS(chessBoard, N);

    std::cout << answerCount << "\n";
}