#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

// TO FIX

#define ll long long

int main() {
    int n;
    ll mod = 998244353;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> dp0(n, vector<ll>(32)), dp1(n, vector<ll>(32));
    vector<ll> count0(32), count1(32), p0(32, -1), p1(32, -1), m0(32), m1(32);
    for (int b=0; b<32; b++) {
        if (a[0] & (1 << b)) {
            dp1[0][b] = 1;
            count1[b] = 1;
            p1[b] = 0;
        } else {
            dp0[0][b] = 1;
            count0[b] = 1;
            p0[b] = 0;
        }
    }
    for (int i=1; i<n; i++) {
        for (int b=0; b<32; b++) {
            if (a[i] & (1 << b)) {
                ll diff = i - p0[b];
                ll add = (count0[b] * diff) % mod;
                ll base = 0;
                if (p0[b] != -1) base = dp0[p0[b]][b];
                dp1[i][b] = (base + add) % mod;
            } else {
                
            }
        }
    }
    ll ans = 0;
    for (int b=0; b<32; b++) {
        ans = (ans + (((m0[b] + m1[b]) % mod) << b)) % mod;
    }
    cout << ans << endl;
}