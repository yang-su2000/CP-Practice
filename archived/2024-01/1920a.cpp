#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        int lo = INT_MIN, hi = INT_MAX;
        int a, x;
        for (int i=0; i<n; i++) {
            cin >> a >> x;
            if (a == 1) lo = max(lo, x);
            else if (a == 2) hi = min(hi, x);
            else if (a == 3) v.push_back(x);
        }
        if (hi < lo) {
            cout << 0 << endl;
            continue;
        }
        int ans = hi - lo + 1;
        for (int x: v) {
            if (lo <= x and x <= hi) ans--;
        }
        cout << ans << endl;
    }
}