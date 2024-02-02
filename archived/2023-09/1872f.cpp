#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), c(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i=0; i<n; i++) cin >> c[i];
        vector<int> childs(n);
        for (int i=0; i<n; i++) {
            childs[a[i]]++;
        }
        vector<bool> vis(n);
        vector<int> ans;
        stack<int> cur;
        for (int i=0; i<n; i++) {
            if (childs[i] == 0) cur.push(i);
        }
        while (!cur.empty()) {
            int node = cur.top();
            cur.pop();
            ans.push_back(node);
            vis[node] = true;
            int parent = a[node];
            if (--childs[parent] == 0) cur.push(parent);
        }
        for (int i=0; i<n; i++) {
            if (vis[i]) continue;
            int node = i;
            int min_node = -1;
            int min_val = INT_MAX;
            while (childs[node] > 0) {
                childs[node]--;
                node = a[node];
                if (c[node] < min_val) {
                    min_node = node;
                    min_val = c[node];
                }
            }
            int cur_node = a[min_node];
            while (!vis[cur_node]) {
                ans.push_back(cur_node);
                vis[cur_node] = true;
                cur_node = a[cur_node];
            }
        }

        assert((int) ans.size() == n);
        for (int i=0; i<n; i++) {
            cout << ans[i] + 1 << " \n"[i == n-1];
        }
    }
}