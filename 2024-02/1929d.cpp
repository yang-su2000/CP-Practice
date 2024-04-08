#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

struct Union {
    vector<ll> p;
    vector<ll> s;

    Union(ll n) {
        p.resize(n);
        s.resize(n);
        for (int i=0; i<n; i++) {
            p[i] = i;
            s[i] = 1;
        }
    }

    ll find(ll x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void link(ll x, ll y) {
        x = p[x], y = p[y];
        if (s[x] < s[y]) swap(x, y);
        p[y] = x;
        s[x] += s[y];
    }
};

int main() {
    ll mod = 998244353;
    vector<ll> po(3e5+1);
    po[0] = 0;
    po[1] = 1;
    for (int i=2; i<=int(3e5); i++) {
        po[i] = (po[i-1] * 2ll) % mod;
    }
    ll t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        Union U = Union(n);
        vector<ll> ccount(n);
        vector<pair<ll, ll>> E;
        for (int i=0; i<n-1; i++) {
            cin >> u >> v;
            u--, v--;
            U.link(u, v);
            ccount[u]++;
            ccount[v]++;
            E.push_back(make_pair(u, v));
        }
        ll ans = n + n * (n - 1) / 2 + 1;
        // cout << n << "  " << ans << endl;
        ans %= mod;
        map<ll, ll> pcount;
        for (int i=0; i<n; i++) pcount[U.find(i)]++;
        for (auto p: pcount) {
            ll group = p.first;
            ll count = p.second;
            // cout << group << ' ' << count << endl;
            ll cur = po[n - count];
            ll pv = (count * (count - 1)) / 2;
            pv %= mod;
            cur = (cur * pv) % mod;
            ans = (ans + cur) % mod;
        }
        for (auto [u, v]: E) {
            ll count = pcount[U.find(u)];
            ll cur = po[n - count];
            
        }
        cout << ans << endl;
    }
}