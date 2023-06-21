#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, u, v, x;
    char c;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> w(1);
        w[0] = 1;
        vector<vector<int>> A(1);
        vector<pair<int, int>> query;
        int count = 1;
        for (int i=0; i<n; i++) {
            cin >> c;
            if (c == '+') {
                cin >> v >> x;
                v--;
                w.push_back(x);
                A.push_back({});
                A[v].push_back(count++);
            } else {
                cin >> u >> v >> x;
                v--;
                query.push_back({v, x});
            }
        }
        // for (int i: w) cout << i << " ";
        // cout << endl;
        // for (int i=0; i<count; i++) {
        //     cout << i << ": ";
        //     for (int node: A[i]) cout << node << " ";
        //     cout << endl;
        // }
        vector<pair<int, int>> cur(count), ans(count, {INT_MAX, INT_MIN});
        function<void(int, int)> dfs = [&](int node, int parent) {
            if (parent != -1) {
                cur[node] = cur[parent];
                ans[node] = ans[parent];
            }
            cur[node].first = min(w[node], cur[node].first + w[node]);
            cur[node].second = max(w[node], cur[node].second + w[node]);
            ans[node].first = min(ans[node].first, cur[node].first);
            ans[node].second = max(ans[node].second, cur[node].second);
            for (int child: A[node]) {
                dfs(child, node);
            }
        };
        dfs(0, -1);
        // for (int i=0; i<count; i++) {
        //     cout << i << ": " << cur[i].first << ", " << cur[i].second << "; " << ans[i].first << ", " << ans[i].second << endl;
        // }
        for (auto &[v, x]: query) {
            if (x == 0 || (ans[v].first <= x && x <= ans[v].second)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}