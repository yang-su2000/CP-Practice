#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

// TO FIX

#define ll long long

int main() {
    ll t, k;
    int A, B, C;
    cin >> t;
    while (t--) {
        cin >> A >> B >> C >> k;
        ll a1 = 1;
        for (int i=0; i<A-1; i++) a1 *= 10;
        ll a2 = a1 * 10 - 1;
        ll b1 = 1;
        for (int i=0; i<B-1; i++) b1 *= 10;
        ll b2 = b1 * 10 - 1;
        ll c1 = 1;
        for (int i=0; i<C-1; i++) c1 *= 10;
        ll c2 = c1 * 10 - 1;
        bool flag = false;
        ll a, l, r;
        for (a=a1; a<=a2; a++) {
            l = max(c1 - a, b1);
            r = min(c2 - a, b2);
            if (l <= r) {
                if (k - (r - l + 1) > 0) {
                    k -= (r - l + 1);
                } else {
                    flag = true;
                    break;
                }
            }
        }
        l = max(c1 - a, b1);
        r = min(c2 - a, b2);
        if (flag) cout << a << " + " << l + k - 1 << " = " << a + l + k - 1 << endl;
        else cout << -1 << endl;
    }
}