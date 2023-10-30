#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        ll x = 0;
        int l = 0, r = n-1;
        while (l < r) {
            if (a[l] + x < a[r]) {
                x += a[l];
                ans += a[l];
                l++;
            } else {
                ll diff = a[r] - x;
                x += diff;
                ans += diff;
                a[l] -= diff;
                if (x) ans++;
                x = 0;
                r--;
            }
        }
        // cout << x << " " << a[l] << " " << ans << endl;
        ll y = (a[l] - x) / 2;
        x += y;
        ans += y;
        a[l] -= y;
        if (x) ans++;
        a[l] -= x;
        x = 0;
        if (a[l]) ans++;
        cout << ans << endl;
    }
}