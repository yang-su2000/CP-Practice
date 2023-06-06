#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, k, q, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> k >> q;
        ll ans = 0;
        ll count = 0;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            if (tmp > q) {
                if (count >= k) {
                    count -= k - 1;
                    ans += (count + 1) * count / 2;
                }
                count = 0;
            } else count++;
        }
        if (count >= k) {
            count -= k - 1;
            ans += (count + 1) * count / 2;
        }
        cout << ans << endl;
    }
}