#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, k, val;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int count = 0;
        vector<int> a(n), b(m);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];
        map<int, int> bp;
        for (int i=0; i<m; i++) {
            bp[b[i]]++;
        }
        for (int i=0; i<m; i++) {
            int val = a[i];
            if (!bp.count(val)) continue;
            if (bp[val]-- > 0) count++;
        }
        int ans = (count >= k);
        for (int i=m; i<n; i++) {
            int new_val = a[i];
            int old_val = a[i-m];
            if (bp.count(old_val)) {
                if (++bp[old_val] > 0) count--;
            }
            if (bp.count(new_val)) {
                if (bp[new_val]-- > 0) count++;
            }
            ans += (count >= k);
        }
        cout << ans << endl;
    }
}