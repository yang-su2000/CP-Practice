#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<ll> pre(n), suf(n);
    pre[0] = a[0] + n - 1;
    for (int i=1; i<n; i++) pre[i] = max(a[i] + n - i - 1, pre[i-1]);
    suf[n-1] = a[n-1] + n - 1;
    for (int i=n-2; i>=0; i--) suf[i] = max(a[i] + i, suf[i+1]);
    ll ans = LLONG_MAX;
    for (int i=0; i<n; i++) {
        ll cur = a[i];
        if (i > 0) cur = max(cur, pre[i-1]);
        if (i < n - 1) cur = max(cur, suf[i+1]);
        ans = min(ans, cur);
    }
    cout << ans << endl;
}