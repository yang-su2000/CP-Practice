#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        vector<int> dp(n);
        vector<pair<int, int>> d(n+1, {-1, -1}); // last idx, # remove
        d[a[0]] = {0, 0};
        for (int i=1; i<n; i++) {
            int val = a[i];
            int not_used = dp[i-1];
            if (d[val].first != -1) {
                not_used = max(not_used, d[val].second + i - d[val].first);
            }
            int used = not_used;
            if (d[val].first != -1) {
                used = max(used, d[val].second + i - d[val].first + 1);
            }
            d[val] = {i, not_used};
            dp[i] = used;
            // cout << i << " " << not_used << " " << used << " " << dp[i] << endl;
        }
        cout << dp[n-1] << endl;
    }
}