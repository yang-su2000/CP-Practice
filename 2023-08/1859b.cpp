#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<ll, int>> min_, min2;
        for (int i=0; i<n; i++) {
            cin >> m;
            vector<ll> a(m);
            for (int j=0; j<m; j++) cin >> a[j];
            sort(a.begin(), a.end());
            min_.push_back(make_pair(a[0], i));
            min2.push_back(make_pair(a[1], i));
        }
        ll ans = 0;
        sort(min_.begin(), min_.end());
        sort(min2.begin(), min2.end());
        // for (int i=0; i<n; i++) cout << min_[i].first << ", " << min_[i].second << "; ";
        // cout << endl;
        // for (int i=0; i<n; i++) cout << min2[i].first << ", " << min2[i].second << "; ";
        // cout << endl;
        ans += min(min2[0].first, min_[0].first);
        for (int i=1; i<n; i++) ans += min2[i].first;
        cout << ans << endl;
    }
}