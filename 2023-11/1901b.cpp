#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> c(n);
        for (int i=0; i<n; i++) cin >> c[i];
        ll ans = c[0] - 1;
        for (int i=1; i<n; i++) {
            if (c[i] > c[i-1]) ans += c[i] - c[i-1];
        }
        cout << ans << endl;
    }
}