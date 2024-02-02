#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> X(b), Y(a);
    vector<int> Cx1(c), Cx2(c), Cy1(c), Cy2(c);
    for (int i=0; i<a; i++) cin >> Y[i];
    for (int i=0; i<b; i++) cin >> X[i];
    for (int i=0; i<c; i++) cin >> Cx1[i] >> Cy1[i] >> Cx2[i] >> Cy2[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    ll ans = ((ll) a + 1) * (b + 1);
    // cout << ans << endl;
    for (int i=0; i<c; i++) {
        int cx1 = Cx1[i];
        int cx2 = Cx2[i];
        int cy1 = Cy1[i];
        int cy2 = Cy2[i];
        auto lx = lower_bound(X.begin(), X.end(), cx1);
        auto rx = lower_bound(X.begin(), X.end(), cx2);
        // if (lx != X.end()) cout << *lx << endl;
        // else cout << "e" << endl;
        // if (rx != X.end()) cout << *rx << endl;
        // else cout << "e" << endl;
        int dx = (rx - lx);
        auto ly = lower_bound(Y.begin(), Y.end(), cy1);
        auto ry = lower_bound(Y.begin(), Y.end(), cy2);
        // if (ly != Y.end()) cout << *ly << endl;
        // else cout << "e" << endl;
        // if (ry != Y.end()) cout << *ry << endl;
        // else cout << "e" << endl;
        int dy = (ry - ly);
        // cout << i << " " << dx << " " << dy << endl;
        ans += ((ll) dx + 1) * (dy + 1);
        if (dx >= 1 and dy >= 1) ans -= ((ll) dx - 1) * (dy - 1);
    }
    cout << 2 << " " << ans / 2 << " " << ans / 2 + (ans % 2) << endl;
}