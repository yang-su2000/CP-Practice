#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        int ans = a[0];
        for (int i=0; i<n-1; i++) ans = max(ans, a[i+1] - a[i]);
        ans = max(ans, (x - a[n-1]) * 2);
        cout << ans << endl;
    }
}