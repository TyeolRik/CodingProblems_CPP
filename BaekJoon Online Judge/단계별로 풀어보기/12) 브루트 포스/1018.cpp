// https://www.acmicpc.net/problem/1018
#include <iostream>
#include <vector>

class coordination {
    public:
    int x;
    int y;
    char character;
    coordination() {
        x = -1;
        y = -1;
        character = '\0';
    }
    coordination(int _x, int _y, char _character) {
        x = _x;
        y = _y;
        character = _character;
    }
};

int smaller(int a, int b) {
    // 둘 중 작은 값 출력
    if(a > b) {
        return b;
    } else {
        return a;
    }
}

int min(int* arr, int array_size) {
    // 최소값 리턴
    int ret = arr[0];
    for(int i = 0; i < array_size; i++) {
        if(ret > arr[i]) {
            ret = arr[i];
        }
    }
    return ret;
}

void restore(char** restore_target, std::vector<coordination> cos) {
    int size_snapshot = cos.size();
    for(int i = 0; i < size_snapshot; i++) {
        // std::cout << "RESTORED!\n";
        restore_target[cos[i].x][cos[i].y] = cos[i].character;
        cos.pop_back();
    }
}

void print_8x8(char** matrix8x8) {
    std::cout << "====CALL PRINT====\n";
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            std::cout << matrix8x8[i][j];
        }
        std::cout <<'\n';
    }
}

int in8x8(char** full_matrix, int start_row, int start_col) {
    std::vector<coordination> changed;
    int ret_white = 0;
    int ret_black = 0;
    
    for(int i = start_row; i < start_row + 7; i++) {
        for(int j = start_col; j < start_col + 7; j++) {
            if(full_matrix[i][j] == full_matrix[i][j+1]) {    
                // 오른쪽에 같은거면
                // std::cout << "RIGHT ( " << i << ", " << j << " ) is " << full_matrix[i][j] << "\n";
                ret_black++;
                if(full_matrix[i][j] == 'W') {
                    full_matrix[i][j+1] = 'B';
                    changed.push_back(coordination(i, j+1, 'W'));
                } else {
                    full_matrix[i][j+1] = 'W';
                    changed.push_back(coordination(i, j+1, 'B'));
                }
            }
            if(full_matrix[i][j] == full_matrix[i+1][j]) {
                // 아래쪽에 같은거면
                // std::cout << " DOWN ( " << i << ", " << j << " ) is " << full_matrix[i][j] << "\n";
                ret_black++;
                if(full_matrix[i][j] == 'W') {
                    full_matrix[i+1][j] = 'B';
                    changed.push_back(coordination(i+1, j, 'W'));
                } else {
                    full_matrix[i+1][j] = 'W';
                    changed.push_back(coordination(i+1, j, 'B'));
                }
            }
        }
    }
    print_8x8(full_matrix);
    // Restore data
    restore(full_matrix, changed);

    for(int i = start_row + 1; i < start_row + 8; i++) {
        for(int j = start_col + 1; j < start_col + 8; j++) {
            if(full_matrix[i][j] == full_matrix[i][j-1]) {    
                // 왼쪽에 같은거면
                // std::cout << "RIGHT ( " << i << ", " << j << " ) is " << full_matrix[i][j] << "\n";
                ret_white++;
                if(full_matrix[i][j] == 'W') {
                    full_matrix[i][j-1] = 'B';
                    changed.push_back(coordination(i, j-1, 'W'));
                } else {
                    full_matrix[i][j-1] = 'W';
                    changed.push_back(coordination(i, j-1, 'B'));
                }
            }
            if(full_matrix[i][j] == full_matrix[i-1][j]) {
                // 위쪽에 같은거면
                // std::cout << " DOWN ( " << i << ", " << j << " ) is " << full_matrix[i][j] << "\n";
                ret_white++;
                if(full_matrix[i][j] == 'W') {
                    full_matrix[i-1][j] = 'B';
                    changed.push_back(coordination(i-1, j, 'W'));
                } else {
                    full_matrix[i-1][j] = 'W';
                    changed.push_back(coordination(i-1, j, 'B'));
                }
            }
        }
    }
    print_8x8(full_matrix);
    // Restore data
    restore(full_matrix, changed);

    // std::cout << "RETURN: " << smaller(ret_black, ret_white) << "\n";
    return smaller(ret_black, ret_white);
}

int main() {
    int N, M;       // N: 행 / M: 열
    std::cin >> N >> M;
    char** board = new char*[N];
    for(int i = 0; i < N; i++) {
        board[i] = new char[M];
        std::cin >> board[i];
    }
    
    int* coloring = new int[(N - 7) * (M - 7)];
    for(int i = 0; i < (N - 7); i++) {
        for(int j = 0; j < (M - 7); j++) {
            // 8x8 행렬씩 자른 네모로 만듬.
            coloring[(M-7)*i + j] = in8x8(board, i, j);
            // 각 8x8 행렬에서 리턴 된 "최소 색칠 수"를 배열에 넣음.
        }
    }
    std::cout << min(coloring, (N - 7) * (M - 7));
    
}