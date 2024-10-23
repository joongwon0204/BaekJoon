// https://www.acmicpc.net/problem/5525
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canCountWith(char prev, char curr, int counter) {
    if (prev != curr){
        if (counter != 0) { return true;}
        if (prev == 'I') { return true;}
    }
    return false;
}

int main() {
    int n, m, i, ans = 0, counter = 0;
    cin >> n >> m;
    char s[m+1];
    cin >> s;

    char currChar, prevChar = s[0];
    for (i=1; i<m; i++) {
        currChar = s[i];
        if (canCountWith(prevChar,currChar,counter)) {
            counter++;
        } else {
            if (counter != 0) {
                int currP = counter/2 - n + 1;
                if (currP > 0) { ans += currP;}
                counter = 0;
            }
        }
        prevChar = currChar;
    }
    int lastP = counter/2 - n + 1;
    if (lastP > 0){ ans += lastP;}
    cout << ans;
}
