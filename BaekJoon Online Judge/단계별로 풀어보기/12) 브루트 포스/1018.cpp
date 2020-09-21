// https://www.acmicpc.net/problem/1018
#include <iostream>
#include <vector>

class coordinate {
    // 이 클래스는 배열을 복구하기 위한 (x, y)를 저장하는 클래스입니다.
    public:
    int x;
    int y;
    char character;

    coordinate() {
        x = -1;
        y = -1;
        character = '\0';
    }

    coordinate(int _x, int _y, char _character) {
        x = _x;
        y = _y;
        character = _character;
    }
};

int minimum(int* arr, int arr_size) {
    int ret = arr[0];
    for(int i = 0; i < arr_size; i++) {
        if(ret > arr[i]) {
            ret = arr[i];
        }
    }
    return ret;
}

int smaller(int a, int b) {
    if(a > b) {
        return b;
    } else {
        return a;
    }
}

int get_coloring_count_in_8x8(char** full_matrix, int row_start, int col_start) {
    int if_first_element_is_white = 0;
    int if_first_element_is_black = 0;
    std::vector<coordinate> coordinates_for_restore;

    // 만약, 정답이 "좌상단 첫번째 element가 하얀색"이라면?
    int first_odd_even = (row_start + col_start) % 2;
    for(int i = row_start; i < row_start + 8; i++) {
        for(int j = col_start; j < col_start + 8; j++) {
            if((i + j) % 2 == first_odd_even && full_matrix[i][j] != 'W') {
                if_first_element_is_white++;
            }
            if((i + j + 1) % 2 == first_odd_even && full_matrix[i][j] != 'B') {
                if_first_element_is_white++;
            }
        }
    }

    // 만약, 정답이 "좌상단 첫번째 element가 검은색"이라면?
    for(int i = row_start; i < row_start + 8; i++) {
        for(int j = col_start; j < col_start + 8; j++) {
            if((i + j) % 2 == first_odd_even && full_matrix[i][j] != 'B') {
                if_first_element_is_black++;
            }
            if((i + j + 1) % 2 == first_odd_even && full_matrix[i][j] != 'W') {
                if_first_element_is_black++;
            }
        }
    }

    return smaller(if_first_element_is_white, if_first_element_is_black);
}

int main() {
    int N, M;
    std::cin >> N >> M;
    char** board = new char*[N];
    for(int i = 0; i < N; i++) {
        board[i] = new char[M];
        for(int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }
    int* saver = new int[(N-7) * (M-7)];
    // 8칸씩 자르기
    for(int i = 0; i < N - 7; i++) {
        for(int j = 0; j < M - 7; j++) {
            saver[i*(M-7) + j] = get_coloring_count_in_8x8(board, i, j);
        }
    }
    std::cout << minimum(saver, (N-7) * (M-7));
}