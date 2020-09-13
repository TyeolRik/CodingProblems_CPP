// https://www.acmicpc.net/problem/1002
#include <iostream>
#include <cmath>

/*
Case 1. 동심원 (원의 중심이 같을 때)
     1-1. 반지름이 서로 다르면 절대 안 만남
     1-2. 반지름이 같으면 무한히 많은 경우의 수

Case 2. 반지름이 작은 원이 
*/

class Circle {
public:
    double x;
    double y;
    double radius;

    Circle(double _x, double _y, double _r) {
        x = _x;
        y = _y;
        radius = _r;
    }
};

double distance(Circle c1, Circle c2) {
    return sqrt((c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y));
}

double smaller(double input1, double input2) {
    if(input1 > input2) {
        return input2;
    } else if(input1 < input2) {
        return input1;
    } else {
        std::cout << "!!!ERROR!!!\n";
        exit(-1);
        return -1;
    }
}

double bigger(double input1, double input2) {
    if(input1 > input2) {
        return input1;
    } else if(input1 < input2) {
        return input2;
    } else {
        std::cout << "!!!ERROR!!!\n";
        exit(-1);
        return -1;
    }
}

int main() {
    int T;
    std::cin >> T;
    
    while(T --> 0) {
        double x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        Circle *circle_big, *circle_small;

        if(r1 > r2) {
            circle_big   = &Circle(x1, y1, r1);
            circle_small = &Circle(x2, y2, r2);
        } else if(r1 == r2) {
            
        } else {    // r1 < r2
            circle_small = &Circle(x1, y1, r1);
            circle_big   = &Circle(x2, y2, r2);
        }

        double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));  // 점과 점 사이의 거리

        double small_r = smaller(r1, r2);   // 반지름 작은 것 구하기
        double big_r = bigger(r1, r2);      // 반지름 큰 것 구하기
        int ret;                            // 나중에 RETURN 할 숫자 저장
    }
    
    

}