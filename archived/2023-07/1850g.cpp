#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    ll a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        map<ll, ll> r, c, q, w;
        ll ans = 0;
        for (int i=0; i<n; i++) {
            cin >> a >> b;
            if (r.count(a)) ans += r[a];
            r[a]++;
            if (c.count(b)) ans += c[b];
            c[b]++;
            if (q.count(a+b)) ans += q[a+b];
            q[a+b]++;
            if (w.count(b-a)) ans += w[b-a];
            w[b-a]++;
        }
        cout << 2 * ans << endl;
    }
}