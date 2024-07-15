#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    ll f, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> f >> a >> b;
        vector<ll> m(n);
        for (ll &x: m) cin >> x;
        for (int i=0; i<n; i++) {
            ll diff = m[i];
            if (i > 0) diff -= m[i-1];
            f -= min(a * diff, b);
        }
        if (f > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}