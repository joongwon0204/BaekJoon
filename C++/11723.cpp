// https://www.acmicpc.net/problem/11723
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string command;
    int num, M;

    int set = 0;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> command;
        
        if (command == "add") {
            cin >> num;
            set |= (1<<(num-1));
        } else if (command == "remove") {
            cin >> num;
            set &= ~(1<<(num-1));
        } else if (command == "check") {
            cin >> num;
            cout << (set & (1<<(num-1)) ? 1 : 0) << "\n";
        } else if (command == "toggle") {
            cin >> num;
            set ^= (1<<(num-1)); 
        } else if (command == "all") {
            set = (1<<20)-1;
        } else if (command == "empty") {
            set = 0;
        }
    }
} 