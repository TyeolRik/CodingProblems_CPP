#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#define RED         0
#define ORANGE      1
#define BLUE        2
#define YELLOW      3
#define GREEN       4
#define WHITE       5

// Make Random
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 99);          // Call dis(gen)
// std::cout << "난수 : " << dis(gen) << std::endl;

class MyCube {
    private:
    int matrix[6][3][3];
    void move_row_left(int num_row) {
        // Row 방향으로는 1, 2, 3, 4 면이 영향을 받는다.
        int temp[3] = {matrix[0][num_row][0], matrix[0][num_row][1], matrix[0][num_row][2]};
        for(int i = 0; i < 3; i++) {
            matrix[0][num_row][i] = matrix[2][num_row][i];
            matrix[2][num_row][i] = matrix[3][num_row][i];
            matrix[3][num_row][i] = matrix[1][num_row][i];
            matrix[1][num_row][i] = temp[i];
        }
    }
    void move_row_right(int num_row) {
        // Row 방향으로는 1, 2, 3, 4 면이 영향을 받는다.
        int temp[3] = {matrix[0][num_row][0], matrix[0][num_row][1], matrix[0][num_row][2]};
        for(int i = 0; i < 3; i++) {
            matrix[0][num_row][i] = matrix[1][num_row][i];
            matrix[1][num_row][i] = matrix[3][num_row][i];
            matrix[3][num_row][i] = matrix[2][num_row][i];
            matrix[2][num_row][i] = temp[i];
        }
    }
    void move_col_up(int num_col) {
        // Col 방향으로는 1, 4, 5, 6 면이 영향을 받는다.
        int temp[3] = {matrix[0][0][num_col], matrix[0][1][num_col], matrix[0][2][num_col]};
        for(int i = 0; i < 3; i++) {
            matrix[0][i][num_col] = matrix[5][i][num_col];
            matrix[5][i][num_col] = matrix[3][i][num_col];
            matrix[3][i][num_col] = matrix[4][i][num_col];
            matrix[4][i][num_col] = temp[i];
        }
    }
    void move_col_down(int num_col) {
        // Col 방향으로는 1, 4, 5, 6 면이 영향을 받는다.
        int temp[3] = {matrix[0][0][num_col], matrix[0][1][num_col], matrix[0][2][num_col]};
        for(int i = 0; i < 3; i++) {
            matrix[0][i][num_col] = matrix[4][i][num_col];
            matrix[4][i][num_col] = matrix[3][i][num_col];
            matrix[3][i][num_col] = matrix[5][i][num_col];
            matrix[5][i][num_col] = temp[i];
        }
    }
    void move_side_left(int num_side) {
        // Side 방향으로는 2, 3, 5, 6 면이 영향을 받는다.
        // Row, Col과는 달리, Side 방향에서는 행과 열에 대해서 주의하여야 한다.
        int temp[3] = {matrix[1][0][num_side], matrix[1][1][num_side], matrix[1][2][num_side]}; // 2번 면

        // 5 -> 2
        matrix[1][0][num_side] = matrix[4][num_side][0];
        matrix[1][1][num_side] = matrix[4][num_side][1];
        matrix[1][2][num_side] = matrix[4][num_side][2];

        // 3 -> 5
        matrix[4][num_side][0] = matrix[2][0][num_side];
        matrix[4][num_side][1] = matrix[2][1][num_side];
        matrix[4][num_side][2] = matrix[2][2][num_side];

        // 6 -> 3
        matrix[2][0][num_side] = matrix[5][num_side][0];
        matrix[2][1][num_side] = matrix[5][num_side][1];
        matrix[2][2][num_side] = matrix[5][num_side][2];

        // 2 -> 6
        matrix[5][num_side][0] = temp[0];
        matrix[5][num_side][1] = temp[1];
        matrix[5][num_side][2] = temp[2];

    }
    void move_side_right(int num_side) {
        // Side 방향으로는 2, 3, 5, 6 면이 영향을 받는다.
        // Row, Col과는 달리, Side 방향에서는 행과 열에 대해서 주의하여야 한다.
        int temp[3] = {matrix[1][0][num_side], matrix[1][1][num_side], matrix[1][2][num_side]}; // 2번 면

        // 6 -> 2
        matrix[1][0][num_side] = matrix[5][num_side][0];
        matrix[1][1][num_side] = matrix[5][num_side][1];
        matrix[1][2][num_side] = matrix[5][num_side][2];

        // 3 -> 6
        matrix[5][num_side][0] = matrix[2][0][num_side];
        matrix[5][num_side][1] = matrix[2][1][num_side];
        matrix[5][num_side][2] = matrix[2][2][num_side];

        // 5 -> 3
        matrix[2][0][num_side] = matrix[4][num_side][0];
        matrix[2][1][num_side] = matrix[4][num_side][1];
        matrix[2][2][num_side] = matrix[4][num_side][2];

        // 2 -> 5
        matrix[4][num_side][0] = temp[0];
        matrix[4][num_side][1] = temp[1];
        matrix[4][num_side][2] = temp[2];

    }


