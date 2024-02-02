#include <bits/stdc++.h>
using namespace std;

// g++ sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, x, k;
    cin >> t;
    while (t--) {
        cin >> x >> k;
        if (x < k || x % k) {
            cout << 1 << endl << x << endl;
        } else {
            int r = k + 1;
            cout << 2 << endl << x - r << ' ' << r << endl;
        }
    }
}