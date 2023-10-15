#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    vector<vector<int>> L, R;
    vector<ll> X;
    ll mod = 998244353;
    while (q--) {
        cin >> s;
        vector<int> l(n), r(n);
        for (int i=0; i<n; i++) {
            cin >> l[i] >> r[i];
        }
        if (s == "ADD") {
            ll x;
            cin >> x;
            X.push_back(x);
            L.push_back(l);
            R.push_back(r);
        } else {
            ll ans = 0;
            int m = (int) X.size();
            for (int c=0; c<m; c++) {
                ll cur = 1;
                bool valid = true;
                for (int i=0; i<n; i++) {
                    int a = max(L[c][i], l[i]);
                    int b = min(R[c][i], r[i]);
                    if (a <= b) {
                        cur = (cur * (b - a + 1)) % mod;
                    } else {
                        valid = false;
                        break;
                    }
                }
                if (valid) ans = (ans + cur * X[c]) % mod;
            }
            cout << ans << endl;
        }
    }
}