// https://www.acmicpc.net/problem/10814
#include <iostream>
#include <vector>
#include <algorithm>

class human {
    public:
    int age;
    std::string name;
    int order;

    human(int _age, std::string _name, int _order) {
        age = _age;
        name = _name;
        order = _order;
    }
};

bool compare(human a, human b) {
    if(a.age == b.age) {
        return a.order < b.order;
    } else {
        return a.age < b.age;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<human> list;
    list.reserve(N);

    for(int i = 0; i < N; i++) {
        int age;
        std::string name;
        std::cin >> age >> name;
        list.push_back(human(age, name, i));
    }

    std::sort(list.begin(), list.end(), compare);

    for(int i = 0; i < list.size(); i++) {
        std::cout << list.at(i).age << " " << list.at(i).name << "\n";
    }
}