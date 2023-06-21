#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0; i<n/2; i++) {
            ans += a[n-i-1] - a[i];
        }
        cout << ans << endl;
    }
}