#include <bits/stdc++.h>
using namespace std;

// ./compile sample.cpp
// ./a < input

#define ll long long

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> v(n), v2(n);
        vector<bool> b(n);
        for (int i=0; i<n; i++) {
            v[i] = (i + k) / k;
            // cout << v[i] << ' ';
            if (i==0 or v[i]>v[i-1]) b[i] = true;
        }
        // cout << endl;
        int count = 0;
        for (int i=0; i<n; i++) {
            if (b[n-i-1]) count++;
            v2[n-i-1] = (i + k) / k;
            if (i==0 or v2[n-i-1]>v2[n-i]) count--;
            if (count<0) {
                b[n-i-1] = true;
                count++;
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            // cout << b[i] << ' ';
            if (b[i]) ans++;
        }
        // cout << endl;
        cout << ans << endl;
    }
}