#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n);
        int lo = INT_MAX, hi = INT_MIN;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            lo = min(lo, a[i]);
            hi = max(hi, a[i]);
        }
        ll ans = 0;
        for (int i=0; i<n-1; i++) {
            ans += abs((ll) a[i+1] - a[i]);
        }
        ll lo_sum = 0, hi_sum = 0;
        if (1 < lo) {
            ll count = lo - 1;
            lo_sum = count - 1 + min(a[0] - (lo - 1), a.back() - (lo - 1));
            if (n > 1) lo_sum = min(lo_sum, 2 * count);
        }
        if (hi < x) {
            ll count = x - hi;
            hi_sum = count - 1 + min(hi + 1 - a[0], hi + 1 - a.back());
            if (n > 1) hi_sum = min(hi_sum, 2 * count);
        }
        // cout << ans << " " << lo_sum << " " << hi_sum << endl;
        ans += lo_sum + hi_sum;
        cout << ans << endl;
    }
}