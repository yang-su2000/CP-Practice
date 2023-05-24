#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    ll mod = 998244353;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        ll ans = 1;
        ll cur = 1;
        for (int i=1; i<n; i++) {
            if (s[i] == s[i-1]) cur <<= 1;
            else cur = 1;
            cur %= mod;
            (ans += cur) %= mod;
        }
        cout << ans << endl;
    }
}