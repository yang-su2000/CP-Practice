#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

#define ll long long

int main() {
    int t;
    ll k;
    cin >> t;
    // vector<ll> v(13);
    // for (ll last=0, base=1, i=0; i<13; i++) {
    //     ll cur = last * 9 + base;
    //     last = cur;
    //     base *= 10;
    //     v[i] = cur;
    //     cout << cur << " ";
    // }
    // cout << endl;
    while (t--) {
        cin >> k;
        bool done = false;
        ll ans = 0;
        ll cur = k;
        while (!done) {
            ll ans2 = 0;
            
            cout << ans2 << " ";
            if (ans == ans2) {
                done = true;
                break;
            } else {
                cur = k + ans2;
                ans = ans2;
            }
        }
        cout << k + ans << endl;
    }
}