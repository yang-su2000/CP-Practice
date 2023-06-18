#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    ll t, n, k, g;
    cin >> t;
    while (t--) {
        cin >> n >> k >> g;
        ll total = k * g;
        total -= (g - 1) / 2 * (n - 1);
        if (total <= 0) total = 0;
        ll r = total % g;
        ll ans;
        if (n == 1) ans = total;
        else if (r >= (g + 1) / 2) ans = total + (g - r);
        else ans = total - r;
        cout << k * g - ans << endl;
    }
}