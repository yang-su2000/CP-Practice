#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, q, l, r;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &x: a) cin >> x;
        vector<int> rs;
        for (int i=1; i<n; i++) {
            if (a[i] != a[i-1]) rs.push_back(i);
        }
        // for (int i: rs) cout << i << " ";
        // cout << endl;
        cin >> q;
        while (q--) {
            cin >> l >> r;
            l--, r--;
            auto p = upper_bound(rs.begin(), rs.end(), r);
            if (p == rs.begin()) {
                cout << "-1 -1" << endl;
                continue;
            }
            int idx = *prev(p);
            if (idx <= l) {
                cout << "-1 -1" << endl;
                continue;
            }
            cout << idx << " " << idx + 1 << endl;
        }
        cout << endl;
    }
}