// https://www.acmicpc.net/problem/1620
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    init();

    int t, n;
    cin >> t;

    for (int j = 0; j < t; j++) {
        cin >> n;
        unordered_map<string, int> closet;
        
        string temp, temp_type;
        for (int i = 0; i < n; i++) {
            cin >> temp >> temp_type;
            closet[temp_type] += 1;
        }

        int ans = 1;
        if (closet.size() == 1) {
            ans = closet.begin()->second;
        } else{
            for (auto& cloth: closet) {
                ans *= cloth.second + 1;
            }
            ans--;
        }
        cout << ans << '\n';
    }
}