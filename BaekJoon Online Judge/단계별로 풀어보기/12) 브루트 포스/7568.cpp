#include <iostream>

class Human {
    public:
    int x;
    int y;
    int rank;

    Human() {
        rank = 1;
        x = 0;
        y = 0;
    }

    Human(int _x, int _y) {
        rank = 1;
        x = _x;
        y = _y;
    }

    void is_bigger_than_me(Human target) {
        if(x < target.x && y < target.y) {
            rank++;
        }
    }
};

int main() {
    int N;
    std::cin >> N;
    Human* list_human = new Human[N];
    for(int i = 0; i < N; i++) {
        int input_x, input_y;
        std::cin >> input_x >> input_y;
        list_human[i] = Human(input_x, input_y);
    }

    // N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            list_human[i].is_bigger_than_me(list_human[j]);
        }
    }
    for(int i = 0; i < N; i++) {
        std::cout << list_human[i].rank << " ";
    }
}