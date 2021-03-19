// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>
#include <algorithm>

typedef struct Possibles {
    int divide3, divide2, minus1;
} Possibles;

int main() {
    unsigned int N;
    std::cin >> N;

    if(N == 1) {
        std::cout << 0;
        return 0;
    } else if(N == 2) {
        std::cout << 1;
        return 0;
    } else if(N == 3) {
        std::cout << 1;
        return 0;
    }

    std::vector<int> possibilites;
    possibilites.reserve(3);

    std::vector<Possibles> numbers(N + 1, {-1, -1, -1});
    numbers[N] = {0, 0, 0};
    for(size_t i = N - 1; i >= 1; i--) {
        Possibles n_th;

        if(i * 3 <= N) {
            if(numbers[i*3].divide3 != -1) {
                possibilites.push_back(numbers[i*3].divide3);
            }
            if(numbers[i*3].divide2 != -1) {
                possibilites.push_back(numbers[i*3].divide2);
            }
            possibilites.push_back(numbers[i*3].minus1);
            n_th.divide3 = *std::min_element(possibilites.begin(), possibilites.end()) + 1;
            possibilites.clear();
        }

        if(i * 2 <= N) {
            if(numbers[i*2].divide3 != -1) {
                possibilites.push_back(numbers[i*2].divide3);
            }
            if(numbers[i*2].divide2 != -1) {
                possibilites.push_back(numbers[i*2].divide2);
            }
            possibilites.push_back(numbers[i*2].minus1);
            n_th.divide2 = *std::min_element(possibilites.begin(), possibilites.end()) + 1;
            possibilites.clear();
        }

        if(numbers[i+1].divide3 != -1) {
            possibilites.push_back(numbers[i+1].divide3);
        }
        if(numbers[i+1].divide2 != -1) {
            possibilites.push_back(numbers[i+1].divide2);
        }
        possibilites.push_back(numbers[i+1].minus1);
        n_th.minus1 = *std::min_element(possibilites.begin(), possibilites.end()) + 1;
        possibilites.clear();

        // std::cout << "NOW : " << i << " : " << n_th.divide3 << '\t' << n_th.divide2 << '\t' << n_th.minus1 << '\n';
        numbers[i] = n_th;
    }

    std::cout << std::min(std::min(numbers[1].divide3, numbers[1].divide2), numbers[1].minus1);
}