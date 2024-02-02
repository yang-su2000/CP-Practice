#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

// TO FIX

#define ll long long

int main() {
    int T, t, v, x;
    cin >> T;
    while (T--) {
        int q;
        cin >> q;
        int n = 1;
        vector<vector<int>> A(n);
        vector<int> created(n);
        vector<vector<pair<int, ll>>> ops(n); // time, val
        for (int i=1; i<=q; i++) {
            cin >> t;
            if (t == 1) {
                cin >> v;
                v--;
                A[v].push_back(n);
                A.push_back({});
                created.push_back(i);
                ops.push_back({});
                n++;
            } else {
                cin >> v >> x;
                v--;
                ops[v].push_back(make_pair(i, x));
            }
        }
        vector<ll> ans(n);
        function<void(int, set<pair<int, ll>>&, ll)> dfs = [&](int node, set<pair<int, ll>>& cur, ll sum) {
            ans[node] = sum;
            for (int child: A[node]) {
                int ctime = created[child];
                while (!cur.empty() && cur.begin()->first < ctime) {
                    sum -= cur.begin()->second;
                    cur.erase(cur.begin());
                }
                int sum2 = sum;
                int cops = (int) ops[child].size();
                for (int i=0; i<cops; i++) {
                    cur.insert(ops[child][i]);
                    sum2 += ops[child][i].second;
                }
                dfs(child, cur, sum2);
                for (int i=0; i<cops; i++) cur.erase(ops[child][i]);
            }
        };
        set<pair<int, ll>> cur;
        ll sum = 0;
        int cops = (int) ops[0].size();
        for (int i=0; i<cops; i++) {
            cur.insert(ops[0][i]);
            sum += ops[0][i].second;
        }
        dfs(0, cur, sum);
        for (int i=0; i<n; i++) cout << ans[i] << " \n"[i == n-1];
    }
}