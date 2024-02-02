#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    vector<tuple<int, int, int>> order {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    while (t--) {
        cin >> n;
        vector<vector<int>> v(3, vector<int>(n));
        for (int &x: v[0]) cin >> x;
        for (int &x: v[1]) cin >> x;
        for (int &x: v[2]) cin >> x;
        int ans = 0;
        for (auto [i1, i2, i3]: order) {
            int idx1 = -1;
            for (int i=0; i<n; i++) {
                if (idx1 == -1 or v[i1][i] > v[i1][idx1]) idx1 = i;
            }
            int idx2 = -1;
            for (int i=0; i<n; i++) {
                if (i != idx1 and (idx2 == -1 or v[i2][i] > v[i2][idx2])) idx2 = i;
            }
            int idx3 = -1;
            for (int i=0; i<n; i++) {
                if (i != idx1 and i != idx2 and (idx3 == -1 or v[i3][i] > v[i3][idx3])) idx3 = i;
            }
            ans = max(ans, v[i1][idx1] + v[i2][idx2] + v[i3][idx3]);
        }
        cout << ans << endl;
    }
}