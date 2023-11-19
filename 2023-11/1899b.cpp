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
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        ll ans = 0;
        for (int k=1; k<=n; k++) {
            if (n % k) continue;
            vector<ll> v;
            for (int j=0; j<n/k; j++) {
                ll cur = 0;
                for (int x=j*k; x<j*k+k; x++) {
                    cur += a[x];
                }
                v.push_back(cur);
            }
            sort(v.begin(), v.end());
            ans = max(ans, v.back() - v.front());
        }
        cout << ans << endl;
    }
}