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
        vector<ll> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        ll ans = 0;
        ll lo = LLONG_MAX;
        ll hi = LLONG_MIN;
        for (int i=0; i<n; i++) {
            ans += abs(a[i] - b[i]);
            lo = min(lo, max(a[i], b[i]));
            hi = max(hi, min(a[i], b[i]));
        }
        ll add = 0;
        for (int i=0; i<n; i++) {
            ll x = min(a[i], b[i]);
            ll y = max(a[i], b[i]);
            add = max(add, max((x - lo) * 2ll, (hi - y) * 2ll));
        }
        cout << ans + add << endl;
    }
}