#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    int limit = 1e5;
    vector<ll> dp(limit+1);
    dp[1] = -1;
    for (int i=3; i<=limit; i++) {
        dp[i] = dp[i-3] - 1;
    }
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        for (ll &x: a) cin >> x;
        vector<ll> ans(n);
        ll cur = 0;
        int odd = 0;
        for (int i=0; i<n; i++) {
            cur += a[i];
            if (a[i] % 2) odd++;
            ans[i] = cur + dp[odd];
        }
        ans[0] = a[0];
        for (int i=0; i<n; i++) cout << ans[i] << " \n"[i == n-1];
    }
}