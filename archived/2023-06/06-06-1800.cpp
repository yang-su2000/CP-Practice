#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        k--;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        queue<pair<ll, ll>> l, r; // min_req, gain
        ll req = 0;
        ll gain = 0;
        for (int i=k-1; i>=0; i--) {
            gain += v[i];
            req = min(req, gain);
            if (gain >= 0) {
                l.push({req, gain});
                req = 0;
                gain = 0;
            }
        }
        l.push({req, gain});
        req = 0;
        gain = 0;
        for (int i=k+1; i<n; i++) {
            gain += v[i];
            req = min(req, gain);
            if (gain >= 0) {
                r.push({req, gain});
                req = 0;
                gain = 0;
            }
        }
        r.push({req, gain});
        req = 0;
        gain = 0;
        ll val = v[k];
        while (!l.empty() && !r.empty()) {
            if (val + l.front().first >= 0) {
                // cout << "l " << val << ", " << l.front().first << ", " << l.front().second << endl;
                val += l.front().second;
                l.pop();
            } else if (val + r.front().first >= 0) {
                // cout << "r " << val << ", " << r.front().first << ", " << r.front().second << endl;
                val += r.front().second;
                r.pop();
            } else break;
        }
        if (l.empty() || r.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}