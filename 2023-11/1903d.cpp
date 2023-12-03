#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll &i: a) cin >> i;
    while (q--) {
        ll k;
        cin >> k;
        vector<ll> a2 = a;
        ll ans = 0;
        for (int b=61; b>=0; b--) {
            bool out = false;
            ll req = 0;
            ll f = (1ll << (b + 1)) - 1;
            ll target = (1ll << b);
            for (ll &i: a2) {
                ll j = (i & f);
                if (j < target) {
                    if (k - (target - j) < req) {
                        out = true;
                        break;
                    }
                    req += target - j;
                }
            }
            if (k >= req and !out) {
                k -= req;
                ans += target;
                for (ll &i: a2) {
                    ll j = (i & f);
                    if (j < target) i += target - j;
                }
            }
        }
        cout << ans << endl;
    }
}