#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        vector<pair<int, int>> a2, b2; // val, idx
        for (int i=0; i<n; i++) {
            if (a2.empty() or a2.back().first > a[i]) a2.push_back(make_pair(a[i], i));
        }
        for (int i=0; i<n; i++) {
            if (b2.empty() or b2.back().first < b[i]) b2.push_back(make_pair(b[i], i));
        }
        int ans = INT_MAX;
        int ai = 0, bi = 0;
        int an = (int) a2.size(), bn = (int) b2.size();
        while (bi < bn and a2[ai].first > b2[bi].first) bi++;
        if (bi < bn) ans = b2[bi].second;
        while (ai < an and bi < bn) {
            while (bi > 0 and a2[ai].first < b2[bi-1].first) bi--;
            ans = min(ans, a2[ai].second + b2[bi].second);
            ai++;
        }
        cout << ans << endl;
    }
}