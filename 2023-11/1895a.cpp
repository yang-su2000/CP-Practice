#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, x, y, k;
    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        if (y <= x) cout << x << endl;
        else if (y - k <= x) cout << y << endl;
        else cout << y + y - (x + k) << endl;
    }
}