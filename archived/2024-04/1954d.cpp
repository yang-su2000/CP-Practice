#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    sort(a.begin(), a.end());
    ll mod = 998244353;
    unordered_map<ll, ll> m;
    m[0] = 1;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        unordered_map<ll, ll> m2 = m;
        for (auto [sum, val]: m) {
            if (sum <= a[i]) ans = (ans + a[i] * val) % mod;
            else {
                ll mid = (sum + a[i] + 1) / 2;
                ans = (ans + mid * val) % mod;
            }
            m2[sum + a[i]] = (m2[sum + a[i]] + val) % mod;
        }
        swap(m, m2);
    }
    cout << ans << endl;
}