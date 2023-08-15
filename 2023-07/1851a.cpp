#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, m, k, H;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> H;
        vector<int> h(n);
        for (int i=0; i<n; i++) {
            cin >> h[i];
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            bool valid = false;
            for (int j=1; j<m; j++) {
                if (abs(H - h[i]) == j * k) {
                    valid = true;
                    // cout << h[i] << ", ";
                    break;
                }
            }
            if (valid) ans++;
        }
        // cout << endl;
        cout << ans << endl;
    }
}