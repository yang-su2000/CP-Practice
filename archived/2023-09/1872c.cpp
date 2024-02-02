#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, l, r;
    cin >> t;
    ll limit = 1e7;
    vector<bool> f(limit + 1, true);
    for (ll i=2; i<=limit; i++) {
        if (!f[i]) continue;
        for (ll j=i*i; j<=limit; j+=i) {
            f[j] = false;
        }
    }
    vector<int> psum(limit + 1);
    for (ll i=2; i<=limit; i++) {
        psum[i] = psum[i-1] + (!f[i]);
    }
    while (t--) {
        cin >> l >> r;
        // cout << psum[l-1] << " " << psum[r] << "; ";
        if (psum[r] - psum[l-1] > 0) {
            int target = -1;
            for (int i=l; i<=r; i++) {
                if (!f[i]) {
                    target = i;
                    break;
                }
            }
            int div = -1;
            for (int j=2; j*j<=target; j++) {
                if (target % j == 0) {
                    div = j;
                    break;
                }
            }
            // cout << target << " " << div << "; ";
            int a = target - target / div;
            int b = target - a;
            cout << a << " " << b << endl;
        } else {
            cout << -1 << endl;
        }
    }
}