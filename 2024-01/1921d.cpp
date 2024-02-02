#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<ll> a(n);
        for (ll &x: a) cin >> x;
        vector<ll> b(m);
        for (ll &x: b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll csum = 0;
        for (int i=0; i<n; i++) {
            csum += abs(a[i] - b[m-i-1]);
        }
        ll ans = csum;
        // cout << csum << " ";
        for (int i=n-1, j=0, k=m-n; i>=0; i--, j++, k++) {
            csum -= abs(a[i] - b[k]);
            csum += abs(a[i] - b[j]);
            ans = max(ans, csum);
            // cout << csum << " ";
        }
        cout << ans << endl;
    }
}