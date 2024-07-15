#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int lo = 4 * n - 4;
        if (k < lo) cout << (k + 1) / 2 << endl;
        else cout << (lo + 1) / 2 + (k - lo) << endl;
    }
}