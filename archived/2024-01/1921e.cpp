#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, h, w, xa, ya, xb, yb;
    cin >> t;
    while (t--) {
        cin >> h >> w >> xa >> ya >> xb >> yb;
        if (xa > xb) {
            cout << "Draw" << endl;
            continue;
        }
        int row = xb - xa;
        int costb = row / 2;
        int costa = row - costb;
        bool checka = row % 2;
        int loa = max(1, ya - costa), hia = min(w, ya + costa);
        int lob = max(1, yb - costb), hib = min(w, yb + costb);
        if (checka and loa <= lob and hib <= hia) cout << "Alice" << endl;
        else if (!checka and lob <= loa and hia <= hib) cout << "Bob" << endl;
        else cout << "Draw" << endl;
    }
}