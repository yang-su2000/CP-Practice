#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> b(n);
        for (int i=0; i<n; i++) cin >> b[i];
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i=1; i<=n; i++) {
            int l = i - b[i-1] - 1;
            int r = i + b[i-1];
            if (0 <= l && f[l]) f[i] = true;
            if (f[i-1] && r <= n) f[r] = true;
        }
        if (f[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}