#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int u, v;
        ll w;
        vector<vector<pair<int, ll>>> A(n);
        for (int i=0; i<m; i++) {
            cin >> u >> v >> w;
            u--, v--;
            A[u].push_back(make_pair(v, w));
            A[v].push_back(make_pair(u, w));
        }
        vector<ll> s(n);
        for (ll &x: s) cin >> x;
        vector<vector<ll>> d(n, vector<ll>(1001, LLONG_MAX));
        d[0][s[0]] = 0;
        queue<tuple<int, ll, ll>> q; // node, dist, min_s
        q.push(make_tuple(0, 0, s[0]));
        while (!q.empty()) {
            auto [node, dist, min_s] = q.front();
            q.pop();
            if (dist > d[node][min_s]) continue;
            for (auto [child, w]: A[node]) {
                ll dist2 = dist + min_s * w;
                ll min_s2 = min(min_s, s[child]);
                if (dist2 < d[child][min_s2]) {
                    d[child][min_s2] = dist2;
                    q.push(make_tuple(child, dist2, min_s2));
                }
            }
        }
        ll ans = LLONG_MAX;
        for (int min_s=0; min_s<=1000; min_s++) {
            ans = min(ans, d[n-1][min_s]);
        }
        cout << ans << endl;
    }
}