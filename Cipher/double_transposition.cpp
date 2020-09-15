/*
* 강의명 : 암호알고리즘특강
* 작성자 : 백 승 록
* Coded in C++
* Compiled with G++ 9.3.0
* OS: Debian/Buster10
*/

/*
* 이중전위 방법으로 다음 평문에 대한 암호문을 구하시오.
* 평문 : ilovecomputersciencetopic
* key : 행열 모두 (34215)
*/

#include <iostream>

/* 단순 행렬 print */
void print_matrix(char** matrix) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/* 주어진 배열의 행을 변경하는 함수 */
char** change_row(char** matrix, int row1, int row2, int row3, int row4, int row5) {
    // Return 할 이중배열 선언
    char** ret = new char*[5];
    for(int i = 0; i < 5; i++) {
        ret[i] = new char[5];
    }
    for(int col = 0; col < 5; col++) {
        ret[0][col] = matrix[row1 - 1][col];
        ret[1][col] = matrix[row2 - 1][col];
        ret[2][col] = matrix[row3 - 1][col];
        ret[3][col] = matrix[row4 - 1][col];
        ret[4][col] = matrix[row5 - 1][col];
    }
    return ret;
}

/* 주어진 배열의 열을 변경하는 함수 */
char** change_column(char** matrix, int col1, int col2, int col3, int col4, int col5) {
    // Return 할 이중배열 선언
    char** ret = new char*[5];
    for(int row = 0; row < 5; row++) {
        ret[row] = new char[5];
        ret[row][0] = matrix[row][col1 - 1];
        ret[row][1] = matrix[row][col2 - 1];
        ret[row][2] = matrix[row][col3 - 1];
        ret[row][3] = matrix[row][col4 - 1];
        ret[row][4] = matrix[row][col5 - 1];
    }
    return ret;
}

int main() {
    std::string message("ilovecomputersciencetopic");
    char** matrix = new char*[5];
    for(int i = 0; i < 5; i++){
        matrix[i] = new char[5];
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = message.at(i*5 + j);
        }
    }

    /* TEST용 출력
    std::cout << "NOT CHANGE\n";
    print_matrix(matrix);

    std::cout << "COLUMN CHANGE (3, 4, 2, 1, 5)\n";
    char** column_changed = change_column(matrix, 3, 4, 2, 1, 5);
    print_matrix(column_changed);

    std::cout << "ROW CHANGE (3, 4, 2, 1, 5)\n";
    char** row_changed = change_row(matrix, 3, 4, 2, 1, 5);
    print_matrix(row_changed);
    */
    std::cout << "BOTH CHANGE (3, 4, 2, 1, 5)\n";
    char** both_changed = change_row(change_column(matrix, 3, 4, 2, 1, 5), 3, 4, 2, 1, 5);
    print_matrix(both_changed);

    std::cout << "Message\t\t: " << message << std::endl;
    std::cout << "Encrypted\t: ";
    for(int i = 0; i < 5; i++) {
        std::cout << both_changed[i];
    }
}