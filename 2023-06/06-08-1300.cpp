#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        vector<int> d(n);
        vector<pair<int, int>> e(m);
        int e1, e2;
        for (int i=0; i<m; i++) {
            cin >> e1 >> e2;
            e1--, e2--;
            d[e1]++;
            d[e2]++;
            e[i] = {e1, e2};
        }
        if (m % 2 == 0) {
            cout << 0 << endl;
            continue;
        }
        int ans = INT_MAX;
        for (int i=0; i<n; i++) {
            if (d[i] % 2) ans = min(ans, a[i]);
        }
        for (int i=0; i<m; i++) {
            auto [e1, e2] = e[i];
            if (d[e1] % 2 == 0 && d[e2] % 2 == 0) ans = min(ans, a[e1] + a[e2]);
        }
        cout << ans << endl;
    }
}