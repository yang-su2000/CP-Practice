#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t;
    ll n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ll ans = 0;
        ll cur = 1;
        while (cur < n) {
            if (cur > k) {
                ans += (n - cur + k - 1) / k;
                break;
            } else cur *= 2;
            ans++;
        }
        cout << ans << endl;
    }
}