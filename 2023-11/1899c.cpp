#include <bits/stdc++.h>
using namespace std;

// ./run sample.cpp

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        int ans = a[0];
        int cur = a[0];
        bool odd;
        if (abs(cur) % 2) odd = true;
        else odd = false;
        for (int i=1; i<n; i++) {
            if ((abs(a[i]) % 2) ^ odd) {
                odd = !odd;
                cur = max(a[i], cur + a[i]);
            } else {
                cur = a[i];
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
}