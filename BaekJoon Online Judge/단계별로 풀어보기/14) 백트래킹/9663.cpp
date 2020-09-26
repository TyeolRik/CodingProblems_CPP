// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>

class Coordination {
    public:
    int row;
    int col;
    
    Coordination(int _row, int _col) {
        row = _row;
        col = _col;
    }
};

// Queen이 서로 부딪히는가? : 안 부딪힌다(안전) - 참 / 부딛힌다(위험) - 거짓
bool is_safe(Coordination placeA, Coordination placeB) {
    int row_difference = placeA.row - placeB.row;
    int col_difference = placeA.col - placeB.col;

    // Queen의 이동방향

    // 1. 가로로 만난다.
    if(row_difference == 0) {
        return false;
    }
    // 2. 세로로 만난다.
    else if(col_difference == 0) {   
        return false;
    }
    // 3. 대각선으로 만난다.
    else if(row_difference == col_difference || row_difference == -1 * col_difference) {
        // 절대값 취해줬다고 생각하면 됨.
        return false;
    }
    // 아니면, 안전
    else {
        return true;
    }
}

int DFS(std::vector<Coordination> queen_place, int row, int col, int board_size, int correct) {
    if(queen_place.size() == board_size) {
        correct++;
        return correct;
    } else {
        for(int i = row; i < board_size; i++) {
            for(int j = 0; j < board_size; j++) {
                Coordination now = Coordination(i ,j);
                for(int queen = 0; queen < queen_place.size(); queen++) {
                    if(is_safe(queen_place.at(queen), now)) {
                        queen_place.push_back(now);
                        correct = correct + DFS(queen_place, i, j, board_size, correct);
                        queen_place.pop_back();
                    }
                }
            }
        }
    }
    return correct;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Coordination> queen_place;
    queen_place.reserve(N);

    std::cout << DFS(queen_place, 0, 0, N, 0);
}