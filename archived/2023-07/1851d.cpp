#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n - 1);
        vector<bool> p(n + 1);
        vector<ll> v;
        ll cand = -1;
        bool ans = true;
        for (int i=0; i<n-1; i++) cin >> a[i];
        for (int i=0; i<n-1; i++) {
            ll val = a[i];
            if (i > 0) val -= a[i-1];
            if (val > n || p[val]) {
                if (cand != -1) {
                    ans = false;
                    break;
                } else {
                    cand = val;
                }
            } else {
                p[val] = true;
            }
        }
        if (!ans) {
            cout << "No" << endl;
            continue;
        }
        for (int i=1; i<=n; i++) {
            if (!p[i]) v.push_back(i);
        }
        if (cand == -1) {
            cout << "Yes" << endl;
        } else {
            ll sum = 0;
            for (int i=0; i<(int)v.size(); i++) sum += v[i];
            if (sum == cand) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}