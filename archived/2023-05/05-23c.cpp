#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, tmp;
    cin >> t;
    while (t--) {
        ll l, r, m;
        cin >> l >> r >> m;
        for (ll a=l; a<=r; a++) {
            ll n = (m + r - l) / a;
            if (n > 0 && m - r + l <= n * a && n * a <= m + r - l) {
                ll b_c = m - n * a;
                if (b_c >= 0) {
                    cout << a << " " << b_c + l << " " << l << endl;
                } else {
                    cout << a << " " << l << " " << l - b_c << endl;
                }
                break;
            }
        }
    }
}