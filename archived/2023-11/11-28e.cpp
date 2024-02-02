#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &i: a) cin >> i;
        ll l = 0, r = 1e9;
        for (int i=1; i<n; i++) {
            if (a[i-1] < a[i]) {
                ll diff = a[i] - a[i-1];
                r = min(r, a[i-1] + diff / 2);
            } else if (a[i-1] > a[i]) {
                ll diff = a[i-1] - a[i];
                l = max(l, a[i] + (diff + 1) / 2);
            }
        }
        // cout << l << ", " << r << endl;
        if (l <= r) cout << l << endl;
        else cout << -1 << endl;
    }
}