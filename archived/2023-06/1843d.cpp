#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, u, v, q, x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> A(n + 1);
        for (int i=0; i<n-1; i++) {
            cin >> u >> v;
            A[u].push_back(v);
            A[v].push_back(u);
        }
        vector<ll> count(n + 1);
        function<ll(int, int)> dfs = [&](int node, int parent) {
            ll val = 0;
            for (int child: A[node]) {
                if (child == parent) continue;
                val += dfs(child, node);
            }
            if (!val) val = 1;
            count[node] = val;
            return val;
        };
        dfs(1, -1);
        // for (int i=1; i<=n; i++) cout << count[i] << " ";
        // cout << endl;
        cin >> q;
        for (int i=0; i<q; i++) {
            cin >> x >> y;
            cout << count[x] * count[y] << endl;
        }
    }
}