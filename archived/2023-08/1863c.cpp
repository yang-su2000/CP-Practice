#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<bool> b(n + 1);
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i];
            b[v[i]] = true;
        }
        for (int i=0; i<=n; i++) {
            if (!b[i]) v.push_back(i);
        }
        k %= (n + 1);
        int idx = n + 1 - k;
        for (int i=idx, j=0; j<n; i++, j++) {
            cout << v[i % (n + 1)] << " \n"[j == n-1];
        }
    }
}