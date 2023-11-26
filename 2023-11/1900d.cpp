#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int limit = 1e5;
    vector<vector<int>> fac(limit + 1);
    // the Euler totient function, https://cp-algorithms.com/algebra/phi-function.html
    // phi[i]: number of vals < i where gcd(val, i) = 1
    // this is implemented with the divisor sum property, O(nlogn)
    vector<ll> phi(limit + 1);
    for (int i=1; i<=limit; i++) phi[i] = i;
    for (int i=1; i<=limit; i++) {
        fac[i].push_back(i);
        for (int j=i+i; j<=limit; j+=i) {
            fac[j].push_back(i);
            phi[j] -= phi[i];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<ll> dp(limit + 1);
        ll ans = 0;
        for (int i=0; i<n; i++) {
            int val = a[i];
            ll cur = 0;
            // cout << val << ": ";
            // for (int f: fac[val]) cout << f << " ";
            for (int f: fac[val]) cur += dp[f];
            ans += cur * (n - i - 1);
            // cout << "[cur = " << cur << ", ans = " << ans << "]" << endl;
            for (int f: fac[val]) dp[f] += phi[f];
            // cout << "phi: ";
            // for (int f: fac[val]) cout << phi[f] << " ";
            // cout << endl;
            // cout << "dp: ";
            // for (int i=0; i<=20; i++) cout << dp[i] << " ";
            // cout << endl;
        }
        cout << ans << endl;
    }
}