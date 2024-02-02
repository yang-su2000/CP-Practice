#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, m, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll a = 0;
        ll b = 0;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            a += tmp;
        }
        for (int i=0; i<m; i++) {
            cin >> tmp;
            b += tmp;
        }
        if (a > b) {
            cout << "Tsondu" << endl;
        } else if (a == b) {
            cout << "Draw" << endl;
        } else {
            cout << "Tenzing" << endl;
        }
    }
}