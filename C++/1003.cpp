#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> fibCounter(int n, vector<pair<int, int>>& fibCount){
    if (fibCount[n] != make_pair(-1, -1)) {return fibCount[n];}

    pair<int, int> ret;
    pair<int, int> f1 = fibCounter(n-1,fibCount);
    pair<int, int> f2 = fibCounter(n-2,fibCount);

    ret = make_pair(f1.first + f2.first, f1.second + f2.second);
    fibCount[n] = ret;
    return ret;
}

int main() {
    int T, i;
    cin >> T;

    vector<pair<int, int>> fibCount;
    fibCount.push_back(make_pair(1,0));
    fibCount.push_back(make_pair(0,1));
    for (i=2; i<=40; i++) {
        fibCount.push_back(make_pair(-1, -1));
    }

    for (i=0; i<T; i++) {
        int n;
        cin >> n;
        pair<int, int> ans = fibCounter(n, fibCount);

        cout << ans.first << " " << ans.second << "\n";
    }
}

    