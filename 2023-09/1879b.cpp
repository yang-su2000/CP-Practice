#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    ll val;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sa = 0, sb = 0;
        ll ma = INT_MAX, mb = INT_MAX;
        for (int i=0; i<n; i++) {
            cin >> val;
            sa += val;
            ma = min(ma, val);
        }
        for (int i=0; i<n; i++) {
            cin >> val;
            sb += val;
            mb = min(mb, val);
        }
        ll aa = sa + mb * n;
        ll ab = sb + ma * n;
        cout << min(aa, ab) << endl;
    }
}