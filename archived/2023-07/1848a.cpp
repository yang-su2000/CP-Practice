#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, k, x, y, xi, yi;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin >> x >> y;
        bool ans = true;
        for (int i=0; i<k; i++) {
            cin >> xi >> yi;
            if ((abs(xi - x) + abs(yi - y)) % 2 == 0) ans = false;
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}