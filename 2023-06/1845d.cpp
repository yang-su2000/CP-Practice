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
        ll k;
        ll dmax = 0;
        ll csum = 0;
        ll cmax = 0;
        for (int i=0; i<n; i++) {
            cin >> val;
            csum += val;
            cmax = max(cmax, csum);
            ll d = cmax - csum;
            if (d > dmax) {
                dmax = d;
                k = cmax;
            }
        }
        cout << k << endl;
    }
}