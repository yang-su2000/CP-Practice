#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t;
    ll n, k, b, s, val;
    cin >> t;
    while (t--) {
        cin >> n >> k >> b >> s;
        if (b <= s / k) {
            vector<ll> a(n);
            a[0] = b * k;
            s -= b * k;
            for (int i=0; i<n; i++) {
                val = min(s, k - 1);
                a[i] += val;
                s -= val;
            }
            if (s > 0) cout << -1 << endl;
            else {
                for (int i=0; i<n; i++) {
                    cout << a[i] << " \n"[i == n-1];
                }
            }
        } else {
            cout << -1 << endl;
        }
    }
}