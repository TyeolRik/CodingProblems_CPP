// https://www.acmicpc.net/problem/3053
#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

/*
* Circle in Taxicab geometry

- - * - -
- * - * -
* - O - *
- * - * -
- - * - -

Look like above.
*/


int main() {
    double R;
    std::cin >> R;

    std::cout.precision(10);
    std::cout << std::fixed << R * R * M_PI << "\n";
    std::cout << std::fixed << R * R * 2.0;
}