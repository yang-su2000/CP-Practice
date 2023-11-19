#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(2*n);
        for (int i=0; i<2*n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> x(n), y(n);
        for (int i=0; i<n; i++) {
            x[i] = a[i];
            y[i] = a[2*n-i-1];
        }
        ll ans = 0;
        for (int i=1; i<n; i++) {
            ans += abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        }
        cout << ans << endl;
        for (int i=0; i<n; i++) cout << x[i] << " " << y[i] << endl;
    }
}