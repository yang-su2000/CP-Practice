#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    vector<pair<ll, ll>> bounds;
    vector<ll> vals;
    for (ll i=2; i<61; i++) {
        ll l = (1ll << i);
        ll r = 2 * l - 1;
        ll a = log(l) / log(i), b = log(r) / log(i);
        if (a == b) {
            bounds.push_back(make_pair(l, r));
            vals.push_back(a);
        } else {
            ll mid = pow(i, b);
            bounds.push_back(make_pair(l, mid - 1));
            vals.push_back(a);
            bounds.push_back(make_pair(mid, r));
            vals.push_back(b);
        }
    }
    int n = (int) bounds.size();
    // for (int i=0; i<n; i++) {
    //     cout << bounds[i].first << " " << bounds[i].second << " " << vals[i] << endl;
    // }
    int q;
    cin >> q;
    ll l, r;
    ll mod = 1e9+7;
    while (q--) {
        cin >> l >> r;
        ll ans = 0;
        for (int i=0; i<n; i++) {
            ll lt = bounds[i].first, rt = bounds[i].second;
            ll val = vals[i];
            if (lt > r or rt < l) continue;
            ll l2 = max(l, lt);
            ll r2 = min(r, rt);
            ll range = (r2 - l2 + 1) % mod;
            ans = (ans + range * val) % mod;
        }
        cout << ans << endl;
    }
}