#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int target = INT_MAX;
        for (int i=0; i<n; i++) target &= a[i];
        if (target) {
            cout << 1 << endl;
            continue;
        }
        // cout << "target: " << target << endl;
        int cur = INT_MAX;
        int ans = 0;
        for (int i=0; i<n; i++) {
            cur &= a[i];
            if (cur == 0) {
                ans++;
                cur = INT_MAX;
            }
        }
        cout << ans << endl;
    }
}