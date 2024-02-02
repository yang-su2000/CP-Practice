#include <bits/stdc++.h>
using namespace std;
 
// ./compile sample.cpp
// ./a < input
 
#define ll long long
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rows(n);
    vector<vector<int>> cols(m);
    vector<bool> vis_rows(n);
    vector<bool> vis_cols(m);
    vector<pair<int, int>> v, v2;
    string s;
    for (int i=0; i<n; i++) {
        cin >> s;
        for (int j=0; j<m; j++) {
            if (s[j] == '#') {
                if (i == 0) {
                    v.push_back({i, j});
                    vis_rows[i] = true;
                } else {
                    rows[i].push_back(j);
                    cols[j].push_back(i);
                }
            }
        }
    }
    if (rows[n-1].empty()) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 1;
    bool flag = false;
    while (!v.empty()) {
        for (auto &[i, j]: v) {
            // cout << ans << ": " << i << " " << j << " " << endl;
            if (i == n-1) {
                cout << ans << endl;
                return 0;
            }
            if (flag && !vis_rows[i]) {
                vis_rows[i] = true;
                for (int j2: rows[i]) {
                    v2.push_back({i, j2});
                }
            } else if (!flag && !vis_cols[j]) {
                vis_cols[j] = true;
                for (int i2: cols[j]) {
                    v2.push_back({i2, j});
                }
            }
        }
        v.clear();
        swap(v, v2);
        flag = !flag;
        ans++;
    }
    cout << -1 << endl;
}