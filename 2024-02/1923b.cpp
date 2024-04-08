#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    ll k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<ll> a(n);
        for (ll &i: a) cin >> i;
        vector<int> x(n);
        for (int &i: x) cin >> i;
        vector<ll> v(n + 1);
        for (int i=0; i<n; i++) v[abs(x[i])] += a[i];
        bool ans = true;
        int i = 0;
        ll cur = 0;
        while (i <= n) {
            if (cur < v[i]) {
                ans = false;
                break;
            }
            cur -= v[i];
            cur += k;
            i++;
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}