// https://www.acmicpc.net/problem/11053
// Time Complexity : O(Nlog(N))
// Using Lower Bound : https://seungkwan.tistory.com/8

/**
 * Unsorted Array 에서는 std::lower_bound 가 적절하지 않다는 지적이 있음.
 * https://stackoverflow.com/a/25592388
 * 
 * 원문
 * Since the precondition of supplying a sorted array has been violated, the behavior is undefined.
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int N;
    std::cin >> N;

    int length = 0;
    std::vector<int> A(N);
    for(size_t i = 0; i < N; i++) {
        std::cin >> A[i];
        int here = A[i];
        auto pos = std::lower_bound(A.begin(), A.begin() + length, here);
        // std::cout << "here : " << here << "\tpos : " << (pos - A.begin()) << "\t1 : *pos : " << *pos << "\n";
        *pos = here;
        // std::cout << "here : " << here << "\tpos : " << (pos - A.begin()) << "\t2 : *pos : " << *pos << "\n";
        if(pos == A.begin() + length) {
            length++;
        }
    }
    std::cout << length << "\n";
}