#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> link(n + 1, -1), taken(n + 1, -1);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> link[a[i]];
        for (int i=0; i<n; i++) cin >> taken[a[i]];
        ll mod = 1e9+7;
        ll ans = 1;
        // for (int i=1; i<=n; i++) {
        //     cout << i << " " << link[i] << " " << taken[i] << endl;
        // }
        for (int i=1; i<=n; i++) {
            if (link[i] == i) continue;
            bool valid = true;
            int count = 0;
            int cur = i;
            while (cur != -1) {
                count++;
                if (taken[cur]) valid = false;
                int nxt = link[cur];
                link[cur] = -1;
                cur = nxt;
            }
            if (valid and count >= 2) ans = (ans << 1) % mod;
        }
        cout << ans << endl;
    }
}