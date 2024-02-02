#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k < n-1) {
            int k2 = n-1-k;
            for (int i=0; i<n/2; i++) {
                if (i != 0 && i != k && i != k2) {
                    cout << i << " " << n-1-i << endl;
                }
            }
            cout << 0 << " " << k2 << endl;
            if (k) cout << n-1 << " " << k << endl;
            // cout << endl;
        } else {
            if (n == 4) {
                cout << -1 << endl;
                continue;
            }
            for (int i=0; i<n/2; i++) {
                if (i != 0 && i != 1 && i != n/2-2 && i != n/2-1) {
                    cout << i << " " << n-1-i << endl;
                }
            }
            cout << 0 << " " << 1 << endl;
            cout << n-1 << " " << k-1 << endl;
            cout << n/2-2 << " " << n/2 << endl;
            cout << n/2-1 << " " << n/2+1 << endl;
            // cout << endl;
        }
    }
}