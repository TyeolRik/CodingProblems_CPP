#include <iostream>
#include <cmath>

#define EPSILON     1e-10

bool is_same(double __x, double __y) {
    if(std::abs(__x - __y) < EPSILON) {
        std::cout << std::fixed << "IN Function __x\t\t" << __x << "\n";
        std::cout << std::fixed << "IN Function __y\t\t" << __y << "\n";
        std::cout << std::fixed << "std::abs(__x - __y)\t" << std::abs(__x - __y) << "\n";
        return true;
    } else {
        return false;
    }
}

double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}

int main() {
    std::cout.precision(17);        // maximum precision : https://stackoverflow.com/a/554134/7105963
    std::cout << std::fixed << "dist (0, 0) ~ (3, 4)\t" << distance(0, 0, 3, 4) << "\n";
    std::cout << std::fixed << "EPSILON(small)\t\t" << EPSILON << "\n";
    std::cout << std::fixed << "distance + EPSILON\t" << (distance(0, 0, 3, 4) + EPSILON) << "\n";
    std::cout << std::fixed << "distance - EPSILON\t" << (distance(0, 0, 3, 4) - EPSILON) << "\n";
    // std::cout << is_same(distance(0, 0, 3, 4), (distance(0, 0, 3, 4) + __DBL_EPSILON__)) << "\n";
    std::cout << is_same(distance(0, 0, 3, 4), (distance(0, 0, 3, 4) + EPSILON)) << "\n";
    std::cout << std::fixed << "5.0 + EPSILON\t\t" << (5.0 + EPSILON) << "\n";
    std::cout << std::fixed << "5.0 - EPSILON\t\t" << (5.0 - EPSILON) << "\n";
    std::cout << std::fixed << "5.0 - EPSILON\t\t" << (5.0 - EPSILON) << "\n";
}