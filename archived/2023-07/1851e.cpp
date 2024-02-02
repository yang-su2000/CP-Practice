#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k, len, val;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<ll> c(n);
        vector<int> p(k);
        vector<int> count(n);
        for (int i=0; i<n; i++) cin >> c[i];
        for (int i=0; i<k; i++) {
            cin >> p[i];
            p[i]--;
            c[p[i]] = 0;
        }
        // for (int i=0; i<n; i++) cout << c[i] << ", ";
        // cout << endl;
        vector<vector<int>> A(n);
        for (int i=0; i<n; i++) {
            cin >> len;
            count[i] = len;
            for (int j=0; j<len; j++) {
                cin >> val;
                val--;
                A[val].push_back(i);
            }
        }
        // for (int i=0; i<n; i++) {
        //     cout << i << ": ";
        //     for (int child: A[i]) cout << child << ", ";
        //     cout << endl;
        // }
        vector<int> cur;
        vector<bool> vis(n);
        vector<ll> ans(n);
        for (int i=0; i<n; i++) {
            if (count[i] == 0 || c[i] == 0) {
                vis[i] = true;
                cur.push_back(i);
                ans[i] = c[i];
            }
        }
        // for (int i=0; i<n; i++) cout << ans[i] << ", ";
        // cout << endl;
        // for (int i=0; i<n; i++) cout << count[i] << ", ";
        // cout << endl;
        // for (int i=0; i<n; i++) cout << vis[i] << ", ";
        // cout << endl;
        while (!cur.empty()) {
            int node = cur.back();
            cur.pop_back();
            ans[node] = min(ans[node], c[node]);
            for (int child: A[node]) {
                if (!vis[child]) {
                    count[child]--;
                    ans[child] += ans[node];
                    if (count[child] == 0) {
                        vis[child] = true;
                        cur.push_back(child);
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            cout << ans[i] << " \n"[i == n-1];
        }
    }
}