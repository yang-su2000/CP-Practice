#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = a[n-1] - a[0];
        for (int i=1; i<n-1; i++) {
            ans = max(ans, a[i+1] - a[0] + a[i+1] - a[i]);
        }
        for (int i=0; i<n-2; i++) {
            ans = max(ans, a[n-1] - a[i] + a[i+1] - a[i]);
        }
        cout << ans << endl;
    }
}