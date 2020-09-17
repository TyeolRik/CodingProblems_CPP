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
                    std::cout << ",\n";
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
    }
    void move();
};

int main() {

    // Declare Cube Variable
    MyCube temp = MyCube();
    temp.print_matrix();
    temp.print_as_cube();
}