#include <bits/stdc++.h>
using namespace std;
 
// ./compile sample.cpp
// ./a < input
 
#define ll long long
 
int main() {
    int t, n, tmp;
    ll mod = 998244353;
    cin >> t;
    while (t--) {
        cin >> n;
        int max = 0;
        int max_count = 0;
        int max2_count = 0;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            if (tmp < max - 1);
            else if (tmp == max - 1) max2_count++;
            else if (tmp == max) max_count++;
            else if (tmp == max + 1) {
                max2_count = max_count;
                max_count = 1;
                max++;
            } else if (tmp > max + 1) {
                max2_count = 0;
                max_count = 1;
                max = tmp;
            }
        }
        if (max_count == 1 && max2_count == 0) {
            cout << 0 << endl;
        } else if (max_count == 1) {
            int leave_out = max2_count + 1;
            ll ans = 1;
            for (int i=1; i<=n; i++) {
                if (i == leave_out) continue;
                ans = ans * i % mod;
            }
            ans = (ans * leave_out - ans) % mod;
            cout << ans << endl;
        } else {
            ll ans = 1;
            for (int i=1; i<=n; i++) {
                ans = ans * i % mod;
            }
            cout << ans << endl;
        }
    }
}