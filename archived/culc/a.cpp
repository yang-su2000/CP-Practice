#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += a[i];
    }
    for (int i=n-1; i>=0 && k>0; i--, k--) {
        ans += a[i];
    }
    cout << ans << endl;
}