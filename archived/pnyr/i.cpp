#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v) cin >> x;
    sort(v.begin(), v.end());
    ll hi = v.back();
    ll lo = 0;
    for (int i=0; i<n-1; i++) lo += v[i];
    ll ans;
    if (lo >= hi) ans = (lo + hi) / 2;
    else ans = lo;
    cout << ans << endl;
}