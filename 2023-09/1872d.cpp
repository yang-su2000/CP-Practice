#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    ll t, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        ll d1 = n / x;
        ll d2 = n / y;
        ll d = n / (x * y / gcd(x, y));
        d1 -= d;
        d2 -= d;
        ll v1 = (n - (d1 - 1) + n) * d1 / 2;
        ll v2 = (1 + d2) * d2 / 2;
        cout << v1 - v2 << endl;
    }
}