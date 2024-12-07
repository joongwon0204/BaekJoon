// https://www.acmicpc.net/problem/1987
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dfs(int x, int y, int visited_chars, vector<vector<bool>>& visited, vector<string>& board) {
    int ret = 0;

    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R = board.size(), C = board[0].size();

    for (auto& move: moves) {
        int new_x = x + move.first;
        int new_y = y + move.second;

        if (new_x >= 0 && new_x < C &&
            new_y >= 0 && new_y < R &&
            !visited[new_y][new_x]) {

            int new_char_bit = (1 << (board[new_y][new_x] - 'A'));

            if ((new_char_bit & visited_chars) == 0) {
                visited[new_y][new_x] = 1;
                ret = max(ret, dfs(new_x, new_y, visited_chars | new_char_bit, visited, board));
                visited[new_y][new_x] = 0;
            }
        }
    }
    ret = max(ret, __builtin_popcount(visited_chars));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> board;
    vector<vector<bool>> visited(R,vector<bool>(C,0));
    for (int i = 0; i < R; i++) {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }
    visited[0][0] = 1;
    int visited_chars = 0;
    visited_chars |= (1 << (board[0][0] - 'A'));

    cout << dfs(0, 0, visited_chars, visited, board);

}