#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<ll> b(n);
        for (ll &x: b) cin >> x;
        ll pro = 1;
        for (ll x: b) pro *= x;
        if (pro > 2023 or 2023 % pro) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            ll re = 2023 / pro;
            for (int i=0; i<k-1; i++) cout << "1 ";
            cout << re << endl;
        }
    }
}