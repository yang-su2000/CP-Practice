#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    set<int> vy;
    int count = n * m;
    while (count > 0) {
        cout << sx << " " << sy << endl;
        count--;
        vy.insert(sy);
        int sx2;
        for (int i=1; i<=n; i++) {
            if (i != sx) {
                cout << i << " " << sy << endl;
                sx2 = i;
                count--;
            }
        }
        int sy2;
        for (int j=1; j<=m; j++) {
            if (!vy.count(j)) sy2 = j;
        }
        sx = sx2;
        sy = sy2;
    }
}