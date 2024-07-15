#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, q;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<ll> c(n);
        for (ll &x: c) cin >> x;
        vector<ll> psum(n), p1(n);
        psum[0] = c[0] - 1;
        if (c[0] == 1) p1[0] = 1;
        for (int i=1; i<n; i++) {
            psum[i] = psum[i-1] + c[i] - 1;
            p1[i] = p1[i-1];
            if (c[i] == 1) p1[i]++;
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            if (l == r) {
                cout << "NO" << endl;
                continue;
            }
            ll count = psum[r];
            if (l > 0) count -= psum[l-1];
            ll c1 = p1[r];
            if (l > 0) c1 -= p1[l-1];
            if (count >= c1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}