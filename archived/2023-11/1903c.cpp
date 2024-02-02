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
        vector<ll> a(n);
        for (ll &i: a) cin >> i;
        vector<ll> ans;
        ans.push_back(0);
        ll sum = 0;
        ll cur = 0;
        for (int i=n-1; i>=0; i--) {
            sum += a[i];
            cur += a[i];
            if (sum > 0) {
                ans.push_back(cur);
                cur = 0;
            }
        }
        if (sum < 0) ans.push_back(cur);
        reverse(ans.begin(), ans.end());
        ll ret = 0;
        int m = ans.size();
        // for (int i=0; i<m; i++) cout << ans[i] << " \n"[i == m-1];
        for (int i=0; i<m; i++) ret += ans[i] * (i + 1);
        cout << ret << endl;
    }
}