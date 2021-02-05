#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

typedef struct node{
    int element, level;
} node;

int main() {

    int N, M;
    cin >> N >> M;
    
    auto start = std::chrono::high_resolution_clock::now();
    // Non-recurisve DFS solution
    vector<node> answer;
    vector<node> st;
    vector<bool> visited(N + 1);
    // push first node to stack
    for (int i = N; i > 0; i--) {
        st.push_back({i, 1});
    }
    while (!st.empty()) {
        // pop node from stack
        node curNode = st.back();
        st.pop_back();
        // pop node from answer
        while (!answer.empty() && answer.back().level >= curNode.level) {
            visited[answer.back().element] = false;
            answer.pop_back();
        }
        // push node to answer
        answer.push_back(curNode);
        visited[curNode.element] = true;
        if (curNode.level == M) {
            // if last level, print answer
            for (int i = 0; i < M; i++) {
                // cout << answer[i].element << ' ';
            }
            // cout << '\n';
        } else {
            // else, push next node to stack
            for (int i = N; i > 0; i--) {
                if (!visited[i]) {
                    st.push_back({i, curNode.level + 1});
                }
            }
        }
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << "Time cost : " << microseconds / 1000.0 << "ms\n";
}