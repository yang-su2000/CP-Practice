#include <bits/stdc++.h>
using namespace std;

#define ll long long

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, q, tmp;
    ll a, b, n;
    cin >> t;
    while (t--) {
        ll l = 1;
        ll r = LONG_LONG_MAX;
        cin >> q;
        while (q--) {
            cin >> tmp;
            if (tmp == 1) {
                cin >> a >> b >> n;
                ll l2 = (a - b) * (n - 2) + a + 1;
                if (n == 1) l2 = 1;
                ll r2 = (a - b) * (n - 1) + a;
                if (max(l, l2) > min(r, r2)) {
                    cout << 0 << " \n"[q == 0];
                } else {
                    l = max(l, l2);
                    r = min(r, r2);
                    cout << 1 << " \n"[q == 0];
                }
            } else {
                cin >> a >> b;
                if (r <= a) {
                    cout << 1 << " \n"[q == 0];
                    // debug
                    // cout << "[" << l << "," << r << "]" << " \n"[q == 0];
                    continue;
                } else if (l <= a) {
                    cout << -1 << " \n"[q == 0];
                    // debug
                    // cout << "[" << l << "," << r << "]" << " \n"[q == 0];
                    continue;
                }
                ll hl = (l - a) / (a - b) + 1;
                if ((l - a) % (a - b)) hl++;
                if ((a - b) * (hl - 1) + a <= r - 1) {
                    cout << -1 << " \n"[q == 0];
                } else {
                    cout << hl << " \n"[q == 0];
                }
            }
            // debug
            // cout << "[" << l << "," << r << "]" << " \n"[q == 0];
        }
    }
}