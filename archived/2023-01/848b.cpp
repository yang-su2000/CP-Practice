#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp -o run
// ./run < input.txt

int main() {
    int t, n, m, d, tmp;
    vector<int> p, a;
    cin >> t;
    while (t--) {
        cin >> n >> m >> d;
        p.resize(n);
        a.resize(m);
        for (int i=0; i<n; i++) cin >> p[i];
        for (int i=0; i<m; i++) cin >> a[i];
        int ans = INT_MAX;
        vector<int> idxs(n);
        for (int i=0; i<n; i++) {
            idxs[p[i]-1] = i;
        }
        for (int i=1; i<m; i++) {
            int a1 = idxs[a[i-1]-1];
            int a2 = idxs[a[i]-1];
            if (a1 > a2 or a1 + d < a2) {
                ans = 0;
                break;
            }
            if (a1 + n - 1 - a2 + a2 - a1 > d) {
                ans = min(ans, d + 1 - (a2 - a1));
                // cout << ans << " ";
            }
            ans = min(ans, a2 - a1);
            // cout << ans << "/";
        }
        cout << ans << endl;
    }
}