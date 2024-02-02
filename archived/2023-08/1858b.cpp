#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, d;
    cin >> t;
    while (t--) {
        cin >> n >> m >> d;
        vector<int> s(m + 2);
        s[0] = 1;
        for (int i=0; i<m; i++) cin >> s[i+1];
        s[m + 1] = n + 1;
        int total = 0;
        for (int i=1; i<=m+1; i++) {
            int y = s[i];
            int x = s[i-1];
            total += (y - x - 1) / d + 1;
            if (y == 1) total--;
        }
        // cout << total << endl;
        int ans = total;
        int nmin = 0;
        for (int i=1; i<=m; i++) {
            int y2 = s[i+1];
            int y = s[i];
            int x = s[i-1];
            int eat = (y - x - 1) / d + (y2 - y - 1) / d + 1;
            int noeat = (y2 - x - 1) / d;
            if (y == 1) noeat++;
            int cur = total - eat + noeat;
            // cout << i << ", " << y2 << ", " << y << ", " << x << ", " << eat << ", " << noeat << "; ";
            if (cur < ans) {
                ans = cur;
                nmin = 1;
            } else if (cur == ans) {
                nmin++;
            }
        }
        cout << ans << " " << nmin << endl;
    }
}