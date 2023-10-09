#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

double dist(int x1, int y1, int x2, int y2) {
    double d1 = abs(x1 - x2);
    double d2 = abs(y1 - y2);
    return sqrt(d1 * d1 + d2 * d2);
}

int main() {
    int t, px, py, ax, ay, bx, by;
    cin >> t;
    while (t--) {
        cin >> px >> py >> ax >> ay >> bx >> by;
        double a0 = dist(0, 0, ax, ay);
        double a1 = dist(px, py, ax, ay);
        double b0 = dist(0, 0, bx, by);
        double b1 = dist(px, py, bx, by);
        double ans = min(max(a0, a1), max(b0, b1));
        double w = dist(ax, ay, bx, by) / 2;
        ans = min(ans, max(w, max(a0, b1)));
        ans = min(ans, max(w, max(a1, b0)));
        cout << setprecision(12) << ans << endl;
    }
}