    public:
    MyCube() {
        // Initialize Cube with Complete State

        // N사분면에 무슨 색을 채색할 것인가?
        std::vector<int> temp_color_list{RED, ORANGE, BLUE, YELLOW, GREEN, WHITE};
        std::uniform_int_distribution<int> __random(0, 6*5*4*3*2);
        int random_number = __random(gen);
        while(random_number --> 0) {
            std::next_permutation(temp_color_list.begin(), temp_color_list.end());
        }
        std::cout << "Color : { " \
        << temp_color_list.at(0) << ", " \
        << temp_color_list.at(1) << ", " \
        << temp_color_list.at(2) << ", " \
        << temp_color_list.at(3) << ", " \
        << temp_color_list.at(4) << ", " \
        << temp_color_list.at(5) << " }\n\n";

        for(int side = 0; side < 6; side++) {
            for(int row = 0; row < 3; row++) {
                for(int col = 0; col < 3; col++) {
                    matrix[side][row][col] = temp_color_list.at(side);
                }
            }
        }
    }
    MyCube(int init_matrix[6][3][3]) {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    matrix[i][j][k] = init_matrix[i][j][k];
                }
            }
        }
    }
    void print_matrix() {
        std::cout << "{ ";
        for(int side = 0; side < 6; side++) {
            if(side != 0) {
                std::cout << "  ";
            }
            std::cout << "{ ";
            for(int row = 0; row < 3; row++) {
                if(row != 0) {
                    std::cout << "    ";
                }
                std::cout << "{ ";
                for(int col = 0; col < 3; col++) {
                    std::cout << matrix[side][row][col];
                    if(col != 2) {
                        std::cout << ", ";
                    }
                }
                std::cout << " }";
                if(row != 2) {
                    std::cout << ",";
                }
            }
            std::cout << " }";
            if(side != 5) {
                std::cout << ",\n";
            }
        }
        std::cout << " }\n\n";
    }
    void print_as_cube() {
        std::cout << " |-1사분면-| ";
        std::cout << " |-2사분면-| ";
        std::cout << " |-3사분면-| ";
        std::cout << " |-4사분면-| ";
        std::cout << " |-5사분면-| ";
        std::cout << " |-6사분면-| \n";
        for(int row = 0; row < 3; row++) {
            for(int side = 0; side < 6; side++) {
                std::cout << " | ";
                for(int col = 0; col < 3; col++) {
                    std::cout << matrix[side][row][col];
                    if(col < 2) {
                        std::cout << ", ";
                    } else {
                        std::cout << " | ";
                    }
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }
    bool IsCorrect() {
        int color_check[6] = {0, };     // 각 면의 색상이 사용되면 1로 체크된다.
        for(int face = 0; face < 6; face++) {
            int current_color = matrix[face][0][0];
            bool same_sofar = true;
            for(int row = 0; row < 3; row++) {
                for(int col = 0; col < 3; col++) {
                    if(current_color != matrix[face][row][col]) {
                        same_sofar = false;
                    }
                }
            }
            if(same_sofar == true) {
                color_check[current_color]++;
            }
        }
        int temp = 0;
        for(int i = 0; i < 6; i++) {
            if(color_check[i] == 1) {
                temp++;
            }
        }
        if(temp == 6) {
            std::cout << "CORRECT!\n";
            return true;
        } else {
            std::cout << "WRONG!\n";
            return false;
        }
    }
    void move(char select_row_col_side, int number, bool left_or_right) {
        // select_row_col_side: 0이면 row, 1이면 column, 2이면 side이다.
        // number: row[number] 또는 col[number]의 number이다.
        // left_or_right: 0(false)이면 left/up, 1(true)이면 right/down이다.
        if(select_row_col_side == 0) {
            // row 방향으로 이동. 영향을 받는건 1, 2, 3, 4면
            if(left_or_right == 0) {
                move_row_left(number);
            } else if(left_or_right == 1) {
                move_row_right(number);
            } else {
                std::cout << "SOMETHING ERROR :: left_or_right should be 0 or 1. But, left_or_right is " << left_or_right << "\n";
                perror("FATAL ERROR\n");
            }
        } else if(select_row_col_side == 1) {
            if(left_or_right == 0) {
                move_col_up(number);
            } else if(left_or_right == 1) {
                move_col_down(number);
            } else {
                std::cout << "SOMETHING ERROR :: left_or_right should be 0 or 1. But, left_or_right is " << left_or_right << "\n";
                perror("FATAL ERROR\n");
            }
        } else if(select_row_col_side == 2) {
            if(left_or_right == 0) {
                move_side_left(number);
            } else if(left_or_right == 1) {
                move_side_right(number);
            } else {
                std::cout << "SOMETHING ERROR :: left_or_right should be 0 or 1. But, left_or_right is " << left_or_right << "\n";
                perror("FATAL ERROR\n");
            }
        } else {
            std::cout << "SOMETHING ERROR :: select_row_col_side should be 0 or 1. But, select_row_col_side is " << select_row_col_side << "\n";
            perror("FATAL ERROR\n");
        }
    }
    void shuffle(int how_many_shuffle) {
        // 랜덤하게 Cube를 섞는 함 수

        std::uniform_int_distribution<int> random_row_col_or_side(0, 2);
        std::uniform_int_distribution<int> random_number(0, 2);
        std::uniform_int_distribution<int> random_left_or_right(0, 1);

        std::cout << "Shuffle Start! : " << how_many_shuffle << " times will be done\n";

        while(how_many_shuffle --> 0) {
            move(random_row_col_or_side(gen), random_number(gen), random_left_or_right(gen));
        }

        std::cout << "Shuffle Complete!\n\n";
    }
};

int main() {
    // Declare Cube Variable
    MyCube temp = MyCube();     // 새로운 큐브 선언
    temp.print_as_cube();       // 출력
    temp.shuffle(1000000);      // 100만번 랜덤섞기
    temp.print_matrix();        // 출력
    temp.move(0, 0, 0);
    temp.print_matrix();
    temp.IsCorrect();           // 정답 여부 확인
}