// https://www.acmicpc.net/problem/17387
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

using Point = pair<long long, long long>;

int ccw(Point a, Point b, Point c) {
    long long ccwValue = (b.first - a.first)*(c.second - a.second) - (b.second - a.second)*(c.first - a.first);
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

int main() {
    long long x1, x2, x3, x4, y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Point a(x1,y1), b(x2,y2), c(x3,y3), d(x4,y4);
    int abc = ccw(a,b,c), abd = ccw(a,b,d), cda = ccw(c,d,a), cdb = ccw(c,d,b);
    int f = abc * abd, g = cda * cdb;
    
    if (f == 0) cout << 1;
    else if (abs(f) == 2) cout << 0;
    else if (f > 0) cout << 0;
    else if (f < 0) {
        if (g > 0) cout << 0;
        else cout << 1;
    }
}
