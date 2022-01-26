// https://www.acmicpc.net/problem/1463
#include <iostream>
#include <vector>

int main() {
    int N, now;
    std::cin >> N;
    std::vector<int> nums(N+1);

    std::vector<int> current;
    current.reserve(N+1);
    current.push_back(N);
    while(true) {
        now = current.back();
        current.pop_back();

        if(now != 1) {
            if(nums[now - 1] == 0 || nums[now - 1] > (nums[now] + 1)) {
                nums[now - 1] = nums[now] + 1;
                current.push_back(now - 1);
            }
        }
       
        if(now % 2 == 0) {
            if(nums[now / 2] == 0 || nums[now / 2] > (nums[now] + 1)) {
                nums[now / 2] = (nums[now] + 1);
                current.push_back(now / 2);
            }
        }

        if(now % 3 == 0) {
            if(nums[now / 3] == 0 || nums[now / 3] > (nums[now] + 1)) {
                nums[now / 3] = (nums[now] + 1);
                current.push_back(now / 3);
            }
        }

        int counter = 0;
        for(int i = 0; i < current.size(); i++) {
            if(current[i] == 1) {
                counter++;
            }
        }
        if(counter == current.size()) {
            break;
        }
    }
    std::cout << nums[1];
}