#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k, c;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<vector<int>> dist(k);
        vector<int> idxs(k, -1);
        for (int i=0; i<n; i++) {
            cin >> c;
            c--;
            int d = i - idxs[c] - 1;
            idxs[c] = i;
            dist[c].push_back(d);
        }
        for (int i=0; i<k; i++) {
            int d = n - idxs[i] - 1;
            dist[i].push_back(d);
        }
        // for (int i=0; i<k; i++) {
        //     cout << i << ", " << idxs[i] << ": ";
        //     for (int d: dist[i]) cout << d << ", ";
        //     cout << endl;
        // }
        int ans = INT_MAX;
        for (int i=0; i<k; i++) {
            if (dist[i].empty()) continue;
            sort(dist[i].begin(), dist[i].end());
            int val = *(dist[i].rbegin());
            val = val / 2;
            *(dist[i].rbegin()) = val;
            sort(dist[i].begin(), dist[i].end());
            ans = min(ans, *(dist[i].rbegin()));
        }
        cout << ans << endl;
    }
}