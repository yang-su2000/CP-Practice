#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        a[0]++;
        ll ans = 1;
        for (int i=0; i<n; i++) ans *= a[i];
        cout << ans << endl;
    }
}