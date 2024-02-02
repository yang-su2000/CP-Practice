#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, d, h;
    cin >> t;
    while (t--) {
        cin >> n >> d >> h;
        vector<int> y(n);
        for (int i=0; i<n; i++) cin >> y[i];
        double ans = (double) h * d * n / 2;
        for (int i=1; i<n; i++) {
            int diff = y[i] - y[i-1];
            if (diff >= h) continue;
            // ans -= (double) h * d / 2 - d * diff + ((double) d * diff * diff) / (2 * h);
            double h2 = h - diff;
            double d2 = h2 * d / h;
            ans -= h2 * d2 / 2;
        }
        cout.precision(17);
        cout << fixed << ans << endl;
    }
}