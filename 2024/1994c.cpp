#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    ll n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = n * (n + 1) / 2;
        ll sum = 0;
        vector<ll> count(n);
        int r = (int) n - 1;
        for (int l = n - 1; l >= 0; l--) {
            sum += a[l];
            while (sum - a[r] > x) {
                sum -= a[r];
                r--;
            }
            if (sum > x) {
                count[l] = 1;
                if (r + 1 < n) {
                    count[l] += count[r + 1];
                }
            }
            ans -= count[l];
        }
        cout << ans << endl;
    }
}