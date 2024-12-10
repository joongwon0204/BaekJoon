// https://www.acmicpc.net/problem/13549
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int push_n_x_2power(int n, const int& k, int max_n, queue<int>& q, int* visited) {
    if (n == 0) { return 0;}
    while (n <= max_n) {
        if (n == k) { return 1; }
        if (visited[n]) { 
            n *= 2;
            continue; 
        }
        q.push(n);
        visited[n] = 1;;
        n *= 2;

    }
    return 0;
}

int bfs(int n, const int k, int* visited) {
    int ret = 1; 

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    int max_n = min(2 * k - n, 100000);
    if(push_n_x_2power(n * 2, k, max_n, q, visited)) { return 0; }

    while (!q.empty()) {

        int size = q.size();
        while (size--) {
            int cur = q.front();
            q.pop();

            if (cur - 1 > 0 && !visited[cur - 1]) {
                if (push_n_x_2power(cur - 1, k, max_n, q, visited)) { return ret; }
            }
            if (cur + 1 <= max_n && !visited[cur + 1]) {
                if (push_n_x_2power(cur + 1, k, max_n, q, visited)) {return ret; }
            }
        }
        ret++;
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    int visited[100001] = {0,};

    cout << (n < k ? bfs(n, k, visited) : n - k);
}