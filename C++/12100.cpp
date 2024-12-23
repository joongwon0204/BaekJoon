// https://www.acmicpc.net/problem/12100
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

void left(vector<vector<int>>& board, int n) {
    int temps_size;

    for (int i = 0; i < n; i++) {
        vector<int> temps;
        bool did_merge = false;

        if (board[i][0]) {
            temps.push_back(board[i][0]);
        }
        
        for (int j = 1; j < n; j++) {
            if (board[i][j] == 0) continue;

            if (!temps.empty() && board[i][j] == temps.back() && !did_merge) {
                temps.pop_back();
                temps.push_back(board[i][j] * 2);
                did_merge = true;
            } else {
                temps.push_back(board[i][j]);
                did_merge = false;
            }
        }

        temps_size = temps.size();
        for (int j = 0; j < n; j++) {
            board[i][j] = (j < temps_size ? temps[j] : 0);
        }
    }
}

void right(vector<vector<int>>& board, int n) {
    int temps_size;

    for (int i = 0; i < n; i++) {
        vector<int> temps;
        bool did_merge = false;

        if (board[i][n - 1]) {
            temps.push_back(board[i][n - 1]);
        }
                
        for (int j = 1; j < n; j++) {
            if (board[i][n - 1 - j] == 0) continue;

            if (!temps.empty() && board[i][n - 1 - j] == temps.back() && !did_merge) {
                temps.pop_back();
                temps.push_back(board[i][n - 1 - j] * 2);
                did_merge = true;
            } else {
                temps.push_back(board[i][n - 1 - j]);
                did_merge = false;
            }
        }
        
        temps_size = temps.size();
        for (int j = 0; j < n; j++) {
            board[i][n - 1 - j] = (j < temps_size ? temps[j] : 0);
        }
    }
}


void up(vector<vector<int>>& board, int n) {
    int temps_size;

    for (int i = 0; i < n; i++) {
        vector<int> temps;
        bool did_merge = false;

        if (board[0][i]) {
            temps.push_back(board[0][i]);
        }
        
        for (int j = 1; j < n; j++) {
            if (board[j][i] == 0) continue;

            if (!temps.empty() && board[j][i] == temps.back() && !did_merge) {
                temps.pop_back();
                temps.push_back(board[j][i] * 2);
                did_merge = true;
            } else {
                temps.push_back(board[j][i]);
                did_merge = false;
            }
        }

        temps_size = temps.size();
        for (int j = 0; j < n; j++) {
            board[j][i] = (j < temps_size ? temps[j] : 0);
        }
    }
}

void down(vector<vector<int>>& board, int n) {
    int temps_size;

    for (int i = 0; i < n; i++) {
        vector<int> temps;
        bool did_merge = false;

        if (board[n - 1][i]) {
            temps.push_back(board[n - 1][i]);
        }
        
        for (int j = 1; j < n; j++) {
            if (board[n - 1 - j][i] == 0) continue;

            if (!temps.empty() && board[n - 1 - j][i] == temps.back() && !did_merge) {
                temps.pop_back();
                temps.push_back(board[n - 1 - j][i] * 2);
                did_merge = true;
            } else {
                temps.push_back(board[n - 1 - j][i]);
                did_merge = false;
            }
        }
        
        temps_size = temps.size();
        for (int j = 0; j < n; j++) {
            board[n - 1 - j][i] = (j < temps_size ? temps[j] : 0);
        }
    }
}

int move_board(vector<vector<int>>& board, int n, int move_left) {
    int ret = -1;
    vector<vector<int>> board_copy = board;
    if (move_left == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, board[i][j]);
            }
        }
        return ret;
    }

    vector<void(*)(vector<vector<int>>&, int)> moves = {left, right, up, down};

    for (auto move: moves) {
        move(board, n);
        ret = max(ret, move_board(board, n, move_left - 1));
        board = board_copy;
    }

    return ret;
}

int main() {
    init();

    int n, temp;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            board[i][j] = temp;
        }
    }

    cout << move_board(board, n, 5);
}