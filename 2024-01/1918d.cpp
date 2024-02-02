#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        for (ll &x: a) cin >> x;
        ll l = 0, r = 0;
        for (ll x: a) {
            l = max(l, x);
            r += x;
        }
        ll sum = r;
        function<bool(ll)> solve = [&](ll limit) {
            vector<ll> dp(n);
            multiset<ll> s;
            int li = 0;
            ll lsum = 0;
            ll rsum = sum;
            for (int i=0; i<n; i++) {
                if (i > 0) lsum += a[i-1];
                while (lsum > limit) {
                    lsum -= a[li];
                    if (li > 0) s.erase(s.lower_bound(dp[li-1]));
                    li++;
                }
                rsum -= a[i];
                dp[i] = a[i];
                if (li > 0) dp[i] += *s.begin();
                s.insert(dp[i]);
                if (rsum <= limit and dp[i] <= limit) return true;
            }
            // cout << limit << ": ";
            // for (int i=0; i<n; i++) cout << dp[i] << " \n"[i == n-1];
            return false;
        };
        while (l < r) {
            ll mid = (l + r) / 2;
            // cout << l << " " << mid << " " << r << endl;
            if (solve(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}