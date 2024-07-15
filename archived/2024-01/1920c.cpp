#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    // int limit = 2e5;
    // vector<set<int>> d(limit+1);
    // for (int x=1; x<=limit; x++) {
    //     for (int y=1; y*y<=x; y++) {
    //         if (x % y == 0) {
    //             d[x].insert(y);
    //             d[x].insert(x / y);
    //         }
    //     }
    //     d[x].insert(x);
    // }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        int minval = INT_MIN;
        for (int i: a) minval = max(minval, i);
        int ans = 0;
        function<bool(int, int)> solve = [&](int k, int m) {
            bool valid = true;
            for (int j=0; j<k; j++) {
                int target = a[j];
                if (m != -1) target %= m;
                for (int jj=j; jj<n; jj+=k) {
                    int cur = a[jj];
                    if (m != -1) cur %= m;
                    if (cur != target) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }
            return valid;
        };
        for (int k=1; k<=n; k++) {
            if (n % k) continue;
            bool valid = false;
            if (solve(k, -1)) {
                ans++;
                continue;
            }
            for (int m=minval; m>=2; m--) {
                if (solve(k, m)) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}