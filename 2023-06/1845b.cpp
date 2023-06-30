#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, xa, ya, xb, yb, xc, yc;
    cin >> t;
    while (t--) {
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        int ans = 1;
        int dx1 = xb - xa;
        int dx2 = xc - xa;
        int dy1 = yb - ya;
        int dy2 = yc - ya;
        // cout << dx1 << " " << dx2 << " " << dy1 << " " << dy2 << endl;
        if ((dx1 >= 0 && dx2 >= 0) || (dx1 <= 0 && dx2 <= 0)) {
            ans += min(abs(dx1), abs(dx2));
        }
        if ((dy1 >= 0 && dy2 >= 0) || (dy1 <= 0 && dy2 <= 0)) {
            ans += min(abs(dy1), abs(dy2));
        }
        cout << ans << endl;
    }
}