#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

ll binpow(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a, ll m) {
    return binpow(a, m-2, m);
}

int main() {
    int n;
    vector<int> v(3);
    cin >> n;
    ll group = 1;
    ll mod = 998244353;
    for (int i=0; i<n/3; i++) {
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        if (v[0] == v[1]) {
            if (v[1] == v[2]) group = group * 3 % mod;
            else group = group * 2 % mod;
        }
    }
    ll val = 1;
    for (int i=n/6+1; i<=n/3; i++) {
        val = val * i % mod;
    }
    ll invval = 1;
    for (int i=1; i<=n/6; i++) {
        invval = invval * i % mod;
    }
    // cout << group << " " << val << " " << invval << endl;
    ll ans = group * val % mod * inv(invval, mod) % mod;
    cout << ans << endl;
}