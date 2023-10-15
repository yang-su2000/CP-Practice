#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    string s;
    cin >> s;
    int n = (int) s.length();
    vector<ll> v(n + 1);
    ll mod = 1e9+7;
    for (int i=1; i<=n; i++) {
        v[i] = (v[i-1] * 2 + 1) % mod;
    }
    ll ans = 0;
    for (int i=n-1, count=0; i>=0; i--, count++) {
        if (s[i] == 'O') {
            ans = (ans + v[count] + 1) % mod;
        }
    }
    cout << ans << endl;
}