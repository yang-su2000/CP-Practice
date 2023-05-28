#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int u, v;
        vector<bool> vis(n);
        vector<vector<pair<int, int>>> A(n);
        for (int i=0; i<n-1; i++) {
            cin >> u >> v;
            u--, v--;
            A[u].push_back({v, i});
            A[v].push_back({u, i});
        }
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq, pq2; // idx, node
        vis[0] = true;
        for (auto &p: A[0]) {
            pq.push({p.second, p.first});
        }
        while (!pq.empty()) {
            int idx = 0;
            ans++;
            while (!pq.empty()) {
                auto p = pq.top();
                // cout << ans << " " << p.first << " " << p.second << endl;
                idx = p.first;
                pq.pop();
                int node = p.second;
                vis[node] = true;
                for (auto &p2: A[node]) {
                    int child = p2.first;
                    if (!vis[child]) {
                        if (p2.second < idx) pq2.push({p2.second, child});
                        else pq.push({p2.second, child});
                    }
                }
            }
            // cout << endl;
            swap(pq, pq2);
        }
        cout << ans << endl;
    }
}