// https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>

class Coordinate {
    public:
    int row;
    int col;
};

int DFS_iterative(std::vector<std::vector<int>> chess_board, Coordinate now) {
    // let S be a stack
    // S.push(v)
    // while S is not empty do
        // v = S.pop()
        // if v is not labeled as discovered then
            // label v as discovered
            // for all edges from v to w in G.adjacentEdges(v) do 
                // S.push(w)
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> chess_board;
    
}