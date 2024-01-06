#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k, d;
    cin >> t;
    while (t--) {
        cin >> n >> k >> d;
        vector<int> a(n), v(k);
        for (int &x: a) cin >> x;
        for (int &x: v) cin >> x;
        vector<int> cur(n);
        int count = 0;
        for (int i=0; i<n; i++) {
            cur[i] = i + 1 - a[i];
            if (cur[i] == 0) count++;
        }
        int ans = count + (d - 1) / 2;
        for (int i=0; i<2*n; i++) {
            int idx = v[i % k];
            for (int j=0; j<idx; j++) {
                if (cur[j] == 0) count--;
                cur[j]--;
                if (cur[j] == 0) count++;
            }
            if (d - 1 >= i + 1) {
                ans = max(ans, count + (d - 1 - i - 1) / 2);
            }
        }
        cout << ans << endl;
    }
}