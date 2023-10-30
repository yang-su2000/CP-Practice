#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, sx, sy, d;
    cin >> t;
    while (t--) {
        cin >> n >> m >> sx >> sy >> d;
        if ((sx - d <= 1 and sx + d >= n) or (sy - d <= 1 and sy + d >= m) or (sx - d <= 1 and sy - d <= 1) or (sx + d >= n and sy + d >= m)) {
            cout << -1 << endl;
        } else {
            cout << n - 1 + m - 1 << endl;
        }
    }
}