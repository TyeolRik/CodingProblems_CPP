// https://www.acmicpc.net/problem/15596
#include <vector>

long long sum(std::vector<int> &a) {
    long long ret = 0;
    for(int i = 0; i < a.size(); i++) {
        ret = ret + a.at(i);
    }
    return ret;
}