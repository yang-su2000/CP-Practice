#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k, x;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        if (x != 1) {
            cout << "Yes" << endl;
            cout << n << endl;
            for (int i=0; i<n; i++) cout << 1 << " \n"[i == n-1];
            continue;
        }
        if ((n % 2 && k == 2) || (k == 1)) {
            cout << "No" << endl;
            continue;
        }
        if (k == 2) {
            cout << "Yes" << endl;
            cout << n/2 << endl;
            for (int i=0; i<n/2; i++) cout << 2 << " \n"[i == n/2-1];
            continue;
        }
        cout << "Yes" << endl;
        if (n % 2) {
            cout << (n-3)/2 + 1 << endl;
            cout << 3;
            if (n-3) cout << " ";
            else cout << endl;
            for (int i=0; i<(n-3)/2; i++) cout << 2 << " \n"[i == (n-3)/2-1];
        } else {
            cout << n/2 << endl;
            for (int i=0; i<n/2; i++) cout << 2 << " \n"[i == n/2-1];
        }
    }
}