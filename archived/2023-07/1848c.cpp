#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        ll target = -1;
        bool ans = true;
        for (int i=0; i<n; i++) {
            ll cur = 0;
            int x = a[i];
            int y = b[i];
            if (x == 0 && y == 0) continue;
            while (x && y) {
                int x2, y2;
                if (x <= y) {
                    x2 = y;
                    y2 = y - x;
                } else {
                    int mul = x / y;
                    int mod = x % y;
                    x2 = y;
                    if (mul % 2) y2 = mod;
                    else y2 = y - mod;
                }
                x = x2;
                y = y2;
                cur++;
            }
            if (x) cur++;
            // cout << x << ", " << y << ": " << cur << ", " << target << endl;
            if (target == -1) target = cur;
            else if (abs(target - cur) % 3 == 0) continue;
            else {
                ans = false;
                break;
            }
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}