#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m;
    int a, b, d;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<map<int, int>> A(n);
        bool ans = true;
        for (int i=0; i<m; i++) {
            cin >> a >> b >> d;
            a--, b--;
            if (A[a].count(b) && A[a][b] != d) ans = false;
            A[a][b] = d;
            if (A[b].count(a) && A[b][a] != -d) ans = false;
            A[b][a] = -d;
        }
        if (!ans) {
            cout << "No" << endl;
            continue;
        }
        vector<bool> v(n);
        vector<ll> p(n);
        function<void(int)> dfs = [&](int cur) {
            for (auto &[child, d]: A[cur]) {
                ll pos = p[cur] + d;
                if (!v[child]) {
                    v[child] = true;
                    p[child] = pos;
                    dfs(child);
                    if (!ans) break;
                } else if (p[child] == pos);
                else {
                    ans = false;
                    break;
                }
            }
        };
        for (int i=0; i<n; i++) {
            if (!v[i]) {
                p[i] = 0;
                dfs(i);
                if (!ans) break;
            }
        }
        // for (int i=0; i<n; i++) cout << p[i] << ", ";
        // cout << endl;
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}