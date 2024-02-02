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
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        int lo = INT_MAX, hi = INT_MIN;
        for (int i=0; i<n; i++) {
            lo = min(lo, a[i]);
            hi = max(hi, a[i]);
        }
        vector<int> ans;
        while (lo != hi) {
            if (lo % 2 and hi % 2 == 0) {
                ans.push_back(1);
                lo = (lo + 1) / 2;
                hi = (hi + 1) / 2;
            } else {
                ans.push_back(0);
                lo /= 2;
                hi /= 2;
            }
        }
        int m = (int) ans.size();
        cout << m << endl;
        if (m > n) continue;
        for (int i=0; i<m; i++) cout << ans[i] << " \n" [i == m-1];
    }
}