// https://www.acmicpc.net/problem/1002
#include <iostream>
#include <cmath>

// 매우 작은 수
// Double 형 끼리의 수 비교를 위함. (https://stackoverflow.com/a/17341/7105963)
#define EPSILON     1e-10

bool areSame(double _a, double _b) {
    return std::abs(_a - _b) < EPSILON;
}

double getDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int T;
    std::cin >> T;
    
    while(T --> 0) {
        double x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        double distance = getDistance(x1, y1, x2, y2);
        double big_radius, small_radius;
        if(r1 > r2) {
            big_radius = r1;
            small_radius = r2;
        } else {
            big_radius = r2;
            small_radius = r1;
        }

        if(areSame(distance, 0.0) && areSame(r1, r2)) {
            // 두 원이 일치할 때, 답은 -1
            std::cout << "-1\n";
            continue;
        } else if(areSame(distance, (r1 + r2))) {
            // 두 원이 외접할 때, 답은 1
            std::cout << "1\n";
            continue;
        } else if(areSame(distance + small_radius, big_radius)) {
            // 두 원이 내접할 때, 답은 1
            std::cout << "1\n";
            continue;
        } else if(distance > r1 + r2) {
            // 두 원이 서로 떨어져 있고 만나지 않을 때, 답은 0
            std::cout << "0\n";
            continue;
        } else if(distance + small_radius < big_radius) {
            // 한 원이 다른 원의 내부에 있고 두 원이 만나지 않을 때, 답은 0.
            // 꼭 두 원의 중심이 같을 필요는 없습니다!
            std::cout << "0\n";
            continue;
        } else {
            std::cout << "2\n";
            continue;
        }
    }
}