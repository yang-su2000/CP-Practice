#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    ll t, k, x, a;
    cin >> t;
    while (t--) {
        cin >> k >> x >> a;
        ll origin = a;
        bool valid = true;
        while (x--) {
            ll l = 1, r = a;
            while (l < r) {
                ll mid = l + (r - l) / 2;
                if (a + mid * (k - 1) > origin) r = mid;
                else l = mid + 1;
            }
            if (l <= a and a + l * (k - 1) > origin) a -= l;
            else {
                valid = false;
                break;
            }
        }
        // cout << valid << " " << k << " " << a << endl;
        if (valid and a * k > origin) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}