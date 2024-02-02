#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<ll> v;
        for (int i=0; i<n; i++) {
            if (s[i] == '*') v.push_back(i);
        }
        int m = (int) v.size();
        int target = m / 2;
        ll ans = 0;
        for (int i=0; i<m; i++) {
            ans += abs(v[target] - v[i]);
        }
        ll l = target;
        ll r = m - l - 1;
        ans -= (1 + l) * l / 2; // 1 + 2 + ... + l
        ans -= (1 + r) * r / 2; // 1 + ... r
        cout << ans << endl;
    }
}