#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        ll ans = 0;
        ll lo = a[n-1];
        for (int i=n-2; i>=0; i--) {
            if (a[i] <= lo) {
                lo = a[i];
                continue;
            }
            ll times = a[i] / lo;
            if (a[i] % lo) times++;
            ans += times - 1;
            lo = a[i] / times;
        }
        cout << ans << endl;
    }
}