#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    ll a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        ll ans = lcm(a, b);
        if (ans == a) {
            ll di = a / b;
            if (min(b, di) == 1) ans *= max(b, di);
            else ans *= min(b, di);
        }
        cout << ans << endl;;
    }
}