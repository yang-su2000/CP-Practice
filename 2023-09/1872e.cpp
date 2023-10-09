#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, q, tp;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        cin >> s;
        vector<int> x(n + 1);
        int x0 = 0, x1 = 0;
        for (int i=1; i<=n; i++) {
            char c = s[i-1];
            x[i] = x[i-1] ^ a[i-1];
            if (c == '0') {
                x0 ^= a[i-1];
            } else {
                x1 ^= a[i-1];
            }
        }
        cin >> q;
        for (int i=0; i<q; i++) {
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                x0 ^= x[l-1] ^ x[r];
                x1 ^= x[l-1] ^ x[r];
            } else {
                int g;
                cin >> g;
                if (g == 0) cout << x0 << " \n"[i == q-1];
                else cout << x1 << " \n"[i == q-1];
            }
        }
    }
}