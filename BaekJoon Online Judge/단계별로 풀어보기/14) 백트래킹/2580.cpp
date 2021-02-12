// https://www.acmicpc.net/problem/2580
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

typedef struct Block {
    int row, col, content;
} Block;

bool done = false;

std::vector<std::vector<int>> sudoku;
std::vector<Block> blankList;
std::vector<Block> stack;

void printSudoku() {
    std::cout << sudoku[0][0] << ' ' << sudoku[0][1] << ' ' << sudoku[0][2] << ' ' << sudoku[0][3] << ' ' << sudoku[0][4] << ' ' << sudoku[0][5] << ' ' << sudoku[0][6] << ' ' << sudoku[0][7] << ' ' << sudoku[0][8] << "\n";
    std::cout << sudoku[1][0] << ' ' << sudoku[1][1] << ' ' << sudoku[1][2] << ' ' << sudoku[1][3] << ' ' << sudoku[1][4] << ' ' << sudoku[1][5] << ' ' << sudoku[1][6] << ' ' << sudoku[1][7] << ' ' << sudoku[1][8] << "\n";
    std::cout << sudoku[2][0] << ' ' << sudoku[2][1] << ' ' << sudoku[2][2] << ' ' << sudoku[2][3] << ' ' << sudoku[2][4] << ' ' << sudoku[2][5] << ' ' << sudoku[2][6] << ' ' << sudoku[2][7] << ' ' << sudoku[2][8] << "\n";
    std::cout << sudoku[3][0] << ' ' << sudoku[3][1] << ' ' << sudoku[3][2] << ' ' << sudoku[3][3] << ' ' << sudoku[3][4] << ' ' << sudoku[3][5] << ' ' << sudoku[3][6] << ' ' << sudoku[3][7] << ' ' << sudoku[3][8] << "\n";
    std::cout << sudoku[4][0] << ' ' << sudoku[4][1] << ' ' << sudoku[4][2] << ' ' << sudoku[4][3] << ' ' << sudoku[4][4] << ' ' << sudoku[4][5] << ' ' << sudoku[4][6] << ' ' << sudoku[4][7] << ' ' << sudoku[4][8] << "\n";
    std::cout << sudoku[5][0] << ' ' << sudoku[5][1] << ' ' << sudoku[5][2] << ' ' << sudoku[5][3] << ' ' << sudoku[5][4] << ' ' << sudoku[5][5] << ' ' << sudoku[5][6] << ' ' << sudoku[5][7] << ' ' << sudoku[5][8] << "\n";
    std::cout << sudoku[6][0] << ' ' << sudoku[6][1] << ' ' << sudoku[6][2] << ' ' << sudoku[6][3] << ' ' << sudoku[6][4] << ' ' << sudoku[6][5] << ' ' << sudoku[6][6] << ' ' << sudoku[6][7] << ' ' << sudoku[6][8] << "\n";
    std::cout << sudoku[7][0] << ' ' << sudoku[7][1] << ' ' << sudoku[7][2] << ' ' << sudoku[7][3] << ' ' << sudoku[7][4] << ' ' << sudoku[7][5] << ' ' << sudoku[7][6] << ' ' << sudoku[7][7] << ' ' << sudoku[7][8] << "\n";
    std::cout << sudoku[8][0] << ' ' << sudoku[8][1] << ' ' << sudoku[8][2] << ' ' << sudoku[8][3] << ' ' << sudoku[8][4] << ' ' << sudoku[8][5] << ' ' << sudoku[8][6] << ' ' << sudoku[8][7] << ' ' << sudoku[8][8];
}

/*
void printSudoku() {
    for(std::vector<int> eachCol : sudoku) {
        for(int each : eachCol) {
            std::cout << each << ' ';
        }
        std::cout << "\n";
    }
}
*/

std::vector<int> getPossibleSolution(Block currentBlock) {
    std::vector<int> ret;
    std::vector<bool> available(9, true);
    ret.reserve(9);

/*
    // 가로 체크
    for(int each : sudoku[currentBlock.row]) {
        if(each != 0) {
            ret.erase(std::remove(ret.begin(), ret.end(), each), ret.end());
        }
    }

    if(ret.size() == 0) {
        return ret;
    }

    // 세로 체크
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][currentBlock.col] != 0) {
            ret.erase(std::remove(ret.begin(), ret.end(), sudoku[i][currentBlock.col]), ret.end());
        }
    }
    
    if(ret.size() == 0) {
        return ret;
    }
    
    // 네모 체크
    // int startRow = currentBlock.row - (currentBlock.row % 3);
    int startRow = currentBlock.row / 3 * 3;
    // int startCol = currentBlock.col - (currentBlock.col % 3);
    int startCol = currentBlock.col / 3 * 3;
    for(int i = startRow; i < startRow + 3; i++) {
        for(int j = startCol; j < startCol + 3; j++) {
            if(sudoku[i][j] != 0) {
                ret.erase(std::remove(ret.begin(), ret.end(), sudoku[i][j]), ret.end());
            }
        }
    }
*/
    // 가로체크
    for(int each : sudoku[currentBlock.row]) {
        if(each != 0) {
            available[each - 1] = false;
        }
    }

    // 세로체크
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][currentBlock.col] != 0) {
            available[sudoku[i][currentBlock.col] - 1] = false;
        }
    }

    // 네모체크
    int startRow = currentBlock.row / 3 * 3;
    int startCol = currentBlock.col / 3 * 3;
    for(int i = startRow; i < startRow + 3; i++) {
        for(int j = startCol; j < startCol + 3; j++) {
            if(sudoku[i][j] != 0) {
                available[sudoku[i][j] - 1] = false;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        if(available[i]) {
            ret.push_back(i + 1);
        }
    }

    return ret;
}

void DFS() {

    // 탈출조건명시
    if(blankList.empty()) {
        done = true;
        printSudoku();
        exit(0);
        return;
    }
    Block nextBlock = blankList.back();
    blankList.pop_back();

    for(int possible : getPossibleSolution(nextBlock)) {
        sudoku[nextBlock.row][nextBlock.col] = possible;
        stack.push_back({nextBlock.row, nextBlock.col, possible});
        DFS();
        sudoku[nextBlock.row][nextBlock.col] = 0;
        stack.pop_back();
    }
    blankList.push_back(nextBlock);

}


int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    blankList.reserve(80);
    sudoku.reserve(9);
    stack.reserve(80);
    for(int i = 0; i < 9; i++) {
        std::vector<int> col(9);
        for(int j = 0; j < 9; j++) {
            std::cin >> col.at(j);
            if(col.at(j) == 0) {
                blankList.push_back({i, j, 0});
            }
        }
        sudoku.push_back(col);
    }
    DFS();
}