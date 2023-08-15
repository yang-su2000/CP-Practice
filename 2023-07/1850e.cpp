#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    ll c;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        vector<ll> s(n);
        for (int i=0; i<n; i++) cin >> s[i];
        ll l = 0, r = 1e9;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            ll cur = 0;
            for (int i=0; i<n; i++) {
                cur += (s[i] + mid) * (s[i] + mid);
                // cout << s[i] << ", " << mid << endl;
                if (cur > c) break;
            }
            if (cur < c) l = mid + 1;
            else if (cur == c) {
                l = mid;
                break;
            } else r = mid - 1;
            // cout << l << ", " << mid << ", " << r << ": " << cur << endl;
        }
        cout << l / 2 << endl;
    }
}