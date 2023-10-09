#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
    }
    map<int, vector<pair<int, int>>> m;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (l[i] <= j+1 && j+1 <= r[i] && l[i] <= k+1 && k+1 <= r[i] \
                 && l[j] <= i+1 && i+1 <= r[j] && l[j] <= k+1 && k+1 <= r[j] \
                 && l[k] <= i+1 && i+1 <= r[k] && l[k] <= j+1 && j+1 <= r[k]) {
                    m[i+1].push_back(make_pair(j+1, k+1));
                }
            }
        }
    }
    // for (auto p: m) {
    //     cout << p.first << ": ";
    //     for (auto [x, y]: p.second) {
    //         cout << "[" << x << ", " << y << "] ";
    //     }
    //     cout << endl;
    // }
    vector<int> dp(n + 2, -1);
    dp[n+1] = 0;
    function<int(int)> dfs = [&](int i) {
        if (dp[i] != -1) return dp[i];
        dp[i] = dp[i+1];
        for (auto [x, y]: m[i]) {
            dp[i] = max(dp[i], 1 + dfs(y + 1));
        }
        return dp[i];
    };
    int ans = 0;
    for (int i=n; i>=1; i--) {
        ans = max(ans, dfs(i));
        // cout << i << ": " << dp[i] << endl;
    }
    cout << ans << endl;
}