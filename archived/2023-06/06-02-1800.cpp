#include <bits/stdc++.h>
using namespace std;
 
// ./compile sample.cpp
// ./a < input
 
#define ll long long
 
int main() {
    int t, n;
    int a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<pair<int, int>>> A(n);
        for (int i=1; i<n; i++) {
            cin >> a >> b;
            a--, b--;
            A[a].push_back({b, i});
            A[b].push_back({a, i});
        }
        if (n % 3) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        bool valid = true;

        function<int(int, int)> dfs = [&](int node, int parent) {
            if (!valid) return 0;
            int ret = 0;
            for (auto &[child, edge]: A[node]) {
                if (child == parent) continue;
                int count = dfs(child, node);
                if (count == 2) {
                    ans.push_back(edge);
                } else {
                    ret += 1 + count;
                }
            }
            if (ret > 2) valid = false;
            return ret;
        };
        dfs(0, -1);

        if (!valid) {
            cout << -1 << endl;
        } else {
            int n2 = ans.size();
            cout << n2 << endl;
            for (int i=0; i<n2; i++) {
                cout << ans[i] << " \n"[i == n2-1];
            }
            if (n2 == 0) cout << endl;
        }
    }
}