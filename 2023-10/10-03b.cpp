#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> c(n), a(n), b(n);
        for (int i=0; i<n; i++) cin >> c[i];
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        vector<ll> dp(n);
        ll ans = 0;
        for (int i=1; i<n; i++) {
            ll cur = (c[i] - 1) + 2 + abs(a[i] - b[i]); // closed circle from current to prev
            if (a[i] != b[i]) {
                // add prev circle, remove overlap
                cur = max(cur, (c[i] - 1) + 2 + dp[i-1] - abs(a[i] - b[i]));
            }
            dp[i] = cur;
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
}