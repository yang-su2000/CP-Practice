#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &i: a) cin >> i;
        bool same = true;
        for (int i=1; i<n; i++) {
            if (a[i] != a[i-1]) {
                same = false;
                break;
            }
        }
        if (same) {
            cout << -1 << endl;
            continue;
        }
        vector<pair<int, int>> v;
        v.push_back(make_pair(0, 0));
        for (int i=1; i<n; i++) {
            if (a[i] != a[0]) continue;
            if (i == v.back().second + 1) v.back().second++;
            else v.push_back(make_pair(i, i));
        }
        int ans = INT_MAX;
        for (auto [l, r]: v) ans = min(ans, r - l + 1);
        cout << ans << endl;
    }
}