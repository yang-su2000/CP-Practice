#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    ll a, b, r;
    cin >> t;
    while (t--) {
        cin >> a >> b >> r;
        if (a < b) swap(a, b);
        ll x = 0;
        bool flag = true;
        for (int bit=63; bit>=0; bit--) {
            if ((a & (1ll << bit)) and ((b & (1ll << bit)) == 0)) {
                if (flag) {
                    flag = false;
                    continue;
                }
                ll x2 = x;
                x2 |= (1ll << bit);
                if (x2 <= r) {
                    x = x2;
                }
            }
        }
        cout << abs((a ^ x) - (b ^ x)) << endl;
    }
}