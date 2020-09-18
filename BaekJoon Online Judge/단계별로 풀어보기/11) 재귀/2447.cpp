// https://www.acmicpc.net/problem/2447
#include <iostream>

void print_matrix(char** matrix, int _N) {
    for(int i = 0; i < _N; i++) {
        for(int j = 0; j < _N; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}

void stamp(char** target, char** small_stamp, int row_start, int col_start, int length) {
    for(int i = row_start; i < row_start + length; i++) {
        for(int j = col_start; j < col_start + length; j++) {
            target[i][j] = small_stamp[i-row_start][j-col_start];
        }
    }
}

char** recursive_stamp(char** smaller, int length, int target_size) {

    if(length > target_size) {
        return smaller;
    }

    char** ret = new char*[length];
    for(int i = 0; i < length; i++) {
        ret[i] = new char[length];
        for(int j = 0; j < length; j++) {
            ret[i][j] = ' ';
        }
    }
    for(int i = 0; i < length; i = i + (length / 3)) {
        for(int j = 0; j < length; j = j + (length / 3)) {
            if(i == (length / 3) && j == (length / 3)) {

            } else {
                stamp(ret, smaller, i, j, (length / 3));
            }
        }
    }
    delete smaller;
    
    return recursive_stamp(ret, length * 3, target_size);
}

char** color_blank(char** matrix, int row_start, int col_start, int length, int original_size) {

    // 탈출 조건
    if(length == 3) {
        matrix[row_start + 1][col_start + 1] = ' ';
        return matrix;
    }
    
    // 탈출 조건 2. (탈출 구문 하나가 더 늘었으므로 연산량 3배 감소)
    if(length == 9) {
        matrix[row_start + 7][col_start + 7] \
        = matrix[row_start + 7][col_start + 4] \
        = matrix[row_start + 7][col_start + 1] \
        = matrix[row_start + 4][col_start + 7] \
        = matrix[row_start + 4][col_start + 1] \
        = matrix[row_start + 1][col_start + 7] \
        = matrix[row_start + 1][col_start + 4] \
        = matrix[row_start + 1][col_start + 1] = ' ';
        for(int i = row_start + 3; i < row_start + 6; i++) {
            for(int j = col_start + 3; j < col_start + 6; j++) {
                matrix[i][j] = ' ';
            }
        }
        return matrix;
    }
    
    int temp = length / 3;

    // 가운데만 색칠하기
    for(int i = row_start + temp; i < row_start + temp*2; i++) {
        for(int j = col_start + temp; j < col_start + temp*2; j++) {
            matrix[i][j] = ' ';
        }
    }
    
    for(int i = 0; i < original_size; i = i + temp) {
        for(int j = 0; j < original_size; j = j + temp) {
            matrix = color_blank(matrix, i, j, temp, original_size);
        }
    }

    return matrix;
}

int main() {
    std::cout.sync_with_stdio(false);
    std::cout.tie(NULL);
    int N;
    std::cin >> N;
    char** block = new char*[N];
    for(int i = 0; i < N; i++) {
        block[i] = new char[N];
        for(int j = 0; j < N; j++) {
            block[i][j] = '*';
        }
    }
    // block = color_blank(block, 0, 0, N, N);
    char** small_3x3 = new char*[3];
    for(int i = 0; i < 3; i++) {
        small_3x3[i] = new char[3];
        small_3x3[i][0] = '*';
        small_3x3[i][1] = '*';
        small_3x3[i][2] = '*';
    }
    small_3x3[1][1] = ' ';

    small_3x3 = recursive_stamp(small_3x3, 9, N);
    print_matrix(small_3x3, N);

    // print_matrix(block, N);
}