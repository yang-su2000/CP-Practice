#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());
        bool valid = true;
        for (int i=0; i<n; i++) {
            if (a[i] == b[i]) continue;
            if (i - x < 0 and i + x >= n) {
                valid = false;
                break;
            }
        }
        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}