#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, a, b;
    ll k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<ll> h(n);
        for (int i=0; i<n; i++) cin >> h[i];
        vector<int> p(n);
        vector<vector<int>> A(n);
        for (int i=0; i<m; i++) {
            cin >> a >> b;
            a--, b--;
            p[b]++;
            A[a].push_back(b);
        }
        ll ans = 0;
        vector<ll> d(n);
        vector<pair<ll, int>> v;
        stack<int> cur;
        for (int i=0; i<n; i++) {
            if (!p[i]) {
                cur.push(i);
                v.push_back(make_pair(h[i], i));
            }
        }
        sort(v.begin(), v.end());
        int n2 = (int) v.size();
        for (int i=1; i<n2; i++) {
            auto [val, idx] = v[i];
            d[idx] = max(d[idx], h[idx] - h[v[i-1].second]);
            d[idx] = max(d[idx], h[v[i-1].second] + k - h[idx]);
            cout << idx << " " << d[idx] << ", ";
        }
        cout << endl;
        while (!cur.empty()) {
            int node = cur.top();
            cur.pop();
            cout << node << " " << d[node] << " ";
            ans = max(ans, d[node]);
            for (int child: A[node]) {
                p[child]--;
                if (!p[child]) {
                    cur.push(child);
                }
                if (h[node] <= h[child]) {
                    d[child] = max(d[child], d[node] + h[child] - h[node]);
                } else {
                    d[child] = max(d[child], d[node] + h[child] + k - h[node]);
                }
            }
        }
        cout << ans << endl;
    }
}