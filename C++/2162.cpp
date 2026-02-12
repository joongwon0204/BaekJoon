// https://www.acmicpc.net/problem/2162
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

struct DSU {
    int setCount, maxSetSize, maxSet;
    vector<int> p, sz;
    DSU(int n) : p(n+1), sz(n+1, 1), setCount(n), maxSetSize(1), maxSet(0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        setCount--;
        if (sz[a] > maxSetSize) {
            maxSetSize = sz[a];
            maxSet = a;
        }
        return true;
    }
};

using Point = pair<int, int>;

int ccw(Point a, Point b, Point c) {
    int ccwValue = (b.first - a.first)*(c.second - a.second) - (b.second - a.second)*(c.first - a.first);
    if (ccwValue > 0) return 1;
    else if (ccwValue == 0) {
        int minx = min(a.first, b.first), maxx = max(a.first, b.first);
        int miny = min(a.second, b.second), maxy = max(a.second, b.second);
        if (minx <= c.first && maxx >= c.first && miny <= c.second && maxy >= c.second) return 0;
        else if (minx > c.first || miny > c.second) return -2;
        else return 2;
    }
    else return -1;
}

bool isTouching(Point a, Point b, Point c, Point d) {
    int abc = ccw(a,b,c), abd = ccw(a,b,d), cda = ccw(c,d,a), cdb = ccw(c,d,b);
    int f = abc * abd, g = cda * cdb;
    
    if (f == 0) return true;
    else if (abs(f) == 2) return false;
    else if (f > 0) return false;
    else if (f < 0) {
        if (g > 0) return false;
        else return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points;
    DSU dsu(n);

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point a(x1,y1), b(x2,y2);
    points.push_back(a);
    points.push_back(b);

    for (int i = 1; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        Point c(x1,y1), d(x2,y2);
        points.push_back(c);
        points.push_back(d);

        for (int j = 0; j < i; j++) {
            a = points[2*j]; b = points[2*j+1];

            if (isTouching(a,b,c,d)) {
                dsu.unite(i,j);
            }

        }
    }

    cout << dsu.setCount << '\n' << dsu.maxSetSize;

}
