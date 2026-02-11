// https://www.acmicpc.net/problem/1799
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

using Graph = vector<vector<int>>;


bool able(Graph& B, int n, int x, int y) {
    int i = x-1, j = y-1;
    while(i >= 0 && j >= 0) {
        if (B[i--][j--] == 1) return false;
    }

    i = x-1; j = y+1;
    while(i >= 0 && j < n) {
        if (B[i--][j++] == 1) return false;
    }

    return true;
}


int bishop(Graph& G, int n, Graph& B, int x, int counter) {
    if (x >= n*n) return counter;

    int i = x / n, j = x % n;
    int nx = x + 2;
    if (n % 2 == 0) {
        if (nx % n == 0) nx++;
        else if (nx % n == 1) nx--;
    }
        
    if (G[i][j] == 0) return bishop(G,n,B,nx,counter);
    
    int ret = bishop(G,n,B,nx,counter);
    if (able(B,n,i,j)) {
        B[i][j] = 1;
        ret = max(ret, bishop(G,n,B,nx,counter+1));
        B[i][j] = 0;
    }
    return ret;
}


int main() {
    init();

    int n;
    cin >> n;

    Graph G(n,vector<int>(n,0)), B(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    cout << bishop(G, n, B, 0, 0) + bishop(G, n, B, 1, 0);
}
